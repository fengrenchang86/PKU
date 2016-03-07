#include <iostream.h>
#include <string>
using namespace std;
void main ( )
{
	int c = 0;
	int ans = 0;
	int arr[26];
	int i;
	int count = 1;
	char s[255];
	for ( i = 0; i < 26; i++ )
		arr[i] = i+1;
	do
	{
	ans = 0;
	cin.getline ( s, 255, '\n' );
	if ( s[0] == '#' )
		break;
	i = 0;
	while ( s[i] != NULL )
	{
		if ( s[i] >='A' && s[i] <= 'Z' )
			ans += ( arr[s[i]-'A'] * (i+1));
		i++;
	}
	cout<<ans<<endl;
	}while ( s[0] != '#' );

}