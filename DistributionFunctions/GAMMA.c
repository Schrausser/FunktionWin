//---------------------------------------------------------------------------| GAMMA by Dietmar SCHRAUSSER 2009               //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void _err_msg (); 
void _head(void);                    

long double QX_[500], P1[10], QX, QY, QXQ, QYQ, QFQ, QWQ, QZQ, R2;
float s_ij;

main(int argc, char *argv[]) 
{    
	FILE *inStream, *outStream;
	int iLauf, dLauf, QILauf, nA;
		
	if (argc != 4) 
	{
   		printf("ERROR, check arguments!\n");
   		_err_msg(argv[0]);
	}

	nA = atoi(argv[1]);

	inStream = fopen( argv[2], "r" );
	for (iLauf = 0; iLauf < nA; iLauf++)
	{	
			fscanf(inStream,"%f", &s_ij );	
			if (s_ij < 0 || s_ij > 70) 
			{
   				printf("ERROR, check data range (0<x<70)\n");
   				_err_msg(argv[0]);
			}

			QX_[iLauf+1] = s_ij;
	}
	fclose( inStream  );

	P1[0] =	1;
	P1[1] =	-0.577191652;
	P1[2] =	0.988205891;
	P1[3] =	-0.897056937;
	P1[4] =	0.918206857;
	P1[5] =	-0.756704078;
	P1[6] =	0.482199294;
	P1[7] =	-0.193527818;
	P1[8] =	0.035868343;

	outStream = fopen( argv[3], "w" );
	_head();
	//-----------------------------------------------------------------------| Prozedur 
	for(dLauf=1; dLauf <=nA ; dLauf++)//------------------------------------> durchgang
	{
		QX=QY=QXQ=QYQ=QFQ=QWQ=QZQ=0; R2=1; QX = QX_[dLauf];
	
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
		R2=QXQ; fprintf(outStream, "%.3f\n", R2);
	
	}// dLauf end
	fclose( outStream  );

	return 0;
}

void _err_msg()
{
	printf("---------------------------------\n");
	printf("Usage: GAMMA [n] [input] [output]\n");
	printf(" [n] ................. n of cases\n");
	printf(" [input] ............. input file\n");
	printf(" [output] ........... output file\n");
	printf("---------------------------------\n");
	printf("GAMMA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(EXIT_FAILURE);
}	

//---------------------------------------------------------------------------| titelzeile bildschirmausgabe                   
void _head(void) 
{
	printf("\nGAMMA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing GAMMA:\n"); 
}

//---------------------------------------------------------------------------| ENDE          