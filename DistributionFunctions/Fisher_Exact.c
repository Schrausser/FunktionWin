//---------------------------------------------------------------------------------------------------------| Fisher_Exact by Dietmar Schrausser, (c) SCHRAUSSER 2009
//                                                                                                         | Exakt hypergeometrischer 4-Felder Test nach R.A.Fisher,
//                                                                                                         | Fisher Exact Test. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

long double fn_erg;

long double fakt(double wert, double F);
void _head(void);
void _profil();

main(int argc, char *argv[])
{
	FILE *outStream;
	
	int  jLauf, kLauf, index=1,i=0, sw=0;
	double iLauf,a,b,c,d,z1,z2,s1,s2,n,zlr=0,min, min_ad;
	long double P0,P01,P10,P11,Pi, P_, P_1, P1=0, P_vtl[200], Pmax, F;

	if(argc == 1 || argc >6 || argc < 5) _profil();


	//4-felder schema
	a=atof(argv[1]); b=atof(argv[2]);   z1=a+b;
	c=atof(argv[3]); d=atof(argv[4]);   z2=c+d;
	 
	s1=a+c;		     s2=b+d;			 n=a+b+c+d;

	F=pow(10,30);
	if(n>120)F=pow(10,50);
	if(n>170)F=pow(10,70);
	if(n>220)F=pow(10,90);
	if(n>240)F=pow(10,120);
	//if(n>270)F=pow(10,125);//faktorielle in t=3 teile

	if(n>270){printf ("\n[a][b][c][d] n>270 .0\n"); _profil();}

	_head();

	outStream = fopen( "Fisher_Exact_P.txt", "w" );

	//Theta0 = Hypergeometrische Wahrscheinlichkeit P0 der initialanordnung 
	
	//faktoriell zerlegung zur zahlengrössenminderung; ungemindert max n=114	
	P0=fakt(z1,F);		//printf("P0= %.0f\n",P0);
	P0=P0*fakt(z2,F);	//printf("P0= %.0f\n",P0);
	P0=P0*fakt(s1,F);	//printf("P0= %.0f\n",P0);
	P0=P0*fakt(s2,F);	//printf("P0= %.0f\n",P0);

	P01=fakt(n,F);		//printf("P01= %.0f\n",P01);
	P01=P01*(fakt(a,F));
	P01=P01*(fakt(b,F));
	P01=P01*(fakt(c,F));
	P01=P01*(fakt(d,F));

	P0=P0/(P01*pow(F,2));//nennermultiplikation wegen n faktoriellzerlegugen Nenner=5=nZ+1


	//p exact einseitig 

	min= d; if(c<min)min=c; if(b<min)min=b; if(a<min)min=a;

	//if(!( min==b && b==d && a==c ) )
	if(( min==a && a!=b &&(a+d<=b+c))|| //a-d -, b-c +
	   ( min==d && d!=c)             ||
	   ((min==a && a==b) && (d<c))   ||
	   ((min==c && d==c) && (a<b))   ||
	   ((min==a && a==c) && (b>d))   ||
	   ( min==b && (b+c)>(a+d)   )   ||
	   ( min==c && (a+d)<(b+c)   )  /*||
       ((min==b && b==d) && (a>c))*/    )
	{ 
		for (iLauf=1; iLauf<=min; iLauf++)
		{
			P10=fakt(z1,F);
			P10=P10*fakt(z2,F);
			P10=P10*fakt(s1,F);
			P10=P10*fakt(s2,F);

			P11=fakt(n,F);
			P11=P11*(fakt(a-iLauf ,F));
			P11=P11*(fakt(b+iLauf ,F));
			P11=P11*(fakt(c+iLauf ,F));
			P11=P11*(fakt(d-iLauf ,F));

			P1+=P10/(P11*pow(F,2));
	   }
	}
	/*if(!( min==b && (b+c)>(a+d)))
	if(!( min==c && (a+d)<(b+c))) 
	if(!( min==a && b==d && a==c ) )
	if(( min==b && a!=b    )  	    || 
	   ( min==c && d!=c)			||
	   ((min==a && a==b) && (d>=c))	||
	   ((min==c && d==c) && (a>=b)) ||
	   ((min==a && a==c) && (b<d))	||
	   ( min==a && (a+d)>(b+c)   )  ||
	   ((min==b && b==d) && (a<c))    ) */
	else								//a-d +, b-c -
	{	
	   for (iLauf=1; iLauf<=min; iLauf++)
	   {
			P10=fakt(z1,F);
			P10=P10*fakt(z2,F);
			P10=P10*fakt(s1,F);
			P10=P10*fakt(s2,F);

			P11=fakt(n,F);
			P11=P11*(fakt(a+iLauf ,F));
			P11=P11*(fakt(b-iLauf ,F));
			P11=P11*(fakt(c-iLauf ,F));
			P11=P11*(fakt(d+iLauf ,F));

			P1+=P10/(P11*pow(F,2));
	   }
	}
	
	if((a==b) && (b==c) && (c==d)) 
	{
		P1=0;
		for (iLauf=1; iLauf<=a; iLauf++)
		{
			P10=fakt(z1,F);
			P10=P10*fakt(z2,F);
			P10=P10*fakt(s1,F);
			P10=P10*fakt(s2,F);

			P11=fakt(n,F);
			P11=P11*(fakt(a+iLauf ,F));
			P11=P11*(fakt(b-iLauf ,F));
			P11=P11*(fakt(c-iLauf ,F));
			P11=P11*(fakt(d+iLauf ,F));

			P1+=P10/(P11*pow(F,2));
	   }
	}
	
	P_1=P0+P1;


	//p exact zweiseitig 

	min_ad=d;if(a<d)min_ad=a;
	for (iLauf=min_ad; iLauf>=0; iLauf--)//a-d -, b-c +
	{
		//Theta i =  Hypergeometrische Wahrscheinlichkeit Pi für jede mögliche anordnung mit gleichen randhäufigkeiten
		
		P10=fakt(z1,F);
		P10=P10*fakt(z2,F);
		P10=P10*fakt(s1,F);
		P10=P10*fakt(s2,F);

		P11=fakt(n,F);
		P11=P11*(fakt(a-iLauf ,F));
		P11=P11*(fakt(b+iLauf ,F));
		P11=P11*(fakt(c+iLauf ,F));
		P11=P11*(fakt(d-iLauf ,F));

		Pi=P10/(P11*pow(F,2));

		P_vtl[index]=Pi;index++;
	
		if (Pi <= P0 + 0.000000001 ) { P_+=Pi;zlr++;} //P0 bedingte summierung von Pi zu P_
		i++;          /*korrektur zur fliesskommainkonsistenz*/
		
		if(argc==6)if(strcmp(argv[5],"1") == 0)
		{
			printf("\n %3.0f  %3.0f \xB3 %3.0f\n",a-iLauf,b+iLauf,z1 );
			printf(  " %3.0f  %3.0f \xB3 %3.0f\n",c+iLauf,d-iLauf,z2);
			printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\n");
			printf(  " %3.0f  %3.0f \xB3 %3.0f",s1,s2,n);
			if (Pi > P0 + 0.000000001 || i==1)printf("\t       P%.0f= %.15f,  p[2]= %.15f\n", iLauf,Pi, P_);
			if (Pi <= P0 + 0.000000001 && i>1)printf("\t       P%.0f= %.15f + p[2]= %.15f\n", iLauf,Pi, P_);
		}

		fprintf(outStream,"%.15f\n", Pi);
	}
	
	min_ad=c;if(b<c)min_ad=b;
	for (iLauf=1; iLauf<=min_ad; iLauf++)//a-d +, b-c -
	{
		//Theta i =  Hypergeometrische Wahrscheinlichkeit Pi für jede mögliche anordnung mit gleichen randhäufigkeiten
		
		P10=fakt(z1,F);
		P10=P10*fakt(z2,F);
		P10=P10*fakt(s1,F);
		P10=P10*fakt(s2,F);

		P11=fakt(n,F);
		P11=P11*(fakt(a+iLauf ,F));
		P11=P11*(fakt(b-iLauf ,F));
		P11=P11*(fakt(c-iLauf ,F));
		P11=P11*(fakt(d+iLauf ,F));

		Pi=P10/(P11*pow(F,2));

		P_vtl[index]=Pi;index++;
		
		if (Pi <= P0 + 0.000000001 ) { P_+=Pi;zlr++;} //P0 bedingte summierung von Pi zu P_
		i++;          /*korrektur zur fliesskommainkonsistenz*/
		
		if(argc==6)if(strcmp(argv[5],"1") == 0)
		{
			printf("\n %3.0f  %3.0f \xB3 %3.0f\n",a+iLauf,b-iLauf,z1 );
			printf(  " %3.0f  %3.0f \xB3 %3.0f\n",c-iLauf,d+iLauf,z2);
			printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\n");
			printf(  " %3.0f  %3.0f \xB3 %3.0f",s1,s2,n);
				if (Pi > P0 + 0.000000001 )printf("\t       P%i= %.15f,  p[2]= %.15f\n", i-1,Pi, P_);
			if (Pi <= P0 + 0.000000001 )printf("\t       P%i= %.15f + p[2]= %.15f\n", i-1,Pi, P_);
		}
		fprintf(outStream,"%.15f\n", Pi);
	}

	if(argc==6)if(strcmp(argv[5],"1") == 0)printf("\n");// schalter full output 1

	printf("\n %3.0f  %3.0f \xB3 %3.0f\n",a,b,z1 );
	printf(  " %3.0f  %3.0f \xB3 %3.0f\n",c,d,z2);
	printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\n");
	printf(  " %3.0f  %3.0f \xB3 %3.0f",s1,s2,n); 

	if(argc==6)if(strcmp(argv[5],"1") == 0)// schalter full output 1
	{
		printf("\t       P0= %.15f\n\nP0+P1+P2...+Pn=p.exact[1]= %.12f\nP0+sum(Pi<=P0)=p.exact[2]= %.12f, n(Pi<=P0)= %.0f, n(P)= %i\n"
			  ,P0, P_1, P_, zlr-1, i-1);

		Pmax=P_vtl[1];for(kLauf=1; kLauf<index; kLauf++)if(Pmax<P_vtl[kLauf])Pmax=P_vtl[kLauf];//maximal p
		
		printf("\nHypergeometric P disribution\n\n");//P verteilungsgraphik
		for(kLauf=1; kLauf<index; kLauf++)
		{
			if(P_vtl[kLauf]>0.0001)//graphik wenn pi > 0.0001
			{
				if(P_vtl[kLauf]==P0)if(sw==1)printf(" 0\xB3");
				if(P_vtl[kLauf]!=P0)if(sw==1)printf("  \xB3");if(sw==0)printf("  i");sw=1;//schalter y achsen bezeichnung i
				for(jLauf=1; jLauf<=(P_vtl[kLauf]/Pmax)*30;jLauf++)//graphikbreite Pi/Pmax * 30
				{
					if(P_vtl[kLauf]>P0)printf("\xB0");
					if(P_vtl[kLauf]==P0)printf("\xDB");
					if(P_vtl[kLauf]<P0)printf("\xB2");
				}
				printf("\n");
			}
		}
		printf("  \xC5");
		for(jLauf=1; jLauf<=31;jLauf++)printf("\xC4");
		printf(" P\n");
	
		printf("\nP: Conditional hypergeometric point-probability P of given table,\n   where P is defined by Pi= (z1!z2!s1!s2!)/(n!a!b!c!d!);\n");
		printf("p: Exact 1- and 2-sided probability p of initial cross classification table.\n");
	}
	
	if((argc==6 && strcmp(argv[5],"1") != 0) || argc < 6)
	{
		printf("\t       P0= %.4f\n\n\t       p.exact[1]= %.4f\n\t       p.exact[2]= %.4f\n"
			   ,P0, P_1, P_);
	}

	fclose(outStream);

	getch();
						
	return 0;
}

long double fakt(double wert, double F)// faktoriell in t=2 teilen zur exponentialdeflation// 
{
	int iLauf;
	long double fn_erg_1=1;  
	fn_erg=1;

	for(iLauf = 1; iLauf <= floor(wert/2); iLauf++) fn_erg_1 *= iLauf;	//teil t=1
	fn_erg_1= fn_erg_1/F;
	
	for(iLauf = iLauf; iLauf <= wert; iLauf++) fn_erg *= iLauf;			//teil t=2
	fn_erg = fn_erg/F;

																		//teil t=3 ...
	
	fn_erg=fn_erg*fn_erg_1; //!wert = fn_erg * F^t

	return fn_erg;
};

void _head(void) 
{
	printf("\nFisher_Exact by Dietmar Schrausser, (c) SCHRAUSSER 2009\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Fisher_Exact:\n"); 
};	
   
void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=41; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: Fisher_Exact [a] [b] [c] [d] [[1]]\n");
	printf(" [a][b][c][d] ....... cell counts a,b,c,d\n");
	printf(" [1] .....................(1) full output\n");
	for(iLauf=1; iLauf<=41; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Fisher_Exact (c) SCHRAUSSER 2009\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);

	getch();

	exit(1);
};



/* alternativ: p exact zweiseitig  über gesamtschleifenprozedur 
	for (iLauf=0; iLauf<n; iLauf++)//schleife über a
	{
		for (jLauf=0; jLauf<n; jLauf++)//schleife über b
		{
			for (kLauf=0; kLauf<n; kLauf++)//schleife über c
			{
				for (lLauf=0; lLauf<n; lLauf++)//schleife über d
				{
					a1=iLauf+jLauf; 
					a2=kLauf+lLauf; 
					b1=iLauf+kLauf;
					b2=jLauf+lLauf;

				    if(a1== z1 && a2 ==z2 && b1 ==s1 &&b2==s2) //bei gleichen randhäufigkeiten
					 if ((iLauf+ jLauf!=0) &&
						 (kLauf+ lLauf!=0) &&
						 (iLauf+ kLauf!=0) &&
						 (jLauf+ lLauf!=0) )
					{
						//Theta i =  Hypergeometrische Wahrscheinlichkeit Pi für jede mögliche anordnung mit gleichen randhäufigkeiten
						Pi= (fakt(a1)*fakt(a2)*fakt(b1)*fakt(b2))/(fakt(n)*fakt(iLauf)*fakt(jLauf)*fakt(kLauf)*fakt(lLauf));
						
						if (Pi <= P0 + 0.000000001 ) { P_+=Pi;zlr++;} //P0 bedingte summierung von Pi zu P_
						              /*korrektur zur fliesskommainkonsistenz*/
					
					    //i++;
						//anzahl aller möglichen anordnungen mit gleichen randhäufigkeiten
						
						//printf("\n%i %i\n%i %i\tP%i= %.3f P_= %.3f\n",iLauf,jLauf,kLauf,lLauf, i,Pi, P_);
				//	}
			//	}
		//	}	
	//	}
//	}
