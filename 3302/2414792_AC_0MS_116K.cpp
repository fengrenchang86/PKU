#include <iostream>
using namespace std;
int main ()
{
	char a[120],b[120];
	int i,j,k,tcase;
	cin>>tcase;
	while ( tcase )
	{
		cin>>a>>b;
		i = j = k = 0;
		while ( a[i] != NULL )
		{
			if ( a[i] == b[j] )
				j++;
			i++;
			if ( b[j] == NULL )
			{
				k = 1;
				break;
			}
		}
		if ( k == 0 )
		{
			i = 0;
			j = strlen(b)-1;
			while ( a[i] != NULL )
			{
				if ( a[i] == b[j] )
					j--;
				i++;
				if ( j < 0 )
				{
					k = 1;
					break;
				}
			}
		}
		if ( k == 1 )
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		tcase--;
	}
	return 0;
}