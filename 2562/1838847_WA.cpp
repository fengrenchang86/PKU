#include <iostream.h>
void main ()
{
	char a[10];
	char b[10];
	int i;
	int j;
	int c;
	while(cin>>a>>b && a[0] !='0' && b[0]!= '0')
	{
		c = 0;
		i = 0;
		while ( a[i] != NULL && b[i] != NULL )
			i++;
		j = i - 1;
		while ( j >0 )
		{
			if ( a[j] + b[j] - 96 >=10 )
			{
				c++;
				a[j-1]++;
			}
			j--;
		}
		if ( a[j] + b[j] - 96>=10 )
			c++;
		if ( c == 0)
			cout<<"No carry operation."<<endl;
		else
			cout<<c<<" carry operation."<<endl;
	}
}