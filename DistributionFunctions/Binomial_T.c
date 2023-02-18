//---------------------------------------------------------------------------------------------------------| Binomial_T by Dietmar Schrausser, (c) SCHRAUSSER 2010
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include "fn_nk.h"

double fn_binom(double k,double n, int fo);
void _head(void);
void _profil();

main(int argc, char *argv[])
{
	int fo=0;
	
	if(argc > 4 || argc < 3) _profil();
	if(argc ==4) fo=atoi(argv[3]);

	_head(); fn_binom(atof(argv[1]), atof(argv[1])+atof(argv[2]), fo);

	getch();

	return 0;	
}

double fn_binom(double k,double n, int fo)// binomialverteilung  //
{
	FILE *out, *out2;
	
	int jLauf, lz;
	double iLauf, p=0.5, q, c, BW=0, BP, BW_=0, P=0, p_1, p_2, max=0;
	char dbuffer[9], tbuffer[9];

	q=1-p;
	c= n-k;

	out = fopen( "binomial_t_log.txt", "a" );
	out2 = fopen( "binomial_t_p.txt", "a" );

	for(iLauf = n; iLauf >= 0; iLauf--)
	{
		BW =fn_nk(n,iLauf)*pow(p,iLauf)*pow(q,n-iLauf);
		if(max<BW)max=BW;
	}

	//bildschirmausgabe
	if(fo!=1)printf("p(B)= %.3f, q(B)= %.3f, b= %.0f, c= %.0f, n= %.0f\n", p, q, k, c, n);
	
	if(fo==1)// full output
	{
		printf("p(B)= %.3f, q(B)= %.3f\nb= %.0f, c= %.0f, n= %.0f\nP(b)= %.3f\n", p, q, k, c, n, k/n);
		printf("\ni");
		for(jLauf = 1; jLauf <= 30+13; jLauf++)printf(" ");printf("  P(i)   Pi    <pi    >pi");
		printf("\n");
	}

	//dateiausgabe
	_strdate( dbuffer );_strtime( tbuffer );
	fprintf(out,"Binomial_T (c) SCHRAUSSER 2010; %s %s;\n\n", dbuffer , tbuffer);
	fprintf(out, "p= %.3f, q= %.3f, b= %.0f, c= %.0f, n= %.0f, p(b)= %.5f\n\n", p, q, k, c, n, k/n);
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
				if(k>c)
				{
					if(iLauf>k)printf("\xB2");
					if(iLauf==k)printf("\xDC");
					if(iLauf<k)if(iLauf>c)printf("\xB0");
					if(iLauf<=c)printf("\xB2");
				}
				if(k<c)
				{
					if(iLauf>=c)printf("\xB2");
					if(iLauf==k)printf("\xDC");
					if(iLauf<c)if(iLauf>k)printf("\xB0");
					if(iLauf<k)printf("\xB2");
				}
				if(k==c)
				{
					if(iLauf>k)printf("\xB2");
					if(iLauf==k)printf("\xDC");
					if(iLauf<k)printf("\xB2");
				}
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
				if(k>c)
				{	
					if(iLauf>k)fprintf(out, "%%");
					if(iLauf==k)fprintf(out, "_");
					if(iLauf<k)if(iLauf>c)fprintf(out, "|");
					if(iLauf<=c)fprintf(out, "%%");
				}
				if(k<c)
				{
					if(iLauf>=c)fprintf(out, "%%");
					if(iLauf==k)fprintf(out, "_");
					if(iLauf<c)if(iLauf>k)fprintf(out, "|");
					if(iLauf<k)fprintf(out, "%%");
				}
				if(k==c)
				{
					if(iLauf>k)fprintf(out, "%%");
					if(iLauf==k)fprintf(out, "_");
					if(iLauf<k)fprintf(out, "%%");
				}
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

    // pexact
	p_1= BW_;if(k>c) p_1=(1-BW_)+BP; p_2 = 2* p_1;
	if(k==c){p_1= BW_-BP/2; p_2 = 2* p_1;}
	
	printf("\nBinomial Point Probability P0= %.4f\n", BP);
	printf("\nExact 1-sided Probability p.exact[1]= %.4f\n", p_1);
	printf("Exact 2-sided Probability p.exact[2]= %.4f\n", p_2);

	//dateiausgabe
	fprintf(out, "\nBinomial Point Probability P0= %.15f\n", BP);
	fprintf(out, "\nExact 1-sided Probability p.exact[1]= %.15f\n", p_1);
	fprintf(out, "Exact 2-sided Probability p.exact[2]= %.15f\n\n\n", p_2);

	fprintf(out2, "\n");
	
	fclose(out);
	fclose(out2);

	return 0;
};

void _head(void) 
{
	printf("\nBinomial_T by Dietmar Schrausser, (c) SCHRAUSSER 2010\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Binomial_T:\n\n"); 
};	
   
void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=32; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: Binomial_T [b] [c] [[1]]\n");
	printf(" [b] ............. cell count b\n");
	printf(" [c] ............. cell count c\n");
	printf(" [1] .......... (1) full output\n");
	for(iLauf=1; iLauf<=32; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Binomial_T (c) SCHRAUSSER 2010\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);

	getch();

	exit(1);
};