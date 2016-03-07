#include <iostream>
using namespace std;
int make ( int p[] )
{
	int k = 2;
	p[0] = 2;
	p[1] = 3;
	int i,j;
	for ( i = 5; i < 1000102; i+=2 )
	{
		for ( j = 3; j*j <= i; j+=2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
			p[k++] = i;
	}
	return k;
}
int ctoi ( char *a, int t[] )
{
	int i = 0, j = 0, k = 0,p=1;
	for ( j = 0; j < 20; j++ )
		t[j] = 0;
	j = 0;
	i = strlen(a)-1;
	while ( i >= 0 )
	{	
		if ( k == 9 )
		{
			k = 0;
			j++;
			p = 1;
		}
		t[j] += p*(a[i]-'0');
		p*=10;
		k++;
		i--;
	}
	while ( t[j] == 0 && j >= 0 )
		j--;
	return j+1;
}
bool div ( int t[], int size, int k )
{
	__int64 c = 0;
	int i = size-1;
	while ( i >= 0 )
	{
		c *= 1000000000;
		c += t[i];
		c %= k;
		i--;
	}
	if ( c == 0 )
		return true;
	else
		return false;
}
int main ()
{
	char a[200];
	int k,i;
	int t[30];
	int size;
	int p[80000];
	int sizep = make(p);
	while ( cin>>a>>k && !(a[0]=='0'&&k==0) )
	{
		size = ctoi(a,t);
		for ( i = 0; p[i] < k; i++ )
		{
			if ( div(t,size,p[i]) == true )
				break;
		}
		if ( p[i] < k )
			printf("BAD %d\n",p[i]);
		else
			cout<<"GOOD"<<endl;
	}
	return 0;
}