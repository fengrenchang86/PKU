#include <iostream.h>
#include <stdio.h>
void main ()
{
	int list[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
	char ch[10];
	int sum = 0;
	int i;
	int max = 0;
	while ( scanf( "%s", &ch) )
	{
		if ( ch[0] == '.' )
			break;
		sum = 0;
		for ( i = 0; ch[i] != NULL; i++ )
			sum+=list[ch[i]-'a'];
		if ( sum > max )
			max = sum;
	}
	cout<<max<<endl;
}