#include <iostream>
using namespace std;
int a[16000];
int b[16000];
int main ()
{
	int flag=0,x,y;
	int n,i,sum=0;
	memset(b,-1,sizeof(b));
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
		if ( flag != 0 )
			continue;
		sum += a[i];
		sum %= n;
		if ( sum == 0 )
		{
			flag = 1;
			x = i;
		}
		else if ( b[sum] != -1 )
		{
			flag = 2;
			x = b[sum];
			y = i;
		}
		else
		{
			b[sum] = i;
		}
	}
	if ( flag == 0 )
		cout<<0<<endl;
	else if ( flag == 2 )
	{
		printf("%d\n",y-x);
		for ( i = x+1; i <= y; i++ )
			printf("%d\n",a[i]);
	}
	else
	{
		printf("%d\n",x+1);
		for ( i = 0; i <= x; i++ )
			printf("%d\n",a[i]);
	}
	return 0;
}