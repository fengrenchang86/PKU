#include <iostream.h>
void main ()
{
	int l;
	int m;
	int i;
	int a;
	int b;
	int sum;
	while ( cin>>l>>m && !(l==0 && m==0) )
	{
		sum = l+1;
		for ( i = 0; i < m; i++ )
		{
			cin>>a>>b;
			sum -= ( b-a+1);
		}
		cout<<sum<<endl;
	}

}