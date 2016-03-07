#include <iostream.h>
#include <string>
using namespace std;
void main ( )
{
	int ans = 0;
	int arr[26];
	int i;
	int count = 1;
	char s[255];
	for ( i = 0; i < 26; i++ )
		arr[i] = i+1;
	do
	{
	count = 1;
	ans = 0;
	cin.getline ( s, 255, '\n' );
	if ( s[0] == '#' )
		break;
	i = 0;
	while ( s[i] != NULL )
	{
		if ( s[i] >='A' && s[i] <= 'Z' )
			ans += ( arr[s[i]-'A'] * count);
		i++;
		count++;
	}
	cout<<ans<<endl;
	}while ( s[0] != '#' );
}