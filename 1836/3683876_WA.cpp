#include <iostream>
using namespace std;
int dA[2200];
int dB[2200];
int nM[2200];
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
int FromBig ( int nBegin, int nEnd, int dX )
{
	if ( nBegin == nEnd )
		return nBegin;
	int nMid = (nBegin+nEnd)/2;
	if ( dB[nMid] == dX )
		return nMid;
	else if ( dB[nMid] > dX )
		return FromBig ( nMid+1, nEnd, dX );
	else
		return FromBig ( nBegin, nMid, dX );
}
int main ( )
{
	scanf("%d",&nN);
	int nP,nMaxNum,i,j,k=0,dX=0;
	double dY;
	for ( i = 0; i < nN; i++ )
	{
		scanf("%lf",&dY);
		dA[i] = dY*10000;
		if ( dA[i] > dX )
		{
			nMaxNum = 0;
			dX = dA[i];
			nM[nMaxNum] = dX;
		}
		else if ( dA[i] == dX )
			nM[++nMaxNum] = dX;
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
	if ( j > k )
		k = j;
	dB[0] = dA[0];
	j = 0;
	b[nN-1] = 1;
	for ( i = nN-2; i >= 0; i-- )
	{
		if ( dA[i] < dB[j] )
			dB[++j] = dA[i];
		else if ( dA[i] >= dB[0] )
			dB[0] = dA[i];
		else
		{
			nP = FromSmall(0,j,dA[i]);
			dB[nP] = dA[i];
		}
		b[i] = j+1;
	}
	k = 0;
	for ( i = 0; i < nN-2; i++ )
	{
		if ( a[i] != dX )
			continue;
		if ( a[i] + b[i+1] > k )
			k = a[i]+b[i+1];
	}
	printf("%d\n",nN-k);
	return 0;
}