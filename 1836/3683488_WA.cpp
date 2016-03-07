#include <iostream>
using namespace std;
int dA[2200];
int dB[2200];
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
	int nP,nMaxp,i,j,k=0,nX,dX=0;
	double dY;
	for ( i = 0; i < nN; i++ )
	{
		scanf("%lf",&dY);
		dA[i] = dY*10000;
		if ( dA[i] > dX )
		{
			dX = dA[i];
			nMaxp = i;
		}
	}
	dB[0] = dA[0];
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
	}
	if ( j > k )
		k = j;
	dB[0] = dA[0];
	j = 0;
	for ( i = 1; i < nN; i++ )
	{
		if ( dA[i] < dB[j] )
			dB[++j] = dA[i];
		else if ( dA[i] >= dB[0] )
			dB[0] = dA[i];
		else
		{
			nP = FromBig(0,j,dA[i]);
			dB[nP] = dA[i];
		}
	}
	if ( j > k )
		k = j;
	dB[0] = dA[0];
	j = 0;
	for ( i = 1; i <= nMaxp; i++ )
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
	}
	nX = j+1;
	j = 0;
	if ( nMaxp == nN-1 )
	{
		k++;
		printf("%d\n",nN-k);
		return 1;
	}
	dB[0] = dA[i];
	i++;
	while ( i < nN )
	{
		if ( dA[i] < dB[j] )
			dB[++j] = dA[i];
		else if ( dA[i] >= dB[0] )
			dB[0] = dA[i];
		else
		{
			nP = FromBig(0,j,dA[i]);
			dB[nP] = dA[i];
		}
		i++;
	}
	nX += (j+1);
	k++;
	if ( nN-k < nN-nX )
		printf("%d\n",nN-k);
	else
		printf("%d\n",nN-nX);
	return 0;
}