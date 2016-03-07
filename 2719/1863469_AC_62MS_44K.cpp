#include <iostream.h>
int power ( int a, int b )
{
	if ( b == 0 )
		return 1;
	int sum = 1;
	int i;
	for ( i = 0 ; i < b; i++ )
		sum *= a;
	return sum;
}
int f(char *a )
{
	int sum = 0;
	int i = 0;
	int max;
	while ( a[i] != NULL )
		i++;
	max = i;
	for ( i = 0; i < max; i++ )
	{
		if ( a[i] < '4' )
			sum += (a[i]-'0')*power(9,max-1-i);
		else
			sum += (a[i]-'1')*power(9,max-1-i );
	}
	return sum;
}
void main ()
{
	char n[12];
	while ( cin>>n && n[0] != '0' )
	{
		cout<<n<<": "<<f(n)<<endl;
	}
}
