#include <iostream>
using namespace std;
int ctoi ( char *a, __int64 t[] )
{
	int i = 0, j = 0, k = 0,p=1;
	for ( j = 0; j < 10; j++ )
		t[j] = 0;
	j = 0;
	i = strlen(a)-1;
	while ( i >= 0 )
	{	
		if ( k == 7 )
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
	return j+1;
}
void putout ( __int64 t[], int size )
{
	printf("%I64d",t[size-1]);
	int i = size-2;
	while ( i >= 0 )
	{
		printf("%07I64d",t[i]);
		i--;
	}
	printf("\n");
}
bool div ( __int64 t[], int size, int k )
{
	__int64 c = 0;
	int i = size-1;
	while ( i >= 0 )
	{
		c *= 10000000;
		c += t[i];
		c %= k;
		i--;
	}
	if ( c == 0 )
		return true;
	else
		return false;
}
void divi ( __int64 t[], int size, int k )
{
	int i = size-1;
	__int64 c = 0;
	while ( i >= 0 )
	{
		c *= 10000000;
		c += t[i];
		c %= t[i];
		t[i] /= k;
		i--;
	}
}
int main ()
{
	char a[200];
	int k,i;
	__int64 t[10];
	int size;
	while ( cin>>a>>k && !(a[0]=='0'&&k==0) )
	{
		size = ctoi(a,t);
		for ( i = 2; i <= k; i++ )
		{
			if ( div(t,size,i) == true )
				break;
		}
		if ( i <= k )
		{
			divi(t,size,k);
			while ( t[size-1] == 0 && size-1 > 0 )
				size--;
			printf("BAD %d\n",i);
	//		putout(t,size);
		}
		else
			cout<<"GOOD"<<endl;
	}
	return 0;
}