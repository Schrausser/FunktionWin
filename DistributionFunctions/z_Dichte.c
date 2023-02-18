//-----------------------------------------------------------------------------------------| z_Dichte (c) SCHRAUSSER 2009               //           
#include "z_Dichte.h"

void _profil();
void _head();

main(int argc, char *argv[])
{
	double wert, erg_;
	int f_= 0;

	if(argc < 3 || argc > 4) _profil();
	if(argc ==4) f_=atoi(argv[3]);

	_head();

	wert=atof(argv[2]);

	if(atoi(argv[1]) == 1) // z -> d
	{
		erg_=dz_funktion(wert);printf("\nz(%g) d= %.5g\n", wert, erg_);
		if(f_ == 1) z_graph(erg_, erg_, 1);
	}
	if(atoi(argv[1]) == 2) // d -> z
	{
		erg_=zd_funktion(wert, 1);
		if(f_ == 1) z_graph(wert, erg_, 2);
	}
	if(atoi(argv[1]) == 3) // z -> p
	{
		erg_=pz_funktion(wert, 1); if(wert==0)fn_erg=0.5; printf("\nz(%g) p= %.5g\n", wert, fn_erg);
		if(f_ == 1) z_graph(dz_funktion(wert), erg_, 3);
	}

	if(atoi(argv[1]) == 4) // p -> z
	{
		erg_=zp_funktion(wert, 1); 
		//if(f_ == 1) z_graph(dz_funktion(wert), erg_, 3);
	}

	if(atoi(argv[1]) == 5) // p -> d
	{
		erg_=dp_funktion(wert); printf("\np(%g) d= %.5g\n", wert, fn_erg);
		//if(f_ == 1) z_graph(dz_funktion(wert), erg_, 3);
	}
	
	if(atoi(argv[1]) == 6) // d -> p
	{
		erg_=pz_funktion(wert, 2); printf("\nd(%g) p(-z)= %.2g(%.2g), 1-p=p(+z)= %.3g\n", wert, fn_erg, (ceil(2*(100*fn_erg)))/100, 1-fn_erg);
		//if(f_ == 1) z_graph(dz_funktion(wert), erg_, 3);
	}
	
	getch();

	return 0;	
}

             
void _profil()
{
	int iLauf;
	printf("\n");
	for(iLauf=1; iLauf<=52; iLauf++) cprintf("\xC4"); printf("\n");
	printf("Gebrauch: z_Dichte [modus] [wert] [[f]]\n");
	printf(" [modus] ............. (1)fx=z\x1A\x64 (2)fy=d\x1Az (3)\x9Fx=z\x1Ap\n");
	printf("                       (4)\x9F'p\x1Az  (5)\x9F'p\x1A\x64  (6)\x9Fy=d\x1Ap\n");
	printf(" [wert] .............. z-Wert/z-Dichte/Prozentrang p\n");
	printf(" [f] .................... (1)z-Dichte Funktionsgraph\n");
	for(iLauf=1; iLauf<=52; iLauf++) cprintf("\xC4"); printf("\n");
	printf("z_Dichte von Dietmar Schrausser, (c) SCHRAUSSER 2009\n");
    printf("compiliert am %s @ %s\n", __DATE__, __TIME__);
	
	getch();
	
	exit(0);
}	
                 
void _head() 
{
	printf("\nz_Dichte von Dietmar Schrausser, (c) SCHRAUSSER 2009\n");
	printf("compiliert am %s @ %s\n", __DATE__, __TIME__);
	printf("berechne z_Dichte:\n"); 
}