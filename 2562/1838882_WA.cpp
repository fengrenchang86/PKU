#include <iostream.h>
void main ()
{
	char a[10];
	char b[10];
	int i;
	int c;
	int e1;
	int e2;
	while(cin>>a>>b && (a[0] !='0' || b[0]!= '0'))
	{
		c = 0;
		i = 0;
		while ( a[i] != NULL)
			i++;
		e1 = i - 1;
		i = 0;
		while ( b[i] != NULL )
			i++;
		e2 = i - 1;
		while ( e1 > 0 && e2 >0 )
		{
			if ( a[e1] + b[e2] - 96 >=10 )
			{
				c++;
				a[e1-1]++;
			}
			e1--;
			e2--;
		}
		if ( a[e1] + b[e2] - 96>=10 )
			c++;
		if ( c == 0)
			cout<<"No carry operation."<<endl;
		else if ( c== 1 )
			cout<<"1 carry operation."<<endl;
		else
			cout<<c<<" carry operations."<<endl;
	}
}