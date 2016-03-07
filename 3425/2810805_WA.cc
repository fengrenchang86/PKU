#include <iostream>
using namespace std;
int main ()
{
	int n,x,y,z,i,sum=0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		sum += 10;
		if ( z == 1 && y==1 )
			sum += 40;
		else if ( y== 1 )
			sum += 10;
	}
	cout<<sum<<endl;
	return 0;
}