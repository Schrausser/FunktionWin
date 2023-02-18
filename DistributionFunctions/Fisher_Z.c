//---------------------------------------------------------------------------| Fisher_Z by Dietmar SCHRAUSSER 2009               //             //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

void _err_msg()
{
	printf("\n---------------------------------\n");
	printf("Usage: Fisher_Z [mode] [x]\n");
	printf(" [mode] ......... (1)\x9Fr\x1AZ (2)\x9FZ\x1Ar\n");
	printf(" [x] ............ r-value/Z-value\n");
	printf("---------------------------------\n");
	printf("Fisher_Z by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	
	getch();
	
	exit(1);
}

void _head(void) 
{
	printf("\nFisher_Z by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing Fisher_Z:"); 
}	
                    
main(int argc, char *argv[]) 
{    
	long double val, fn_erg, euler=2.7182818284590452353602874713527;

	if(argc == 1 || argc > 3) _err_msg();
	if(atoi(argv[1]) != 1 && atoi(argv[1]) != 2 ){printf ("\nmode.0");_err_msg();}
	if(atoi(argv[1]) == 1 && (atof(argv[2]) >= 1 ||  atof(argv[2]) <= -1) ){printf ("\n-1<r<1 .0");_err_msg();}
	
	val = atof(argv[2]);
	
	_head();
	
	if (atoi(argv[1]) == 1) 
	{
		fn_erg = 0.5 * log( (1 + val) / (1 - val));
		printf( " Z(%.3f) = %f\n", val, fn_erg);
	}

	if (atoi(argv[1]) == 2)
	{
		val = 2*val; fn_erg = (pow(euler,val ) - 1) / (pow(euler,val ) + 1);	
		printf( " r(%.3f) = %f\n", val/2, fn_erg);
	}
	
	getch();

	return 0;
}

       