//---------------------------------------------------------------------------| x2_Function by Dietmar SCHRAUSSER 2009, 2010               //             //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void profil(); 
void _head();                    

long double   x2_wert/*QX*/, p_wert/*P6*/, n_/*Q5*/, n_O/*p5*/, x2[10], OO[10], RD[10], QIOS, QIF, QF, iLauf, hoch;

main(int argc, char *argv[]) 
{    
	x2_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; 
	
	OO[1]=OO[2]=OO[3]=OO[4]=RD[1]=RD[5]=QF=1;

	if (argc != 4) 
	{
   		printf("> check arguments\n");
   		profil();
	}
	if (atoi(argv[1]) > 2  || atoi(argv[1]) < 1 ) // modus bereich
	{
   		printf("> check mode\n");
   		profil();
	}

	if (atoi(argv[1])==1 && (atof(argv[2])>=1 || atof(argv[2])<=0 )) // datenbereich p
	{
   		printf("> check p range\n");
   		profil();
	}

	if (atoi(argv[1])==2 && atof(argv[2])<0) // datenbereich x2
	{
   		printf("> check x\xFD range\n");
   		profil();
	}

	if (atof(argv[2])==0 &&  stricmp(argv[2], "0") != 0  ) 
	{
   		printf("> check x value\n");
   		profil();
	}
	
	_head();

	n_= floor(atof(argv[3]));
   
	//-----------------------------------------------------------------------| Prozedur 
	if (atoi(argv[1]) == 1)//F(x=p)
	{		
		p_wert = atof(argv[2]);//p-wert eingabe	
		
		//t-Wert Berechnung
		//*CP
		if(n_==1)
		{
			OO[3]=p_wert; p_wert=p_wert/2;
		
			//*NP
			//if(p_wert!=0.5)
			//{
				if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}
				OO[1]=-1*log(4*OO[1]*(1-OO[1]));
				OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
				OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
				OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
				x2_wert=OO[2]*OO[1]+1.570796288;
				x2_wert=sqrt(OO[1]*x2_wert);
				if(p_wert>0.5) x2_wert = x2_wert * -1;
			//}
			//*NP end

			if(RD[0]==0)
			{
				x2_wert=pow(x2_wert,2);
				p_wert=OO[3];
			}
		}
 
		if(n_==2) x2_wert=-2*log (p_wert);
	
		if(n_!=1 && n_!=2)
		{
			x2[1]=0; x2[2]=1; x2[3]=0.5; x2[4]=p_wert;
			M2410:
			x2_wert=1/x2[3]-1; 
			
			//*CU
			OO[3]=x2_wert;
			if(x2_wert==0) p_wert=1;
			if(n_>40 && x2_wert!=0)
			{
				OO[4]=2/(9*n_); x2_wert=(pow(x2_wert/n_,0.333)-1+OO[4])/sqrt(OO[4]);
			
				//*NU
				OO[1] = fabs(x2_wert);
				if(OO[1]>7) p_wert=0; 
				if(OO[1]<=7)
				{
					p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
					p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
					p_wert=0.5*pow(p_wert,-16);
				}
				if (x2_wert<0) p_wert=1-p_wert;
				//*NU end

				if(RD[0]==0) x2_wert=OO[3];
			}
		
			if(n_<=40 && x2_wert!=0)
			{
				QIOS=2-floor(n_)+2*floor(floor(n_/2));//{qios: qios=1, n ungerade; qios=2, n gerade}
				OO[4]=sqrt(x2_wert);
		
				if (QIOS!=1)//n gerade
				{
					hoch=((-1*x2_wert)/2); p_wert=pow(2.718281828,hoch);
		
					QF=p_wert/2;
					if(QIOS>n_-1) x2_wert=OO[3];//n=2, hier nie der fall da if (n!=2) 
				
					if(QIOS<=n_-1)
					{
						for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
						{
							QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
						}
					}
				}
		
				if(QIOS==1)//n ungerade
				{
					x2_wert=OO[4];
			
					//*NU
					OO[1] = fabs(x2_wert);
					if(OO[1]>7) p_wert=0; 
					if(OO[1]<=7)
					{
						p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
						p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
						p_wert=0.5*pow(p_wert,-16);
					}
					if (x2_wert<0) p_wert=1-p_wert;
					//*NU end
			

					if(RD[0]==0)
					{
						p_wert=2*p_wert;
						hoch=(-1*OO[3]/2);QF=0.3989422804*pow(2.718281828,hoch)/OO[4];
					}
					if(QIOS<=n_-1)
					{
						for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
						{
							QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
						}
					}
				}
				x2_wert=OO[3];
			}
			//*CU end

			if(RD[0]==0)
			{
				if(p_wert<=x2[4]) {x2[1]=x2[3];} else {x2[2]=x2[3];}
				x2[0]=x2[3]; x2[3]=(x2[1]+x2[2])/2; 
				if(fabs(x2[3]-x2[0])>0.00001*x2[3]) goto M2410;							
				x2_wert=1/x2[3]-1; p_wert=x2[4];
			}
		}

		if(RD[0]==0)
		{
			RD[1]=x2_wert; RD[2]=-4;

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

			x2_wert=RD[1]; printf(" p= %.3f, x\xFD(%.0f)= %.3f\n", atof(argv[2]), n_, x2_wert);//bildschirmausgabe
		}
	
	}//end if argv[1]

	if (atoi(argv[1]) == 2)//F(y=t)
	{
		x2_wert = atof(argv[2]);//t-wert eingabe

		//Prozentrangberechnung
		//*CU
		OO[3]=x2_wert;
		if(x2_wert==0) p_wert=1;
		if(n_>40 && x2_wert!=0)
		{
			OO[4]=2/(9*n_); x2_wert=(pow(x2_wert/n_,0.333)-1+OO[4])/sqrt(OO[4]);
			
			//*NU
			OO[1] = fabs(x2_wert);
			if(OO[1]>7) p_wert=0; 
			if(OO[1]<=7)
			{
				p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
				p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
				p_wert=0.5*pow(p_wert,-16);
			}
			if (x2_wert<0) p_wert=1-p_wert;
			//*NU end

			if(RD[0]==0) x2_wert=OO[3];
		}
		
		if(n_<=40 && x2_wert!=0)
		{
			QIOS=2-floor(n_)+2*floor(floor(n_/2));
			OO[4]=sqrt(x2_wert);
		
			if (QIOS!=1)//n gerade
			{
				hoch=((-1*x2_wert)/2); p_wert=pow(2.718281828,hoch);
		
				QF=p_wert/2;
				if(QIOS>n_-1) x2_wert=OO[3];
				
				if(QIOS<=n_-1)
				{
					for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
					{
						QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
					}
				}
			}
		
			if(QIOS==1)//n ungerade
			{
				x2_wert=OO[4];
			
				//*NU
				OO[1] = fabs(x2_wert);
				if(OO[1]>7) p_wert=0; 
				if(OO[1]<=7)
				{
					p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
					p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
					p_wert=0.5*pow(p_wert,-16);
				}
				if (x2_wert<0) p_wert=1-p_wert;
				//*NU end
			
				if(RD[0]==0)
				{
					p_wert=2*p_wert;
					hoch=(-1*OO[3]/2);QF=0.3989422804*pow(2.718281828,hoch)/OO[4];
				}
				if(QIOS<=n_-1)
				{
					for(iLauf=QIOS; iLauf <= (n_-1); iLauf +=2)
					{
						QF=QF*OO[3]/iLauf; p_wert=p_wert+2*QF;
					}
				}
			}
			x2_wert=OO[3];
		}

		if(RD[0]==0)
		{
			RD[1]=p_wert; RD[2]=-5;

			//Kurvenglättung
			if(RD[1] !=0 )
			{
				RD[3] = log10(fabs(RD[1]));
				//RD[2]=RD[3]+RD[2]; 
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

			p_wert=RD[1]; printf(" x\xFD(%.0f)= %.3f, p= %.3f\n", n_, atof(argv[2]), 1-p_wert);//bildschirmausgabe
		}

	}//end if argv[1]

	getch();
	
	return 0;
}

//---------------------------------------------------------------------------| funktionen                      
void profil()
{
	printf("----------------------------------\n");
	printf("Usage: x2_Function [mode] [x] [n]\n");
	printf(" [mode] .... (1)Fx=p\x1Ax\xFD (2)Fy=x\xFD\x1Ap\n");
	printf(" [x] ............ p-value/x\xFD-value\n");
	printf(" [n] .................. n of cases\n");
	printf("----------------------------------\n");
	printf("x2_Function by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	getch();
	
	exit(0);
}	

//---------------------------------------------------------------------------| titelzeile bildschirmausgabe                   
void _head() 
{
	printf("\nx2_Function by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing x2_Function:"); 
}

//---------------------------------------------------------------------------| ENDE          