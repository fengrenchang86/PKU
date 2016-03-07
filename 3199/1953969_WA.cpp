#include <iostream>
#include <iomanip>
using namespace std;
/*
int main ()
{
	int a[100];
	int d;
	int n;
	int i;
	int j;
	int end;
	while ( scanf("%d %d",&d,&n) && !(d==0&&n==0) )
	{
		for ( i = 0; i < 30; i++ )
			a[i] = 0;
		a[0] = 1;
		end = 0;
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j <= end; j++ )
				a[j] *= d;
			for ( j = 0; j <= end; j++ )
			{
				a[j+1] += a[j]/10000;
				a[j] %= 10000;
			}
			if ( a[end]>0 )
				end++;
		}
		i = end;
		while ( a[i]==0 )
			i--;
		cout<<a[i];
		while ( i-- )
			cout<<setw(4)<<setfill('0')<<a[i];
		cout<<endl;
	}
	return 1;
}
*/
void main ()
{
	int a,b;
	_int64 m = 1;
	int i;
	char c[1000];
	while ( scanf("%d %d",&a,&b) && !(a==0&&b==0) )
	{
		m = 1;
		for ( i = 0; i < b; i++ )
			m *= a;
		_i64toa(m,c,10);
		printf("%s\n",c);
	}
}