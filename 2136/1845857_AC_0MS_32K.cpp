#include <iostream.h>
void main ()
{
	int a[26];
	int i;
	int j;
	int max = 0;
	char in[4][80];
	
	for ( i = 0; i < 26; i++ )
		a[i] = 0;
	for  ( i = 0; i < 4; i++ )
	{
		cin.getline (in[i],80);
		for ( j = 0; in[i][j] != NULL; j++ )
		{
			if ( in[i][j] >= 'A' && in[i][j] <= 'Z' )
				a[in[i][j]-'A']++;
		}
	}
	for ( i = 0; i < 26; i++ )
		if ( a[i] > max )
			max = a[i];
	for ( i = max; i > 0; i-- )
	{
		for ( j = 0; j < 26; j++ )
		{
			if ( a[j] >= i )
				cout<<"* ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}
	for ( i = 0; i < 26; i++ )
		cout<<char(i+'A')<<" ";
	cout<<endl;

}