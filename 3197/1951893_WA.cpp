#include <iostream>
#include <iomanip>
using namespace std;
int f ( int n )
{
	int c = 0;
	while ( n != 0 )
	{
		n /= 10;
		c++;
	}
	return c;
}
int make ( int m, int n, int a[] )
{
	int len = 0;
	int p;
	while ( n != 1 )
	{
		a[len++] = m/n;
		if ( m%n == 0 )
		{
			m/=n;
			n = 1;
			len --;
			break;
		}
		p = m;
		m = n;
		n = p%n;
	}
	a[len++] = m-1;
	return len;
}
int main ()
{
	int a[200];
	int list[200];
	int m,n;
	int len;
	int max;
	int i;
	int c = 1;
	while (scanf("%d %d",&m,&n) && !(m==0&&n==0) )
	{
		printf("Case %d:\n",c++);
		printf("%d / %d\n",m,n);
		len = make ( m,n,a );
		list[0] = f(a[0])+3;
		for ( i = 1; i < len; i++ )
			list[i] = list[i-1] + f(a[i]) + 3;
		max = list[i-1] + 1;
//		for ( i = 0; i < len; i++ )
//			printf("%d\n",a[i]);
//		printf("\n");
//		for ( i = 0; i < len; i++ )
//			printf("%d\n",list[i]);
//		printf("max is %d\n",max);
//		printf("the output:\n");
		for ( i = 0; i < len; i++ )
		{
			if ( i != len-1 )
				cout<<setw(list[i]+(max-list[i]+1)/2)<<setfill('.')<<1;
			else
				cout<<setw(max)<<setfill('.')<<1;
			if ( i!=len-1 )
				cout<<setw(max-1-(list[i]+(max-list[i]+1)/2)+1)<<setfill('.')<<'.';
			cout<<endl;
			if ( i != 0 )
				cout<<setw(list[i-1])<<setfill('.')<<'.'<<a[i];
			else
				cout<<a[i];
			cout<<".+.";
			if ( max-list[i] > 0 )
			cout<<setw(max-list[i])<<setfill('-')<<'-';
			cout<<endl;
		}
		cout<<setw(max)<<setfill('.')<<1<<endl;
	}
	return 1;
}