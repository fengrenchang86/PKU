#include <iostream>
using namespace std;
int main ()
{
	int list[3] = { 9,7,3 };
	int n;
	int i;
	int po;
	int j;
	int sum;
	char a[30];
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		sum = 0;
		scanf("%s",a);
		printf("Scenario #%d:\n",i);
		j = 0;
		while ( a[j] != '?' )
		{
			sum += (a[j]-'0')*list[j%3];
			j++;
		}
		po = j;
		j++;
		while ( a[j] != NULL )
		{
			sum += (a[j]-'0')*list[j%3];
			j++;
		}
		sum%=10;
		sum = 10 - sum;
		for ( j = 0; j <= 9; j++ )
		{
			if ( (j*list[po%3])%10 == sum )
				break;
		}
		sum = j;
		for ( j = 0; j < po; j++ )
			printf("%c",a[j]);
		printf("%d",sum);
		j++;
		while ( a[j] != NULL )
			printf("%c",a[j++]);
		printf("\n\n");
	}
	return 1;
}