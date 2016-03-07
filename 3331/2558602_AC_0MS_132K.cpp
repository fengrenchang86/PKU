#include <iostream>
using namespace std;
int cheng ( int a[], int size, int k )
{
	int i;
	a[size] = 0;
	for ( i = 0; i < size; i++ )
		a[i] *= k;
	for ( i = 0; i < size; i++ )
	{
		a[i+1] += a[i]/10000;
		a[i] %= 10000;
	}
	if ( a[size] != 0 )
		size++;
	return size;
}
int f ( int n, int dig )
{
	int c = 0;
	while ( n != 0 )
	{
		if ( n%10==dig)
			c++;
		n/=10;
	}
	return c;
}
int main ()
{
	int tcase,size,i,dig,count;
	int a[200];
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		memset(a,0,sizeof(a));
		scanf("%d%d",&a[0],&dig);
		size = 1;
		for ( i = a[0]-1; i >= 2; i-- )
			size = cheng(a,size,i);
		count = 0;
		if ( dig != 0 )
		{
			for ( i = 0; i < size; i++ )
				count+=f(a[i],dig);
		}
		else
		{
			for ( i = 0; i < size-1; i++ )
			{
				if ( a[i] == 0 )
					count+=4;
				else
				{
					count += f(a[i],dig);
					if ( a[i] < 10 )
						count += 3;
					else if ( a[i] < 100 )
						count += 2;
					else if ( a[i] < 1000 )
						count += 1;
				}
			}
			count += f(a[size-1],dig);
		}
		cout<<count<<endl;
	}
	return 0;
}