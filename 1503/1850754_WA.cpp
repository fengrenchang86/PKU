#include <iostream.h>
void main ()
{
	int ans[200];
	char b[120];
	char a[120];
	int i;
	int j;
	int max1;
	int max2;
	cin>>a;
	for ( i = 0; i < 200 ; i++ )
		ans[i] = 0;
	while ( cin>>b && b[0] != '0' )
	{
		i = 0;
		while ( b[i] != NULL )
			i++;
		max2 = i;
		i = 0;
		while ( a[i] != NULL )
			i++;
		max1 = i;
		i = max1 > max2 ? max1 : max2;
		i--;
		while ( i>=0 )
		{
			a[i] = a[i] + b[i] - '0';
			i--;
		}
	}
	i = 0;
	while ( a[i] != NULL )
		i++;
	max1 = i;
	j = 0;
	for ( i = max1-1; i>=0; i-- )
		ans[j++] = a[i]-'0';
	i = 0;
	for ( i = 0; i < max1; i++ )
	{
		if ( ans[i] >= 10 )
		{
			ans[i+1] += ans[i]/10;
			ans[i] %= 10;
		}
	}
	if ( a[max1] > 0 )
		cout<<a[max1];
	for ( i = max1-1; i >=0 ; i-- )
		cout<<ans[i];
	cout<<endl;
		
}