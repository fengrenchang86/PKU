#include <iostream>
using namespace std;
bool a[1000100]={false};
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
		if ( y==1 && a[x]==true )
			sum += 10;
		if ( y==1 && z==1)
			sum += 40;
		else if ( y== 1 && a[x] == false )
		{
			sum += 20;
			a[x] = true;
		}
	}
	cout<<sum<<endl;
	return 0;
}