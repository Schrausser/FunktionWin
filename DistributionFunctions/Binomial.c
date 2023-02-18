//---------------------------------------------------------------------------------------------------------| Binomial by Dietmar Schrausser, (c) SCHRAUSSER 2009
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "fn_nk.h"

double fn_binom(double p, double k,double n, int fo);
void _head(void);
void _profil();

main(int argc, char *argv[])
{
	int fo=0;
	
	if(argc > 5 || argc < 4) _profil();
	if(argc ==5) fo=atoi(argv[4]);

	_head(); fn_binom(atof(argv[1]), atof(argv[2]), atof(argv[3]), fo);

	getch();

	return 0;	
}


double fn_binom(double p, double k,double n, int fo)// binomialverteilung  //
{
	FILE *out, *out2;
	
	int jLauf, lz;
	double iLauf, q, BW=0, BP, BW_=0, P=0, max=0;
	char dbuffer[9], tbuffer[9];

	q=1-p;

	out = fopen( "binomial_log.txt", "a" );
	out2 = fopen( "binomial_p.txt", "a" );

	for(iLauf = n; iLauf >= 0; iLauf--)
	{
		BW =fn_nk(n,iLauf)*pow(p,iLauf)*pow(q,n-iLauf);
		if(max<BW)max=BW;
	}

	//bildschirmausgabe
	if(fo!=1)printf("p(A)= %.3f, q(A)= %.3f, k= %.0f, n= %.0f\n", p, q, k, n);
	
	if(fo==1)// full output
	{
		printf("p(A)= %.3f, q(A)= %.3f\nk= %.0f, n= %.0f\nP(k)= %.3f\n", p, q, k,n, k/n);
		printf("\ni");
		for(jLauf = 1; jLauf <= 30+13; jLauf++)printf(" ");printf("  P(i)   Pi    <pi    >pi");
		printf("\n");
	}

	//dateiausgabe
	_strdate( dbuffer );_strtime( tbuffer );
	fprintf(out,"Binomial (c) SCHRAUSSER 2009; %s %s;\n\n", dbuffer , tbuffer);
	fprintf(out, "p= %.3f, q= %.3f, k= %.0f, n= %.0f, p(k)= %.5f\n\n", p, q, k, n, k/n);
	fprintf(out, "i");
	for(jLauf = 1; jLauf <= 40+13; jLauf++)fprintf(out, " ");fprintf(out, "P(i)    Pi                <pi                >pi");
	fprintf(out, "\n");

	for(iLauf = n; iLauf >= 0; iLauf--)
	{
		BW =fn_nk(n,iLauf)*pow(p,iLauf)*pow(q,n-iLauf);
		if(iLauf== k) BP= BW;
		if(iLauf<=k) BW_+=BW;
		P+=BW;
		
		//bildschirmausgabe full output
		if(fo==1)if(BW>0.0001)
		{
			printf("%2.0f \xB3",iLauf);
			for(jLauf = 1; jLauf <= (BW/max)*30; jLauf++)//graphik, breite = Pi/Pmax * 30
			{
				if(iLauf>k)printf("\xB0");
				if(iLauf==k)printf("\xDC");
				if(iLauf<k)printf("\xB2");
			}
			lz=10;
			if(BW==max) lz=10;
			if(iLauf==k){printf(" %.4f",BW);lz=lz-7;}
			
			for(jLauf = 1; jLauf <= (30+lz)-(floor((BW/max)*30)); jLauf++)printf(" ");
			if(iLauf!=k)printf("\xB3 ");	
			if(iLauf==k)printf("\xDC ");
			printf(" %.2f  %.3f  %.3f  %.3f", iLauf/n, BW, 1-P+BW, P);if(iLauf==k)printf(" \xDF ");
			printf("\n");
		}	
		
		//dateiausgabe
		fprintf(out, "%3.0f |",iLauf);
		for(jLauf = 1; jLauf <= (BW/max)*40; jLauf++)//graphik
		{
				if(iLauf>k)fprintf(out, "%%");
				if(iLauf==k)fprintf(out, "_");
				if(iLauf<k)fprintf(out, "|");
		}
		lz=10;
		if(BW==max) lz=10;
		if(iLauf==k){fprintf(out, " %.4f",BW);lz=lz-7;}
		
		for(jLauf = 1; jLauf <= (40+lz)-(floor((BW/max)*40)); jLauf++)fprintf(out, " ");
		fprintf(out, "%.3f  %.15f  %.15f  %.15f\n", iLauf/n, BW, 1-P+BW, P);

		fprintf(out2, "%.19f\n", BW);
	}
	
	//bildschirmausgabe
	if(fo==1)// full output
	{
		//graphik x achse
		printf("\xC4\xC4\xC4\xC5");
		for(jLauf = 1; jLauf <= 30+10; jLauf++)printf("\xC4");
		printf("\xC5\n");
		for(jLauf = 1; jLauf <= 30+13; jLauf++)printf(" ");printf("P");
		//printf("\n");
	}
	printf("\nBinomial Point Probability  k  P= %.4f\n", BP);
	printf("Binomial kum. Probability <=k <p= %.4f\n", BW_);
	printf("Binomial kum. Probability  >k >p= %.4f\n", 1-BW_);

	//dateiausgabe
	fprintf(out, "\nBinomial Point Probability  k  P= %.15f\n", BP);
	fprintf(out, "Binomial kum. Probability <=k <p= %.15f\n", BW_);
	fprintf(out, "Binomial kum. Probability  >k >p= %.15f\n\n\n", 1-BW_);

	fprintf(out2, "\n");
	
	fclose(out);
	fclose(out2);

	return 0;
};

void _head(void) 
{
	printf("\nBinomial by Dietmar Schrausser, (c) SCHRAUSSER 2009\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Binomial:\n\n"); 
};	
   
void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=34; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: Binomial [p] [k] [n] [[1]]\n");
	printf(" [p] ..... probability of event A\n");
	printf(" [k] .............. n of events A\n");
	printf(" [n] ................ n of trials\n");
	printf(" [1] ............ (1) full output\n");
	for(iLauf=1; iLauf<=34; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Binomial (c) SCHRAUSSER 2009\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);

	getch();

	exit(1);
};