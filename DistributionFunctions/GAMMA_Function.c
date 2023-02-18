//---------------------------------------------------------------------------| GAMMA_Function by Dietmar SCHRAUSSER 2009               //             //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

double fn_erg;

void _profil(); 
void _head(); 
double gamma(double wert); 
double gamma_invers(double wert, int sw, int sw2); 
void gamma_graph(double wert, double wert2);                    

void main(int argc, char *argv[]) 
{
	if (argc != 3) _profil();

	if(atoi(argv[1])==1)if (atoi(argv[2]) < 0 || atoi(argv[2])  > 70) //------------------------> x bereich
	{	
   		printf("\n0<x<=70\n");_profil();
	}
	if(atoi(argv[1])==2)if (atof(argv[2]) < 0.885 || atof(argv[2])  > 999) //------------------------> gamma bereich
	{	
   		printf("\n0.885<=\xB3\xEE<=999\n");	_profil();
	}
	
	_head();
	
	if(atoi(argv[1])==1)
	{
		printf("\n\nx(%g) \xB3\xEE= %.4g\n\n", atof(argv[2]), gamma(atof(argv[2])));
		gamma_graph(gamma(atof(argv[2])), atof(argv[2]));
	};

	if(atoi(argv[1])==2) gamma_invers(atof(argv[2]), 1, 0);

	getch();

};

double gamma(double QX) 
{    
	int iLauf, QILauf;
	double P1[10], QY=0, QXQ=0, QYQ=0, QFQ=0, QWQ=0, QZQ=0, R2=1;
	
	P1[0] =	1;
	P1[1] =	-0.577191652;
	P1[2] =	0.988205891;
	P1[3] =	-0.897056937;
	P1[4] =	0.918206857;
	P1[5] =	-0.756704078;
	P1[6] =	0.482199394;
	P1[7] =	-0.193527818;
	P1[8] =	0.035868343;

	//-----------------------------------------------------------------------| Prozedur 
	
	if (QX != floor(QX))
		{
			if (QX < 1)				
			{ 
				QY=QX; R2=P1[8]; for (QILauf=7; QILauf >=0  ;QILauf--) R2 = R2 * QY + P1[QILauf];
				R2 = R2/QY; 
			}
			
			if (QX >= 1 && QX <= 2) 
			{ 
				QY=QX-1; R2=P1[8]; for (QILauf=7; QILauf >=0  ;QILauf--) R2 = R2 * QY + P1[QILauf];
			}
			
			if (QX > 2)
			{
				QY=QX-floor(QX); R2=P1[8]; for (QILauf=7; QILauf >=0  ;QILauf--) R2 = R2 * QY + P1[QILauf];
			    for(iLauf=1; iLauf <= QX-1;iLauf++) R2 = R2 * (QY+iLauf);//-> (x-1+rx)(x-2+rx)...(x-(x-1)+rx) *_fn_P(REST),  rx=REST von x
			}
		}
		if (QX == floor(QX)) for(iLauf=1; iLauf < QX; iLauf++) R2 *= iLauf; // (x-1)! 

		QXQ=R2; QYQ=-7;	
		
		if(QXQ !=0 )
		{
			QFQ = log10(sqrt(pow(QXQ,2)));
			QYQ=QFQ+QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);		
			if (QFQ < 0)  QFQ= -1*(floor(sqrt(pow(QFQ,2))));
			QZQ=QFQ; QFQ=QYQ; 
			if (QFQ >= 0) QFQ= floor(QFQ);	
			if (QFQ < 0)  QFQ= -1*(floor(sqrt(pow(QFQ,2))));	
			QYQ=QZQ-QFQ-1;
			if (QYQ < 19 ) 
			{
				if (QYQ < 0 ) QXQ=0; 
				if (QYQ >=0 )
				{
					if (QZQ >= 90){ QXQ *= 0.00000000000000000001; QFQ=QZQ; QZQ -= 20;}
					QWQ = sqrt(pow(QXQ*pow(10,(-1*QZQ)),2)); QWQ=floor(QWQ*pow(10,QYQ)+0.5);
					QWQ *= pow(10,QZQ)*pow(10,(-1*QYQ));
					if (QFQ >= 90) QWQ *= pow(10000000000,2);
					if (QXQ >= 0) QXQ = QWQ; 
					if (QXQ < 0) QXQ = -1*QWQ;
				}
			}
		}
		
	R2=QXQ;	

	return R2;
};

double gamma_invers(double wert, int sw, int sw2)
{
	int iLauf;
	double aG, bG, erg, i_, i=1, zlr=0, zlr_1, krit=10000, krit2=1000;

	fn_erg=0;
	
	if(wert >= 0.885)
	for(iLauf=1;iLauf<=2;iLauf++)
	{	
		bG=i_; i_=1.45; i=1, zlr_1=zlr; zlr=0; erg=99999;
		
		while(floor(erg*krit2)!=floor(wert*krit2) && zlr < krit)
		{	
			while(erg < wert )
			{
				erg=gamma(i_); 
				if(floor(erg*krit2)==floor(wert*krit2) || zlr > krit) break; 
				if(iLauf==1) i_+=i;  
				if(iLauf==2) i_-=i;
				
				zlr++;//printf("gam=%f x=%f\n",erg, i_);
			} 
			i/=100;
			
			while(erg > wert )
			{
				erg=gamma(i_); 
				if(floor(erg*krit2)==floor(wert*krit2) || zlr > krit) break; 
				if(iLauf==1) i_-=i;  
				if(iLauf==2) i_+=i; 
					
				zlr++;//printf("gam=%f x=%f\n",erg, i_);
			} 
			i/=10;
		}	
	}

	aG=i_;
	
	if(sw==1)
	{
		printf("\n\na\xB3\xEE'(%g) x= ", wert);
		if (floor(erg*krit2)==floor(wert*krit2))printf("%.4g, Iterations i= %g\n", aG, zlr);
		if (floor(erg*krit2)!=floor(wert*krit2))printf("{}, Iterations i= %g\n", zlr);
		printf("b\xB3\xEE'(%g) x= ", wert);
		if (floor(erg*krit2)==floor(wert*krit2))printf("%.4g, Iterations i= %g\n", bG, zlr_1);
		if (floor(erg*krit2)!=floor(wert*krit2))printf("{}, Iterations i= %g\n", zlr_1);
	}

	if(sw2==1) fn_erg= aG;
	if(sw2==2) fn_erg= bG;
	
	return fn_erg;
};

void gamma_graph(double wert, double wert2)
{
	double iLauf, jLauf, a_, b_,  mind=0;
	
	printf("\n\xB3\xEE\n\n");
	
	for(iLauf=6; iLauf>=0.9;iLauf-=0.3)
	{
		printf(" \xB3");
		
		a_	= gamma_invers(iLauf,0,1);
		b_	= gamma_invers(iLauf,0,2);
										
		for(jLauf=1; jLauf<=a_*8;jLauf++)printf(" "); 
		
		mind=0;	
		if(wert2<1.46 && (iLauf-0.3<wert && iLauf>=wert)) 
		{
			printf("\xDC %.3f", wert); mind=6;
		}
		else
		{
			printf(".");
		}
	
		for(jLauf=1; jLauf<=((b_-a_)*8-mind);jLauf++)printf(" "); 
		
		mind=0;
		if(wert2>=1.46 && (iLauf-0.3<wert && iLauf>=wert)) 
		{
			printf("\xDC %.3f", wert); mind=5;
		}
		else
		{
			printf(".");
		}
		printf("\n");

	}
	printf(" \xB3\n \xB3\n \xC5");
	for(iLauf=1; iLauf<=34;iLauf++)printf("\xC4");

	printf(" x\n\n");
};

void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=36; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Usage: GAMMA_Function [mode] [value]\n");
	printf(" [mode] ..... (1)F(x)\x1A\xB3\xEE (2)F'(\xB3\xEE)\x1Ax\n");
	printf(" [value] .................... x / \xB3\xEE\n");
	for(iLauf=1; iLauf<=36; iLauf++) cprintf("\xC4"); printf("\n");
	printf("GAMMA_Function by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	getch();
	
	exit(0);
};	
                
void _head() 
{
	printf("\nGAMMA_Function by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing GAMMA_Function:"); 
};

         