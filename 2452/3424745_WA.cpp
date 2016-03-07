#include <iostream>
#include <math.h>
using namespace std;
int MinRMQ[51000][20];
int MaxRMQ[51000][20];
int Arr[51000];
int Power[20];
int n;
int GetMin ( int x, int y )
{
	return x < y ? x:y;
}
int GetMax ( int x, int y )
{
	return x > y ? x:y;
}
void input()
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&Arr[i]);
		MinRMQ[i][0] = Arr[i];
		MaxRMQ[i][0] = Arr[i];
	}
}
void init ()
{
	int i;
	Power[0] = 1;
	for ( i = 1; i < 20; i++ )
		Power[i] = Power[i-1]*2;
}
void solve ()
{
	int i,j;
	for ( j = 1; j < 17; j++ )
	{
		for ( i = 0; i + Power[j] - 1 < n; i++ )
		{
			MinRMQ[i][j] = GetMin(MinRMQ[i][j-1],MinRMQ[i+Power[j-1]][j-1]);
			MaxRMQ[i][j] = GetMax(MaxRMQ[i][j-1],MaxRMQ[i+Power[j-1]][j-1]);
		}
	}
}
int RMQmin ( int x, int y )
{
	int k = log10(double(y-x+1))/log10(2.0);
	return GetMin(MinRMQ[x][k],MinRMQ[y-Power[k]+1][k]);
}
int RMQmax ( int x, int y )
{
	int k = log10(double(y-x+1))/log10(2.0);
	return GetMax(MaxRMQ[x][k],MaxRMQ[y-Power[k]+1][k]);
}
int Check ( int p )
{
	int begin = p;
	int end = n-1;
	int mid = (begin+end)/2;
	while ( begin < end )
	{
		if ( RMQmin(p,mid)==Arr[p] && RMQmax(p,mid)==Arr[mid] )
			begin = mid+1;
		else
			end = mid;
		mid = (begin+end)/2;
	}
	if ( RMQmin(p,mid)==Arr[p] && RMQmax(p,mid)==Arr[mid] && p!=mid)
		return mid-p;
	else
		return mid-1-p;
}
void LastRun ( )
{
	int ans = -2;
	int i,k;
	for ( i = 0; i < n; i++ )
	{
		k = Check(i);
		if ( k == 0 )
			k = -1;
		if ( k > ans )
			ans = k;
	}
	printf("%d\n",ans);
}
int main ()
{
	init();
	while ( scanf("%d",&n) != EOF )
	{
		input();
		solve();
		LastRun();
	}
	return 0;
}