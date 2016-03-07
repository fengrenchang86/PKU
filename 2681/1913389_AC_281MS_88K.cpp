#include <iostream>
using namespace std;
int main ()
{
	int t[26];
	int n;
	int sum;
	char a[100];
	char b[100];
	scanf("%d",&n);
	int i;
	int j;
	cin.ignore();
	for ( i = 0; i < n; i++ )
	{
		sum = 0;
		for ( j = 0; j < 26; j++ )
			t[j] = 0;
		cin.getline ( a, 100, '\n' );
		cin.getline ( b, 100, '\n' );
		for ( j = 0; a[j] != NULL; j++ )
			t[a[j]-'a'] ++;
		for ( j = 0; b[j] != NULL; j++ )
			t[b[j]-'a'] --;
		for ( j = 0; j < 26; j++ )
		{
			if ( t[j] > 0 )
				sum += t[j];
			else
				sum -= t[j];
		}
		printf("Case #%d:  %d\n",i+1,sum);
	}
	return 1;
}