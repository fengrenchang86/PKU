#include <iostream>
using namespace std;
int dA[2200];
int dB[2200];
int a[2200];
int b[2200];
int nN;
int FromSmall ( int nBegin, int nEnd, int dX )
{
	if ( nBegin == nEnd )
		return nBegin;
	int nMid = (nBegin+nEnd)/2;
	if ( dB[nMid] == dX )
		return nMid;
	else if ( dB[nMid] < dX )
		return FromSmall ( nMid+1, nEnd, dX );
	else
		return FromSmall ( nBegin, nMid, dX );
}
void dp ()
{
	int i,j;
	a[0] = 1;
	for ( i = 1; i < nN; i++ )
	{
		a[i] = 1;
		for ( j = 0; j < i; j++ )
		{
			if ( dA[i] > dA[j] && a[i] < a[j]+1 )
				a[i] = a[j]+1;
		}
	}
	b[nN-1] = 1;
	for ( i = nN-2; i >= 0; i-- )
	{
		b[i] = 1;
		for ( j = nN-1; j > i; j-- )
		{
			if ( dA[i] > dA[j] && b[i] < b[j]+1 )
				b[i] = b[j]+1;
		}
	}
}
int main ( )
{
	scanf("%d",&nN);
	int nP,i,j,k=0,dX=0;
	double dY;
	for ( i = 0; i < nN; i++ )
	{
		scanf("%lf",&dY);
		dA[i] = dY*100000;
	}
	dB[0] = dA[0];
	a[0] = 1;
	j = 0;
	for ( i = 1; i < nN; i++ )
	{
		if ( dA[i] > dB[j] )
			dB[++j] = dA[i];
		else if ( dA[i] <= dB[0] )
			dB[0] = dA[i];
		else
		{
			nP = FromSmall(0,j,dA[i]);
			dB[nP] = dA[i];
		}
		a[i] = j+1;
	}
	dB[0] = dA[nN-1];
	j = 0;
	b[nN-1] = 1;
	for ( i = nN-2; i >= 0; i-- )
	{
		if ( dA[i] > dB[j] )
			dB[++j] = dA[i];
		else if ( dA[i] <= dB[0] )
			dB[0] = dA[i];
		else
		{
			nP = FromSmall(0,j,dA[i]);
			dB[nP] = dA[i];
		}
		b[i] = j+1;
	}

	//1.86 1.86 1.30621 2 1.4 1 1.97 2.2 2.1
	//3 4 5 1 2 5 4 3

//	dp();
	k = b[0] > a[nN-1] ? b[0]:a[nN-1];
	for ( i = 0; i <= nN-2; i++ )
	{
		if ( a[i] + b[i+1] > k )
			k = a[i]+b[i+1];
	}
	printf("%d\n",nN-k);
	return 0;
}