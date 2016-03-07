#include <iostream>
using namespace std;
int f(int m,int n )
{
	int i;
	int ans = m;
	for ( i = 1; i < n; i++ )
	{
		ans *= (m-i);
		while ( ans%10==0 )
			ans/=10;
		ans%=10;
	}
	printf("%d\n",ans);
	return ans;
}
int main ()
{
	int m,n;
	int i;
	int ans;
	int a1;
	int a2;
	while ( scanf("%d %d",&m,&n)!=EOF )
	{
		a1 = n%10;
		a2 = (n-a1)/10;
//		a2 = a2%4;
		ans = m;
		if  (ans%10==0)
			ans = 1;
		for ( i = 1; i < a1; i++ )
		{
			if ( (m-i)%10==0) 
				continue;
			ans *= (m-i)%10;
			while( ans%10==0 )
				ans/=10;
			ans %= 10;
		}
		while ( ans%10==0)
			ans/=10;
		ans%=10;
		/*
		for ( i = 1; i <= a2; i++ )
		{
			ans *= 8;
			while ( ans%10 == 0 )
				ans/=10;
			ans %= 10;
		}*/
		if ( a2 != 0 )
		{
			if ( a2%4==0 )
				ans*=6;
			else if ( a2%4==1 )
				ans *= 8;
			else if ( a2%4==2 )
				ans *= 4;
			else
				ans *= 2;
			while ( ans%10==0 )
				ans/=10;
			ans%=10;
		}
		if ( n == 0 ||m==0 )
			ans = 1;
		printf("%d\n",ans);
	}
	return 1;
}