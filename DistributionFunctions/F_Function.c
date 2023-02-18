//---------------------------------------------------------------------------| F_Function by Dietmar SCHRAUSSER 2009               //             //

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void _profil(); 
void _head();                    

long double  QX, QX1, QND, QMD, QQ, QP, QW1, QW2, QX2, Q5, P5, P6, R5=0;//q5=n1, p5=n2, p6=p_wert, 
long double  QX44, QW3=1, QIF, QJFU, QX0, QXQ, QYQ, QFQ, QZQ, QWQ; 

main(int argc, char *argv[]) 
{    
	//int iLauf, QILauf;
	QX=QYQ=QFQ=QWQ=QZQ=0; QXQ=QWQ=1;

	if (argc != 5) {printf("> check arguments\n");_profil();}
	
	if (atoi(argv[1])==1 && (atof(argv[2])>=1 || atof(argv[2])<=0 )) {	printf("> check p range\n");_profil();}// datenbereich p
	if (atoi(argv[1])==2 && atof(argv[2])<0){printf("> check F range\n"); _profil();} // datenbereich F
	
	P6 = atof(argv[2]);
	Q5 = atof(argv[3]);
	P5 = atof(argv[4]);

	_head();
   
	//-----------------------------------------------------------------------| Prozedur 
	if (atoi(argv[1]) == 1)//F(x=p)
	{	
		//*FP
		P6=1-P6;
		if (Q5 > 30 && P5 > 30)
		{
			//3000
			//*NP
			if(P6!=0.5)
			{
				if(P6>0.5) {QW1=1-P6;} else {QW1=P6;}

				QW1=-1*log(4*QW1*(1-QW1));
				QX44=(-3.231081277e-09*QW1+8.360937017e-08)*QW1-1.04527497e-06;
				QX44=(QX44*QW1+5.824238515e-06)*QW1+6.841218299e-06;
				QX44=((QX44*QW1-2.250947176e-04)*QW1-8.36435359e-04)*QW1+3.706987906e-02;
				QX=QX44*QW1+1.570796288;
				QX=sqrt(QW1*QX);
				if(P6>0.5) QX=QX*-1;

			}

			if(P6==0.5) QX=0; 
			//*NP end:
			
			if(R5==0)
			{
				QW1=2/9/Q5;
				QW2=2/9/P5;
				
				QW3=(1-QW1)*(1-QW2)+QX*sqrt(pow(1-QW1,2))*QW2+pow(1-QW2,2)*QW1-QW1*QW2*pow(QX,2);
				QX=pow(QW3/pow(1-QW2,2)-QW2*pow(QX,2),3);
			
			}// 3000 end
		}
		
		if (Q5 <= 30 || P5 <= 30)
		{

			QX1=0; QX2=1; QQ=0.5; QP=P6;
			
			M2950:
			QX=(1/QQ-1)*P5/Q5;

			//*FU
			QW1=P5/(P5+Q5*QX); QW2=sqrt(1-QW1);
			QMD=2*floor(Q5/2)-Q5+2;
			QND=2*floor(P5/2)-P5+2;

			if(QMD*2-QND == 1 )	{ P6=1-2/3.1417*atan(QW2/sqrt(QW1)); QW3=QW2*sqrt(QW1)/3.1417; } 
			if(QMD*2-QND == 2 )	{ P6=QW1; QW3=(1-QW1)*P6;}
			if(QMD*2-QND == 3 ) { P6=sqrt(QW1); QW3=(1-QW1)*P6/2; }			
			if(QMD*2-QND != 1 && QMD*2-QND != 2 && QMD*2-QND != 3 )	{ P6=1-QW2; QW3=QW1*QW2/2;	}

			//2800
			for(QIF=QND; QIF <= P5-2; QIF +=2) 
			{
				if(P5 > QIF || fabs(2/QIF*QW3) >= 0.00001*P6 )
				{ 			
					QJFU=QIF;
			
					P6=P6-2/QIF*QW3;
					QW3=QW3*QW1*(QMD/QIF+1);
				}
			}
			if(QJFU!=QIF) QJFU=QJFU+2;

			for(QIF=QMD; QIF <= Q5-2; QIF +=2) //2860
			{
				if(Q5 > QIF || fabs(2/QIF*QW3) >= (0.00001*P6) )
				{ 
					P6=P6+2/QIF*QW3;
					QW3=QW3*(1-QW1)*(QJFU/QIF+1);
				}
			}

			//2910 end *FU

			if(R5 == 0) //2990
			{
				if(P6<=QP) {QX1=QQ;} else {QX2=QQ;}
				QX0=QQ;QQ=(QX1+QX2)/2;
				if(fabs(QQ-QX0)>0.00001*QQ ) goto M2950;
				QX=(1/QQ-1)*P5/Q5; P6=QP;
			}
		}
			
		//end FP
		
		
		if(R5 == 0) 
		{
			QXQ=QX; QYQ=-5;
		
			if(QXQ !=0 )//*RNDN
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
						if (QZQ >= 90){ QXQ = QXQ * 1e-20; QFQ=QZQ; QZQ -= 20;}
						QWQ = sqrt(pow(QXQ*pow(10,(-1*QZQ)),2)); QWQ=floor(QWQ*pow(10,QYQ)+0.5);
						QWQ *= pow(10,QZQ)*pow(10,(-1*QYQ));
						if (QFQ >= 90) QWQ = QWQ * 1e+20;
						if (QXQ >= 0) QXQ = QWQ; 
						if (QXQ < 0) QXQ = -1*QWQ;
					}
				}
			}
			QX=QXQ;	printf(" p= %.3f, F(%i,%i)= %.3f\n", atof(argv[2]), atoi(argv[3]),atoi(argv[4]),QX);
		}

	}//end if argv[1]

	if (atoi(argv[1]) == 2)//F(y=F)
	{
		QX=P6;

		//*FU
		QW1=P5/(P5+Q5*QX); QW2=sqrt(1-QW1);
		QMD=2*floor(Q5/2)-Q5+2;
		QND=2*floor(P5/2)-P5+2;

		if(QMD*2-QND == 1 )	{ P6=1-2/3.1417*atan(QW2/sqrt(QW1)); QW3=QW2*sqrt(QW1)/3.1417; } 
		if(QMD*2-QND == 2 )	{ P6=QW1; QW3=(1-QW1)*P6;}
		if(QMD*2-QND == 3 ) { P6=sqrt(QW1); QW3=(1-QW1)*P6/2; }			
		if(QMD*2-QND != 1 && QMD*2-QND != 2 && QMD*2-QND != 3 )	{ P6=1-QW2; QW3=QW1*QW2/2;	}

		//2800
		for(QIF=QND; QIF <= P5-2; QIF +=2) 
		{
			if(P5 > QIF || fabs(2/QIF*QW3) >= (0.00001*P6) )
			{ 			
				QJFU=QIF;
			
				P6=P6-2/QIF*QW3;
				QW3=QW3*QW1*(QMD/QIF+1);
			}
		}
		if(QJFU!=QIF) QJFU=QJFU+2;
		

		for(QIF=QMD; QIF <= Q5-2; QIF +=2) //2860
		{
			if(Q5 > QIF || fabs(2/QIF*QW3) >= (0.00001*P6) )
			{ 
				P6=P6+2/QIF*QW3;
				QW3=QW3*(1-QW1)*(QJFU/QIF+1);
			}
		}

		if(R5 == 0) 
		{
			QXQ= P6; QYQ=-5;

			if(QXQ !=0 )//*RNDN
			{
				
				QFQ = log10(fabs(QXQ));
				QYQ=QFQ+QYQ; 
				if (QFQ >= 0) QFQ= floor(QFQ);		
				if (QFQ < 0)  QFQ= -1*(floor(fabs(QFQ)));
				QZQ=QFQ; QFQ=QYQ; 
				if (QFQ >= 0) QFQ= floor(QFQ);	
				if (QFQ < 0)  QFQ= -1*(floor(fabs(QFQ)));	
				QYQ=QZQ-QFQ-1;
				if (QYQ < 19 ) 
				{
					if (QYQ < 0 ) QXQ=0; 
					if (QYQ >=0 )
					{
						if (QZQ >= 90){ QXQ = QXQ * 1e-20; QFQ=QZQ; QZQ -= 20;}
						QWQ = sqrt(pow(QXQ*pow(10,(-1*QZQ)),2)); QWQ=floor(QWQ*pow(10,QYQ)+0.5);
						QWQ *= pow(10,QZQ)*pow(10,(-1*QYQ));
						if (QFQ >= 90) QWQ = QWQ * 1e+20;
						if (QXQ >= 0) QXQ = QWQ; 
						if (QXQ < 0) QXQ = -1*QWQ;
					}
				}
			}
			P6=QXQ; printf(" F(%i,%i)= %.3f, p= %.3f\n", atoi(argv[3]),atoi(argv[4]),atof(argv[2]),1-P6);
		}
	}	

	getch();

	return 0;
}

//---------------------------------------------------------------------------| funktionen                      
void _profil()
{
	printf("--------------------------------------\n");
	printf("Usage: F_Function [mode] [x] [n1] [n2]\n");
	printf(" [mode] .......... (1)Fx=p\x1A\x46 (2)Fy=F\x1Ap\n");
	printf(" [x] ................... p-Wert/F-Wert\n");
	printf(" [n1] ............................. n1\n");
	printf(" [n2] ............................. n2\n");
	printf("--------------------------------------\n");
	printf("F_Function by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);

	getch();

	exit(0);
}	

//---------------------------------------------------------------------------| titelzeile bildschirmausgabe                   
void _head() 
{
	printf("\nF_Function by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing F_Function:"); 
}

//---------------------------------------------------------------------------| ENDE          