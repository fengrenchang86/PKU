#include <iostream>
using namespace std;
int main ()
{
	int list[3] = { 9,3,7 };
	int n;
	int i;
	int po;
	int j;
	int sum;
	int len;
	int c;
	char a[30];
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		sum = 0;
		scanf("%s",a);
		for ( j = 0; a[j] != NULL; j++ );
		len = j;
		j--;
		c = 0;
		printf("Scenario #%d:\n",i);
		while ( a[j] != '?' )
		{
			sum += (a[j]-'0')*list[c%3];
			j--;
			c++;
		}
		po = c;
		c++;
		j--;
		while ( j>=0 )
		{
			sum += (a[j]-'0')*list[c%3];
			j--;
			c++;
		}
		sum%=10;
		sum = 10 - sum;
		for ( j = 0; j <= 9; j++ )
		{
			if ( (j*list[po%3])%10 == sum )
				break;
		}
		sum = j;
		for ( j = 0; a[j]!='?'; j++ )
			printf("%c",a[j]);
		printf("%d",sum);
		j++;
		while ( a[j] != NULL )
			printf("%c",a[j++]);
		printf("\n");
		if ( i != n )
			printf("\n");
	}
	return 1;
}