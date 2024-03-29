//---------------------------------------------------------------------------| t_Function by Dietmar SCHRAUSSER 2009               //             //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void _profil(); 
void _head();                    

long double   t_wert/*QX*/, p_wert/*P6*/, n_/*Q5*/, n_O/*p5*/, OO[10], RD[10], iLauf, iLauf_1, n_Z, n_N;

main(int argc, char *argv[]) 
{    
	t_wert=RD[0]=RD[2]=RD[3]=RD[4]=iLauf_1=0; 
	
	OO[1]=OO[2]=OO[3]=OO[4]=OO[5]=OO[6]=OO[7]=RD[1]=RD[5]=1;

	if (argc != 4) 
	{
   		printf("> check arguments\n");
   	    _profil();
	}

	if (atoi(argv[1])==1 && (atof(argv[2])>=1 || atof(argv[2])<=0 )) // datenbereich
	{
   		printf("> check p range\n");
   		_profil();
	}

	if (atof(argv[2])==0 &&  stricmp(argv[2], "0") != 0  ) 
	{
   		printf("> check x value\n");
   		_profil();
	}
	
	_head();

	n_= atof(argv[3]);
   
	//-----------------------------------------------------------------------| Prozedur 
	if (atoi(argv[1]) == 1)//F(x=p)
	{		
		p_wert = atof(argv[2]);//p-wert eingabe	
		
		//t-Wert Berechnung
		//*NP
		if(p_wert!=0.5)
		{
			if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}

			OO[1]=-1*log(4*OO[1]*(1-OO[1]));
			OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
			OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
			OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
			t_wert=OO[2]*OO[1]+1.570796288;
			t_wert=sqrt(OO[1]*t_wert);
			if(p_wert>0.5) t_wert=t_wert*-1;
			}

		if(p_wert==0.5) t_wert=0; 

		//*TP
		if(RD[0] ==0)
		{
			OO[3]=pow(t_wert,2);
			OO[1]=t_wert+(1+OO[3])*t_wert/(4*n_)+((5*OO[3]+16)*OO[3]+3)*t_wert/(96*pow(n_,2));
			OO[1]=OO[1]+(((3*OO[3]+19)*OO[3]+17)*OO[3]-15)*t_wert/(384*pow(n_,3));
			OO[1]=OO[1]+((((79*OO[3]+776)*OO[3]+1482)*OO[3]-1920)*OO[3]-945)*t_wert/(92160*pow(n_,4));
			t_wert=OO[1]+(((((27*OO[3]+339)*OO[3]+930)*OO[3]-1782)*OO[3]-765)*OO[3]+17955)*t_wert/(368640*pow(n_,5));
		}


		if(RD[0]==0)
		{
			RD[1]=t_wert; RD[2]=-5;

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

			t_wert=RD[1]; printf(" p= %.3f, t(%.1f)= %.3f\n", atof(argv[2]), n_, t_wert*-1);//bildschirmausgabe
		}
	
	}//end if argv[1]

	if (atoi(argv[1]) == 2)//F(y=t)
	{
		t_wert = atof(argv[2]);//t-wert eingabe

		//Prozentrangberechnung
		//*TU
		
		if(n_ != floor(n_))
		{
			OO[6]=n_; n_=floor(OO[6]);
			n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);
		
 			//*FU
			OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);
			n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

			if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } 
			if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}
			if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }
			if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}

			for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
			{
				if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 			
					iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
					OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
				}
			}
			if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
		
			for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
			{
				if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 
					p_wert=p_wert+2/iLauf*OO[4];
					OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
				}
			}//*FU end
		
			if(RD[0] == 0)
			{
				p_wert=p_wert/2; n_=n_O;t_wert=OO[5];
				if(t_wert < 0) p_wert=1-p_wert;
		
				OO[7]=p_wert;
				n_=floor(OO[6])+1;
				n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);
		
 				//*FU
				OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);
				n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

				if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } 
				if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}
				if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }
				if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}

			
				for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
				{
					if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
					{ 			
						iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
						OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
					}
				}
				if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
		
				for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
				{
					if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
					{ 
						p_wert=p_wert+2/iLauf*OO[4];
						OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
					}
				}//*FU end

				if(RD[0] == 0)
				{
					p_wert=p_wert/2; n_=n_O; t_wert=OO[5];
					if(t_wert < 0) p_wert=1-p_wert;
				
					if(RD[0] == 0) 
					{
						p_wert=(p_wert-OO[7])*(OO[6]-floor(OO[6]))+OO[7]; n_=OO[6];
					}
				}
			}
		}

		if(n_ == floor(n_))
		{
			n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);
			
			//*FU
			OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);
			n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

			if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } //n=1
			if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}//n={}
			if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }//n={}
			if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}//n>1

		
			for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
			{
				if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 			
					iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
					OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
				}
			}
			if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
		
			for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
			{
				if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 
					p_wert=p_wert+2/iLauf*OO[4];
					OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
				}
			}//*FU end

			
			if(RD[0] == 0)
			{
				p_wert=p_wert/2; n_=n_O; t_wert=OO[5];
				if(t_wert < 0) p_wert=1-p_wert;
			}
		}


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

			
			p_wert=RD[1]; printf(" t(%.1f)= %.3f, p= %.3f\n", n_, atof(argv[2]), fabs(1-p_wert));//bildschirmausgabe
		}

	}//end if argv[1]
	
	getch();

	return 0;
}

//---------------------------------------------------------------------------| funktionen                      
void _profil()
{
	printf("---------------------------------\n");
	printf("Usage: t_Function [mode] [x] [n]\n");
	printf(" [mode] ..... (1)Fx=p\x1At (2)Fy=t\x1Ap\n");
	printf(" [x] ............ p-value/t-value\n");
	printf(" [n] ................. n of cases\n");
	printf("---------------------------------\n");
	printf("t_Function by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	getch();

	exit(0);
}	

//---------------------------------------------------------------------------| titelzeile bildschirmausgabe                   
void _head(void) 
{
	printf("\nt_Function by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing t_Function:"); 
}

//---------------------------------------------------------------------------| ENDE          