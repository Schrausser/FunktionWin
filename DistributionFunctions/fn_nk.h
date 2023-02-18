//-------------------------------------------------------------------------------------------| fn_nk by Dietmar Schrausser, (c) SCHRAUSSER 2009
//                                                                                           | Funktion n über k
double fn_erg;

double fn_nk(double n, double k)// n über k //
{
	double iLauf, n_=1, n_1=1, n_2=1, k_=1, k_1=1, k_2=1, nk=1, F;

	if(n>268){printf(" bad n 'n>268'\n");exit(0);}

	fn_erg=1;F=pow(10,300);if (n-k>k) k=n-k;
	
	if (n<=170)for(iLauf = 1; iLauf <= n; iLauf++)   n_ *= iLauf;
	if (n>170)
	{
		for(iLauf = 1; iLauf <= floor(n/2); iLauf++)n_1 *= iLauf; n_1=n_1/F;
		for(iLauf = iLauf; iLauf <= n; iLauf++)n_2 *= iLauf; n_2=n_2/F;
		n_=n_1*n_2;
	}
	
	if (k<=170)for(iLauf = 1; iLauf <= k; iLauf++)   k_ *= iLauf;
	if (k>170)
	{
		for(iLauf = 1; iLauf <= floor(k/2); iLauf++)k_1 *= iLauf; k_1=k_1/F;
		for(iLauf = iLauf; iLauf <= k; iLauf++)k_2 *= iLauf; k_2=k_2/F;
		k_=k_1*k_2;
	}
	
	for(iLauf = 1; iLauf <= n-k; iLauf++) nk *= iLauf;

	if (n<=170 ||(n>170 && k>170)) fn_erg= n_/(k_*nk);
	if (n>170 && k<=170) fn_erg= (n_*F)/(((k_/F)*(nk)));
	
	return fn_erg;
};