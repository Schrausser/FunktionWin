//---------------------------------------------------------------------------------------------------------| Geometric by Dietmar Schrausser, (c) SCHRAUSSER 2009
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

double fn_geom(double p, double r, int fo);
void _head(void);
void _profil();

main(int argc, char *argv[])
{
	int fo=0;
	
	if(argc > 4 || argc < 3) _profil();
	if(argc ==4) fo=atoi(argv[3]);

	_head(); fn_geom(atof(argv[1]), atof(argv[2])-1, fo);

	getch();

	return 0;	
}


double fn_geom(double p, double r, int fo)// Geometricverteilung  //
{
	FILE *out, *out2;
	
	int jLauf, lz;
	double iLauf, q, GW=0, GP, GW_=0, P=0, max=0;
	char dbuffer[9], tbuffer[9];

	q=1-p;

	out = fopen( "Geometric_log.txt", "a" );
	out2 = fopen( "Geometric_p.txt", "a" );

	for(iLauf = 0; iLauf <= 500; iLauf++)
	{
		GW=p*pow(q,iLauf);
		if(max<GW)max=GW;
		if(GW<0.001) break;
	}

	//bildschirmausgabe
	if(fo!=1)printf("p(A)= %.3f, q(A)= %.3f, r+1= %.0f\n", p, q, r+1);
	
	if(fo==1)// full output
	{
		printf("p(A)= %.3f, q(A)= %.3f, r+1= %.0f\n", p, q, r+1);
		printf("\ni");
		for(jLauf = 1; jLauf <= 30+13; jLauf++)printf(" ");printf("   Pi     <pi    >pi");
		printf("\n");
	}

	//dateiausgabe
	_strdate( dbuffer );_strtime( tbuffer );
	fprintf(out,"Geometric (c) SCHRAUSSER 2009; %s %s;\n\n", dbuffer , tbuffer);
	fprintf(out, "p= %.3f, q= %.3f, r+1= %.0f\n\n", p, q, r+1);
	fprintf(out, "i");
	for(jLauf = 1; jLauf <= 40+13; jLauf++)fprintf(out, " ");fprintf(out, "Pi                 <pi                >pi");
	fprintf(out, "\n");

	for(iLauf = 500; iLauf >= 0; iLauf--)
	{
		GW=p*pow(q,iLauf);
		if(iLauf== r) GP= GW;
		if(iLauf<=r) GW_+=GW;
		P+=GW;
		
		if(GW>0.001)
		{	
			//bildschirmausgabe full output
			if(fo==1)if(GW>0.0001)
			{
				printf("%3.0f \xB3",iLauf+1);
				for(jLauf = 1; jLauf <= (GW/max)*30; jLauf++)//graphik, breite = Pi/Pmax * 30
				{
					if(iLauf>r)printf("\xB0");
					if(iLauf==r)printf("\xDC");
					if(iLauf<r)printf("\xB2");
				}
				lz=10;
				if(GW==max) lz=10;
				if(iLauf==r){printf(" %.4f",GW);lz=lz-7;}
				
				for(jLauf = 1; jLauf <= (30+lz)-(floor((GW/max)*30)); jLauf++)printf(" ");
				if(iLauf!=r)printf("\xB3 ");	
				if(iLauf==r)printf("\xDC ");
				printf(" %.3f  %.3f  %.3f", GW, 1-P+GW, P);if(iLauf==r)printf(" \xDF ");
				printf("\n");
			}	
			
			//dateiausgabe
			fprintf(out, "%3.0f |",iLauf+1);
			for(jLauf = 1; jLauf <= (GW/max)*40; jLauf++)//graphik
			{
					if(iLauf>r)fprintf(out, "%%");
					if(iLauf==r)fprintf(out, "_");
					if(iLauf<r)fprintf(out, "|");
			}
			lz=10;
			if(GW==max) lz=10;
			if(iLauf==r){fprintf(out, " %.4f",GW);lz=lz-7;}
			
			for(jLauf = 1; jLauf <= (40+lz)-(floor((GW/max)*40)); jLauf++)fprintf(out, " ");
			fprintf(out, "%.15f  %.15f  %.15f\n",  GW, 1-P+GW, P);

			fprintf(out2, "%.19f\n", GW);
		}
	}
	
	//bildschirmausgabe
	if(fo==1)// full output
	{
		//graphik x achse
		printf("\xC4\xC4\xC4\xC4\xC5");
		for(jLauf = 1; jLauf <= 30+10; jLauf++)printf("\xC4");
		printf("\xC5\n");
		for(jLauf = 1; jLauf <= 30+13; jLauf++)printf(" ");printf("P");
		printf("\n");
	}
	printf("\nGeometric Point Probability  r+1  P= %.4f\n", GP);
	printf("Geometric kum. Probability <=r+1 <p= %.4f\n", GW_);
	printf("Geometric kum. Probability  >r+1 >p= %.4f\n", 1-GW_);

	//dateiausgabe
	fprintf(out, "\nGeometric Point Probability  r+1  P= %.15f\n", GP);
	fprintf(out, "Geometric kum. Probability <=r+1 <p= %.15f\n", GW_);
	fprintf(out, "Geometric kum. Probability  >r+1 >p= %.15f\n\n\n", 1-GW_);

	fprintf(out2, "\n");
	
	fclose(out);
	fclose(out2);

	return 0;
};

void _head(void) 
{
	printf("\nGeometric by Dietmar Schrausser, (c) SCHRAUSSER 2009\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Geometric:\n\n"); 
};	
   
void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=34; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: Geometric [p] [r+1] [[1]]\n");
	printf(" [p] ..... probability of event A\n");
	printf(" [r+1] .............. n of trials\n");
	printf(" [1] ............ (1) full output\n");
	for(iLauf=1; iLauf<=34; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Geometric (c) SCHRAUSSER 2009\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);

	getch();

	exit(1);
};