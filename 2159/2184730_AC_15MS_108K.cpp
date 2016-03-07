#include <iostream>
#include <fstream>
using namespace std;
int a[30];
int b[60];
int main ()
{
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
	int k;
	for ( i = 1; i < 26; i++ )
	{
		for ( j = i+1; j <= 26; j++ )
		{
			if ( a[i] < a[j] )
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
			if ( b[i]  < b[j] )
			{
				k = b[i];
				b[i] = b[j];
				b[j] = k;
			}
		}
	}
	j = 0;
	for ( i = 1; i <= 26; i++ )
	{
		if ( a[i] != b[i] )
		{
			j = 1;
			break;
		}
	}
	if ( j == 0 )
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}