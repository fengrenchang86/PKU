#include <iostream>
using namespace std;
char t[2000];
int acm ( )
{
	int i = strlen(t)-1;
	int j = 0;
	while ( i >= 0 )
	{
		if ( t[i] >= 'p' && t[i] <= 'z' )
			j++;
		else if ( t[i] == 'N' )
		{
			if ( j != 1 )
				return 0;
		}
		else if ( t[i] == 'C' || t[i] == 'D' || t[i] == 'E' || t[i] == 'I' )
		{
			if ( j != 2 )
				return 0;
			j = 1;
		}
		else
			return 0;
		i--;
	}
	if ( j == 1 )
		return 1;
	else
		return 0;
}
int main ()
{
	while ( cin>>t )
	{
		if ( acm() == 1 )
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}