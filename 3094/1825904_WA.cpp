#include <iostream.h>
#include <string>
using namespace std;
void main ( )
{
	int c = 0;
	int save[50];
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
	cin.clear();
	cin.getline ( s, 255, '\n' );
	if ( s[0] < 'A' || s[0] > 'Z' )
		continue;
	for ( i = 0; s[i] != NULL; i++ )
		;
	if ( s[i-1] < 'A' || s[i-1] > 'Z' )
		continue;
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
	save[c++] = ans;
	//cout<<ans<<endl;
	}while ( s[0] != '#' );
	for ( i = 0; i <= c-1; i++ )
		cout<<save[i]<<endl;
}