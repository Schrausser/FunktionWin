//---------------------------------------------------------------------------------------------------------| Hypergeometric by Dietmar Schrausser, (c) SCHRAUSSER 2009
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "fn_nk.h"

double fn_hygeo(double k, double n,double N, double K,int fo);
void _head(void);
void _profil();

main(int argc, char *argv[])
{
	int fo=0;
	
	if(argc > 6 || argc < 5) _profil();
	if(argc ==6) fo=atoi(argv[5]);

	_head(); fn_hygeo(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]),fo);

	getch();

	return 0;	
}


double fn_hygeo(double k, double n,double N, double K,int fo)// Hypergeometrische verteilung  //
{
	FILE *out, *out2;
	
	int jLauf, lz;
	double iLauf, HG=0, HP, HG_=0, P=0, max=0;
	char dbuffer[9], tbuffer[9];


	out = fopen( "Hypergeometric_log.txt", "a" );
	out2 = fopen( "Hypergeometric_p.txt", "a" );

	for(iLauf = n; iLauf >= 0; iLauf--)
	{
		HG = (fn_nk(K,iLauf)*fn_nk(N-K,n-iLauf))/fn_nk(N,n);
		if(max<HG)max=HG;
	}

	//bildschirmausgabe
	if(fo!=1)printf("k(A)= %.0f, n(A)= %.0f, N= %.0f, K(A)= %.0f\n", k, n, N, K);
	
	if(fo==1)// full output
	{
		printf("k(A)= %.0f, n(A)= %.0f, N= %.0f, K(A)= %.0f\n\n", k, n, N, K);
		printf("\ni");
		for(jLauf = 1; jLauf <= 30+13; jLauf++)printf(" ");printf("  P(i)  Pi     <pi    >pi");
		printf("\n");
	}

	//dateiausgabe
	_strdate( dbuffer );_strtime( tbuffer );
	fprintf(out,"Hypergeometric (c) SCHRAUSSER 2009; %s %s;\n\n", dbuffer , tbuffer);
	fprintf(out, "k(A)= %.0f, n(A)= %.0f, N= %.0f, K(A)= %.0f\n\n", k, n, N, K);
	fprintf(out, "i");
	for(jLauf = 1; jLauf <= 40+13; jLauf++)fprintf(out, " ");fprintf(out, "P(i)   Pi                 <pi                >pi");
	fprintf(out, "\n");

	for(iLauf = n; iLauf >= 0; iLauf--)
	{
		HG = (fn_nk(K,iLauf)*fn_nk(N-K,n-iLauf))/fn_nk(N,n);
		if(iLauf== k) HP= HG;
		if(iLauf<=k) HG_+=HG;
		P+=HG;
		
		//bildschirmausgabe full output
		if(fo==1)if(HG>0.0001)
		{
			printf("%2.0f \xB3",iLauf);
			for(jLauf = 1; jLauf <= (HG/max)*30; jLauf++)//graphik, breite = Pi/Pmax * 30
			{
				if(iLauf>k)printf("\xB0");
				if(iLauf==k)printf("\xDC");
				if(iLauf<k)printf("\xB2");
			}
			lz=10;
			if(HG==max) lz=10;
			if(iLauf==k){printf(" %.4f",HG);lz=lz-7;}
			
			for(jLauf = 1; jLauf <= (30+lz)-(floor((HG/max)*30)); jLauf++)printf(" ");
			if(iLauf!=k)printf("\xB3 ");	
			if(iLauf==k)printf("\xDC ");
			printf(" %.2f  %.3f  %.3f  %.3f", iLauf/n, HG, 1-P+HG, P);if(iLauf==k)printf(" \xDF ");
			printf("\n");
		}	
		
		//dateiausgabe
		fprintf(out, "%3.0f |",iLauf);
		for(jLauf = 1; jLauf <= (HG/max)*40; jLauf++)//graphik
		{
				if(iLauf>k)fprintf(out, "%%");
				if(iLauf==k)fprintf(out, "_");
				if(iLauf<k)fprintf(out, "|");
		}
		lz=10;
		if(HG==max) lz=10;
		if(iLauf==k){fprintf(out, " %.4f",HG);lz=lz-7;}
		
		for(jLauf = 1; jLauf <= (40+lz)-(floor((HG/max)*40)); jLauf++)fprintf(out, " ");
		fprintf(out, "%.3f  %.15f  %.15f  %.15f\n", iLauf/n, HG, 1-P+HG, P);

		fprintf(out2, "%.19f\n", HG);
	}
	
	//bildschirmausgabe
	if(fo==1)// full output
	{
		//graphik x achse
		printf("\xC4\xC4\xC4\xC5");
		for(jLauf = 1; jLauf <= 30+10; jLauf++)printf("\xC4");
		printf("\xC5\n");
		for(jLauf = 1; jLauf <= 30+13; jLauf++)printf(" ");printf("P");
		printf("\n");
	}
	printf("\nHypergeometric Point Probability  k  P= %.4f\n", HP);
	printf("Hypergeometric kum. Probability <=k <p= %.4f\n", HG_);
	printf("Hypergeometric kum. Probability  >k >p= %.4f\n", 1-HG_);

	//dateiausgabe
	fprintf(out, "\nHypergeometric Point Probability  k  P= %.15f\n", HP);
	fprintf(out, "Hypergeometric kum. Probability <=k <p= %.15f\n", HG_);
	fprintf(out, "Hypergeometric kum. Probability  >k >p= %.15f\n\n\n", 1-HG_);

	fprintf(out2, "\n");
	
	fclose(out);
	fclose(out2);

	return 0;
};

void _head(void) 
{
	printf("\nHypergeometric by Dietmar Schrausser, (c) SCHRAUSSER 2009\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Hypergeometric:\n\n"); 
};	
   
void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=43; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: Hypergeometric [k] [n] [N] [K] [[1]]\n");
	printf(" [k] ...... n of events A in Sub-Population\n");
	printf(" [n] ............... size of Sub-Population\n");
	printf(" [N] ................... size of Population\n");
	printf(" [K] .......... n of events A in Population\n");
	printf(" [1] ...................... (1) full output\n");
	for(iLauf=1; iLauf<=43; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Hypergeometric (c) SCHRAUSSER 2009\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);

	getch();

	exit(1);
};