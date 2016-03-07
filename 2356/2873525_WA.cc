#include <iostream>
using namespace std;
bool mod[11000];
int a[16000];
int main ()
{
	int flag=0,x,y;
	int n,i,sum=0;
	memset(mod,false,sizeof(mod));
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
		else if ( mod[sum] == true )
		{
			flag = 2;
			y = i;
		}
		else
		{
			mod[sum] = true;
			x = i;
		}
	}
	if ( flag == 0 )
		cout<<0<<endl;
	else if ( flag == 2 )
	{
		printf("%d\n",y-x+1);
		for ( i = x; i <= y; i++ )
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