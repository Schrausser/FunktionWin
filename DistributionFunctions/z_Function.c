//---------------------------------------------------------------------------| z_Function by Dietmar SCHRAUSSER 2009               //             //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void _profil(); 
void _head(); 
void _RD(); 
long double _NP(long double p_wert_in);  
long double _NU(long double z_wert_in); 
long double fn_z(long double wert_in, int sw, int sw2);
void z_graph(double wert, double wert2, int sw);
               

long double   fn_erg, z_wert, p_wert, OO[10], RD[10];

main(int argc, char *argv[]) 
{ 
	if (argc != 3) _profil();
	if (atoi(argv[1])==1 && (atof(argv[2])>=1 || atof(argv[2])<=0 )){ printf("\n0<p<1 .0\n");_profil();}
	if (atof(argv[2])==0 &&  stricmp(argv[2], "0") != 0  ) {printf("\nvalue .0\n");_profil();}
	
	_head();
	
	fn_z(atof(argv[2]), atoi(argv[1]),1);

	if(atoi(argv[1])==1) z_graph(atof(argv[2]), fn_erg, 1);
	if(atoi(argv[1])==2) z_graph(fn_erg, fn_erg, 2);

	getch();

	return 0;
}

//---------------------------------------------------------------------------| funktionen 
long double fn_z(long double wert_in, int sw, int sw2)
{    
	z_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=RD[1]=RD[5]=1;

	//-----------------------------------------------------------------------| Prozedur 
	if (sw == 1)//F(x=p)
	{		
		p_wert = wert_in;//p-wert eingabe	
		
		//z-Wert Berechnung
		_NP(p_wert);
		
		if(RD[0]==0)
		{
			RD[1]=z_wert; RD[2]=-5;

			//Kurvenglättung
			
			if(RD[1] !=0 )
			{	
				RD[3] = log10(fabs(RD[1]));
				RD[2]=RD[3]+RD[2]; 
				if (RD[3] >= 0) RD[3]= floor(RD[3]);		
				if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
				RD[4]=RD[3]; RD[3]=RD[2]; 
				if (RD[3] >= 0) RD[3]= floor(RD[3]);	
				if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
				RD[2]=RD[4]-RD[3]-1;
				if (RD[2] < 19 ) 
				{
					if (RD[2] < 0 ) RD[1]=0; 
					if (RD[2] >=0 )
					{
						if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
						RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
						RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
						if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
						if (RD[1] >= 0) RD[1] = RD[5]; 
						if (RD[1] < 0) RD[1] = -1*RD[5];
					}
				}
			}

			z_wert=RD[1]; if(sw2==1)printf("\n\np= %g, z= %.5g\n", wert_in, z_wert);//bildschirmausgabe
			fn_erg=z_wert;
		}
	
	}//end if argv[1]

	if (sw == 2)//F(y=z)
	{
		z_wert = wert_in;//z-wert eingabe

		//p-Wert Berechnung
		_NU(z_wert);
		
		if(RD[0]==0)
		{
			RD[1]=p_wert; RD[2]=-5;

			//Kurvenglättung
			
			if(RD[1] !=0 )
			{
				RD[3] = log10(fabs(RD[1]));
				RD[2]=RD[3]+RD[2]; 
				if (RD[3] >= 0) RD[3]= floor(RD[3]);		
				if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
				RD[4]=RD[3]; RD[3]=RD[2]; 
				if (RD[3] >= 0) RD[3]= floor(RD[3]);	
				if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
				RD[2]=RD[4]-RD[3]-1;
				if (RD[2] < 19 ) 
				{
					if (RD[2] < 0 ) RD[1]=0; 
					if (RD[2] >=0 )
					{
						if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
						RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
						RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
						if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
						if (RD[1] >= 0) RD[1] = RD[5]; 
						if (RD[1] < 0) RD[1] = -1*RD[5];
					}
				}
			}

			p_wert=RD[1]; if(sw2==1)printf("\n\nz= %g, p= %.5g\n", wert_in, p_wert);//bildschirmausgabe
			fn_erg=p_wert;
		}

	}//end if sw
	
	return fn_erg;
};

  
long double _NP(long double p_wert)
{
	if(p_wert!=0.5)
	{
		if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}
		OO[1]=-1*log(4*OO[1]*(1-OO[1]));
		OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
		OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
		OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
		z_wert=OO[2]*OO[1]+1.570796288;
		z_wert=sqrt(OO[1]*z_wert);
		if(p_wert<0.5) z_wert = z_wert * -1;
	}
	return 0;
};

long double _NU(long double z_wert)
{
	OO[1] = fabs(z_wert);
	if(OO[1]>7) p_wert=0; 
	if(OO[1]<=7)
	{
		p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
		p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
		p_wert=0.5*pow(p_wert,-16);
	}
	if (z_wert>0) p_wert=1-p_wert;
	
	return 0;
};

void z_graph(double wert, double wert2, int sw)
{
	int kLauf;
	double iLauf, jLauf, a_, zlr=0, L_=0, p_=0;
	
	printf("\n p\n\n");
	
	for(iLauf=0.98; iLauf>0;iLauf-=0.06)
	{
		printf(" \xB3");
	
		a_	= fn_z(iLauf,1,0); a_+=2.326;
							
		for(jLauf=1; jLauf<=a_*7;jLauf++)
		{
			printf(" "); zlr++; 
			if(sw==1)if(wert>0.98 && iLauf == 0.98 || iLauf-0.06<wert && iLauf>=wert)printf("\b\xFA");//x referenzlinie	
		}
		
		if(wert>0.98 && iLauf == 0.98 || iLauf-0.06<wert && iLauf>=wert)	
		{	
			if(wert>0.995)printf(". \x10  %.3f", wert2);
			if(wert>=0.005 && wert<=0.995){printf("\xDC %.3f", wert2); L_=zlr; p_=1;}
			if(wert<0.005)printf("\b\b\x11 %.3f", wert2);
		}
		else								
		{	
			printf(".");
		}
		
		if(L_!=zlr)if(sw==2)if(p_==1)//y referenzlinie
		{
			for(kLauf=1;kLauf<L_-zlr;kLauf++)printf(" ");
			printf("\xFA");
		}
		
		printf("\n");
		zlr=0;
	}
	printf(" \xC5");
	for(iLauf=1; iLauf<=17;iLauf++)printf("\xC4");printf("\x9D");for(iLauf=1; iLauf<=14;iLauf++)printf("\xC4");
	printf(" z\n\n");
};
                 
void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=34; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: z_Function [mode] [x]\n");
	printf(" [mode] ..... (1)Fx=p\x1Az (2)Fy=z\x1Ap\n");
	printf(" [x] ............ p-value/z-value\n");
	for(iLauf=1; iLauf<=34; iLauf++) cprintf("\xC4"); printf("\n");
	printf("z_Function by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	getch();
	
	exit(0);
};	
                
void _head() 
{
	printf("\nz_Function by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing z_Function:"); 
};

      