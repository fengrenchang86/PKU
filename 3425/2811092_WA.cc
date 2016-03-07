#include <iostream>
using namespace std;
bool a[1000100]={false};
bool b[1000100]={false};
int main ()
{
	int n,x,y,z,i,sum=0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		if ( y == 0 )
		{
			sum += 10;
			continue;
		}
		if ( b[x] == false && a[x] == true )
		{
			b[x] = false;
			sum += 10;
			if ( z == 1 )
				sum += 40;
		}
		else if ( a[x] == false )
		{
			a[x] = true;
			if ( z == 0 )
				sum += 20;
			else
				sum += 40;
		}
		else
			sum += 10;
	}
	cout<<sum<<endl;
	return 0;
}