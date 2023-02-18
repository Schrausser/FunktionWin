//---------------------------------------------------------------------------| epsilon by Dietmar SCHRAUSSER 2010               //             //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include "fn_t.h"

void _profil();
void _head(); 
                  
main(int argc, char *argv[]) 
{    
	FILE *outstream;
	
	int mode, n_, df_, iLauf;
	double q0_, s_, sg_, e_, q1_, p_, x_,  sm_, tx_, tx2_,nopt_, ep_, txca_, txcb_,xca_, xcb_;
	double t_q1, p_q1, swx_, ani_, bni_, imb_, topt_, popt_, sk;

	char dbuffer[9], tbuffer[9];

	if(argc > 9 || argc < 8) _profil();

	_head(); 

	mode =   atoi(argv[1]);
	n_ =     atoi(argv[4]);
	df_= n_- atoi(argv[7]);

	q0_ = atof(argv[2]);
	s_  = atof(argv[3]);

	if(mode ==1) e_ =  atof(argv[5]);
	if(mode ==2) q1_ = atof(argv[5]);

	p_ = atof(argv[6]);

	if(argc == 9) x_ =  atof(argv[8]);

	sg_=s_*(1.0*n_/(n_-1));
	sm_= sqrt(pow(sg_,2)/n_);

	if(mode ==1)q1_ = e_*sg_ + q0_; // Theta 1

	if(mode ==2)e_ = (q1_-q0_)/sg_; // effect-size epsilon


	                    txca_= tp_funktion(p_, df_);

	      if(q0_ > q1_) txca_=-txca_;
    xca_=           q0_+txca_*sm_; //critical x alpha
          
						txcb_= tp_funktion(p_, df_);
		  if(q0_ < q1_) txcb_=-txcb_;
	xcb_=           q1_+txcb_*sm_; //critical x beta
                        
	if(argc == 9)
	{
		                  tx_= (x_-q0_)/sm_;
		ani_= pt_funktion(tx_, df_);if(q0_ < x_) ani_=1-ani_; // alpha level of x
						  tx2_= (x_-q1_)/sm_;
		bni_= pt_funktion(tx2_, df_);if(q1_ < x_) bni_=1-bni_; // beta level of x
		imb_= pt_funktion(tx2_, df_); imb_ = 1-imb_;           // power
	}

						fn_erg= tp_funktion(p_, df_);
	nopt_=      (pow(2* fn_erg, 2))/pow(e_,2); // optimal n
	ep_=   sqrt((pow(2* fn_erg, 2))/n_); // effect-power ep
	if(e_<0) ep_ = -ep_;
	
	                     topt_=sqrt(pow(e_,2)*n_)/2;
	popt_= pt_funktion(  topt_, df_);popt_ = 1-popt_;// optimal alpha level
	            if(e_<0) topt_ = -topt_;
	                        
	if(q0_ < q1_) swx_ = q0_+ (sqrt(pow(e_,2)*n_)/2)*sm_; // threshold x
	if(q0_ > q1_) swx_ = q0_- (sqrt(pow(e_,2)*n_)/2)*sm_;

	//t-values
	//q1
	t_q1= (q1_-q0_)/sm_; p_q1= pt_funktion( t_q1 , df_);if(p_q1 > 0.5)p_q1 = 1-p_q1;
	
	//screen output
	printf ("\n\nTheta\n");
	for(iLauf=1; iLauf <39; iLauf++) printf ("\x5f");printf ("\n");
	printf ("\t=\tseg\ts\tsg\n");
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xc4");printf ("\n");
	printf ("Q0\t%.2f\t(%.2f)\t%.2f\t(%.2f)\n",                           q0_, sm_, s_, sg_ );
	printf ("Q1\t%.2f\t--\t--\t--\n",                                 q1_               );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xee");printf ("\n");
	printf ("p-level= %.2f\n",                                                            p_ );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\x5f");printf ("\n");
    printf ("\t=\topt(%.2f)\t\xf1\n",                                                     p_ );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xc4");printf ("\n");
	printf ("n\t%i\t%.0f\t\t%.0f\n",                                   n_, nopt_, n_-nopt_ );
	printf ("e\t%.3f\t%.3f\t\t%.3f\n",                              e_, ep_,   e_ -ep_  );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xee");printf ("\n");
	printf ("n/e "); 
                         sk=14*(n_/nopt_);if(sk<1) sk=1; if(sk>27)sk=27;
	for(iLauf=1; iLauf <=sk; iLauf++) printf ("\xfe");if(sk==27) printf ("\x10");printf ("\n"); 
	printf ("                 \x1e\n");      
	printf ("    |............p............|\n\n");

	printf ("n= %.i / e= %.3f\n",            n_, e_ );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\x5f");printf ("\n");
    printf ("\t=\topt(%i)\t\xf1\n",                                                       n_ );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xc4");printf ("\n");
	printf ("p\t%.3f\t%.3f\t\t%.3f\n",                           p_, 1-popt_, p_-(1-popt_));
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xee");printf ("\n");
	printf ("p   "); 
                         sk=28-14*(n_/nopt_);if(sk<1) sk=1; if(sk>27)sk=27;
	for(iLauf=1; iLauf <=sk; iLauf++) printf ("\xfe");if(sk==27) printf ("\x10");printf ("\n"); 
	printf ("                 \x1e\n");       
	printf ("    |...........n/e...........|\n\n");
	printf ("alpha-level\n");
	for(iLauf=1; iLauf <39; iLauf++) printf ("\x5f");printf ("\n");
	printf ("q\t=\tt(%i)\talpha\t1-a\n",                                                   df_ );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xc4");printf ("\n");
	printf ("Q0\t%.2f\t0.000\t0.500\t0.500\n",                  q0_                         );
	printf ("crit\t%.2f\t%.3f\t%.3f\t%.3f\n",                   swx_, topt_, popt_, 1-popt_ );
	printf ("crit(p)\t%.2f\t%.3f\t%.3f\t%.3f\n",                 xca_, txca_, 1-p_,  p_      );
	printf ("Q1\t%.2f\t%.3f\t%.3f\t%.3f\n",                     q1_,  t_q1,  p_q1,  1-p_q1  );
	if(argc == 9)
	printf ("x\t%.2f\t%.3f\t%.3f\t%.3f\n",                      x_,   tx_,   ani_,  1-ani_  );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xee");printf ("\n");
	printf ("beta-level\n");
	for(iLauf=1; iLauf <39; iLauf++) printf ("\x5f");printf ("\n");
	printf ("q\t=\tt(%i)\tbeta\t1-b\n",                                                      df_ );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xc4");printf ("\n");
	printf ("Q1\t%.2f\t0.000\t0.500\t0.500\n",                  q1_                            );
	printf ("crit\t%.2f\t%.3f\t%.3f\t%.3f\n",                   swx_, topt_*-1, popt_, 1-popt_ );
	printf ("crit(p)\t%.2f\t%.3f\t%.3f\t%.3f\n",                 xcb_, txcb_,    1-p_,  p_      );
	printf ("Q0\t%.2f\t%.3f\t%.3f\t%.3f\n",                     q0_,  t_q1*-1,  p_q1,  1-p_q1  );
	if(argc == 9)
	printf ("x\t%.2f\t%.3f\t%.3f\t%.3f\n",                      x_,   tx2_,     bni_,  imb_    );
	for(iLauf=1; iLauf <39; iLauf++) printf ("\xee");printf ("\n");
	printf ("df= n-%i\n\n", atoi(argv[7]));

	printf ("e: Effect-size epsilon, where epsilon\n   is defined by e= (Q1-Q0)/sg\n1-b: Power\n");


	//file output

	outstream = fopen( "epsilon_log.txt", "a" );

	_strdate( dbuffer );_strtime( tbuffer );
	fprintf(outstream,"epsilon (c) SCHRAUSSER 2010; %s %s;\n\n", dbuffer , tbuffer);
	fprintf(outstream,"Theta\n");
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"_");fprintf(outstream,"\n");
	fprintf(outstream,"\t=\tseg\ts\tsg\n");
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"\x97");fprintf(outstream,"\n");
	fprintf(outstream,"Q0\t%.2f\t(%.2f)\t%.2f\t(%.2f)\n",                           q0_, sm_, s_, sg_ );
	fprintf(outstream,"Q1\t%.2f\t--\t--\t--\n",                                 q1_               );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"¯");fprintf(outstream,"\n");
	fprintf(outstream,"p-level= %.2f\n",                                                            p_ );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"_");fprintf(outstream,"\n");
    fprintf(outstream,"\t=\topt(%.2f)\t\xb1\n",                                                     p_ );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"\x97");fprintf(outstream,"\n");
	fprintf(outstream,"n\t%i\t%.0f\t\t%.0f\n",                                   n_, nopt_, n_-nopt_ );
	fprintf(outstream,"e\t%.3f\t%.3f\t\t%.3f\n",                              e_, ep_,   e_ -ep_  );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"¯");fprintf(outstream,"\n");
	fprintf(outstream,"n/e "); 
                         sk=14*(n_/nopt_);if(sk<1) sk=1; if(sk>27)sk=27;
	for(iLauf=1; iLauf <=sk; iLauf++) fprintf(outstream,"\x95");if(sk==27)fprintf(outstream,">");fprintf(outstream,"\n");
	fprintf(outstream,"                 ^\n");       
	fprintf(outstream,"    |............p............|\n\n");

	fprintf(outstream,"n= %.i / e= %.3f\n",            n_, e_ );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"_");fprintf(outstream,"\n");
    fprintf(outstream,"\t=\topt(%i)\t\xb1\n",                                                       n_ );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"\x97");fprintf(outstream,"\n");
	fprintf(outstream,"p\t%.3f\t%.3f\t\t%.3f\n",                           p_, 1-popt_, p_-(1-popt_));
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"¯");fprintf(outstream,"\n");
	fprintf(outstream,"p   "); 
	                     sk=28-14*(n_/nopt_);if(sk<1) sk=1; if(sk>27)sk=27;
	for(iLauf=1; iLauf <=sk; iLauf++) fprintf(outstream,"\x95");if(sk==27) fprintf(outstream,">");fprintf(outstream,"\n");
	fprintf(outstream,"                 ^\n");       
	fprintf(outstream,"    |...........n/e...........|\n\n");
	fprintf(outstream,"alpha-level\n");
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"_");fprintf(outstream,"\n");
	fprintf(outstream,"q\t=\tt(%i)\talpha\t1-a\n",                                                   df_ );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"\x97");fprintf(outstream,"\n");
	fprintf(outstream,"Q0\t%.2f\t0.000\t0.500\t0.500\n",                  q0_                         );
	fprintf(outstream,"crit\t%.2f\t%.3f\t%.3f\t%.3f\n",                   swx_, topt_, popt_, 1-popt_ );
	fprintf(outstream,"crit(p)\t%.2f\t%.3f\t%.3f\t%.3f\n",                 xca_, txca_, 1-p_,  p_      );
	fprintf(outstream,"Q1\t%.2f\t%.3f\t%.3f\t%.3f\n",                     q1_,  t_q1,  p_q1,  1-p_q1  );
	if(argc == 9)
	fprintf(outstream,"x\t%.2f\t%.3f\t%.3f\t%.3f\n",                      x_,   tx_,   ani_,  1-ani_  );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"¯");fprintf(outstream,"\n");
	fprintf(outstream,"beta-level\n");
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"_");fprintf(outstream,"\n");
	fprintf(outstream,"q\t=\tt(%i)\tbeta\t1-b\n",                                                      df_ );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"\x97");fprintf(outstream,"\n");
	fprintf(outstream,"Q1\t%.2f\t0.000\t0.500\t0.500\n",                  q1_                            );
	fprintf(outstream,"crit\t%.2f\t%.3f\t%.3f\t%.3f\n",                   swx_, topt_*-1, popt_, 1-popt_ );
	fprintf(outstream,"crit(p)\t%.2f\t%.3f\t%.3f\t%.3f\n",                 xcb_, txcb_,    1-p_,  p_      );
	fprintf(outstream,"Q0\t%.2f\t%.3f\t%.3f\t%.3f\n",                     q0_,  t_q1*-1,  p_q1,  1-p_q1  );
	if(argc == 9)
	fprintf(outstream,"x\t%.2f\t%.3f\t%.3f\t%.3f\n",                      x_,   tx2_,     bni_,  imb_    );
	for(iLauf=1; iLauf <39; iLauf++) fprintf(outstream,"¯");fprintf(outstream,"\n");
	fprintf(outstream,"df= n-%i\n\n", atoi(argv[7]));

	fprintf(outstream,"e: Effect-size epsilon, where epsilon\n   is defined by e= (Q1-Q0)/sg\n1-b: Power\n");
	fprintf(outstream,"\n\n\n\n");
	   
	fclose(outstream);

	getch();

	return 0;
}

void _profil()
{
	printf("\n---------------------------------------------------------\n");
	printf("Usage: epsilon [mode] [Q0] [s] [n] [e|Q1] [p] [df] [[x]]\n");
	printf(" [mode] ...................... (1)Effect-size (2)Theta.1\n");
	printf(" [Q0] .......................................... Theta.0\n");
	printf(" [s] ................................ Standard deviation\n");
	printf(" [n] ........................................ n of cases\n");
	printf(" [e|Q1] .............................. Epsilon | Theta.1\n");
	printf(" [p] .............................. Percent-level (0.00)\n");
	printf(" [df] ....................... Degrees of freedom n - (.)\n");
	printf(" [x] ........................................ Test value\n");
	printf("---------------------------------------------------------\n");
	printf("epsilon by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	getch();
	
	exit(1);
}

void _head(void) 
{
	printf("\nepsilon by Dietmar Schrausser, (c) SCHRAUSSER 2010\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing epsilon:"); 
}	

   

   