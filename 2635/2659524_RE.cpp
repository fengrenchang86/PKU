#include <iostream>
using namespace std;
int make ( int p[] )
{
	int k = 2;
	p[0] = 2;
	p[1] = 3;
	int i,j;
	for ( i = 5; i < 1000000; i+=2 )
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
		if ( k == 8 )
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
	while ( t[j] == 0 )
		j--;
	return j+1;
}/*
void putout ( __int64 t[], int size )
{
	printf("%I64d",t[size-1]);
	int i = size-2;
	while ( i >= 0 )
	{
		printf("%08I64d",t[i]);
		i--;
	}
	printf("\n");
}*/
bool div ( int t[], int size, int k )
{
	__int64 c = 0;
	int i = size-1;
	while ( i >= 0 )
	{
		c *= 100000000;
		c += t[i];
		c %= k;
		i--;
	}
	if ( c == 0 )
		return true;
	else
		return false;
}
/*
void divi ( __int64 t[], int size, int k )
{
	int i = size-1;
	__int64 c = 0;
	while ( i >= 0 )
	{
		c *= 100000000;
		c += t[i];
		c %= t[i];
		t[i] /= k;
		i--;
	}
}*/
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
		{
//			divi(t,size,p[i]);
			printf("BAD %d\n",p[i]);
	//		putout(t,size);
		}
		else
			cout<<"GOOD"<<endl;
	}
	return 0;
}