#include <iostream>
#include <fstream>
using namespace std;
int a[30];
int b[60];
int main ()
{
	short v[100][100];
	char puta[200],putb[200];
//	fstream cin("in.txt");
	cin>>puta>>putb;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int i,j;
	i = 0;
	while ( puta[i] != NULL )
	{
		a[puta[i]-'A'+1]++;
		i++;
	}
	i = 0;
	while ( putb[i] != NULL )
	{
		b[putb[i]-'A'+1]++;
		i++;
	}
	for ( i = 27; i <= 52; i++ )
		b[i] = b[i-26];
	for ( i = 0; i < 100; i++ )
		v[i][0] = v[0][i] = 0;
	for ( i = 1; i <= 26; i++ )
	{
		for ( j = 1; j <= 52; j++ )
		{
			if ( a[i] == b[j] )
				v[i][j] = v[i-1][j-1] + 1;
			else
				v[i][j] = v[i][j-1]>v[i-1][j]?v[i][j-1]:v[i-1][j];
		}
	}
	if ( v[26][52] == 26 )
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}