#include <iostream.h>
void main ()
{
	char input[30];
	int a[26] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
	int i;
	int j;
	while ( cin>>input )
	{
		if ( a[input[0]-'A'] != 0 )
			cout<<a[input[0]-'A'];
		for ( i = 1; input[i] != NULL; i++ )
		{
			if ( a[input[i]-'A'] != a[input[i-1]-'A'] && a[input[i]-'A'] !=0  )
				cout<<a[input[i]-'A'];
		}
		cout<<endl;
	}
}