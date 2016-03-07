#include <iostream>
using namespace std;
bool a[1000100]={false};
bool b[1000100]={false};
bool c[1000100]={false};
int main ()
{
	int n,x,y,z,i,sum;
	while ( scanf("%d",&n) !=EOF )
	{
		sum = 0;
		memset(a,false,sizeof(a));
		memset(b,false,sizeof(b));
		memset(c,false,sizeof(c));
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&x,&y,&z);
			if ( y == 0 )
			{
				sum += 10;
				continue;
			}
			if ( a[x] == true )
			{
				if ( c[x] == false )
				{
					sum += 10;
					c[x] = true;
				}
		//		if ( z == 1 && b[x] == false )
				if ( z == 1 )
				{
					sum += 40;
					b[x] = true;
				}
			}
			if ( a[x] == false )
			{
				if ( z == 0 )
					sum += 20;
				else
					sum += 40;
			}
			a[x] = true;
		}
	cout<<sum<<endl;
	}
	return 0;
}