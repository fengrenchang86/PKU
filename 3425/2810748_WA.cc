#include <iostream>
using namespace std;
struct ac
{
	bool correct;
	bool expl;
	ac(){correct=expl=false;}
}a[1000100];
int main ()
{
	int n,x,y,z,i,sum=0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		sum += 10;
		if ( a[x].correct == false && y == 1 )
		{
			a[x].correct = true;
			sum += 10;
		}
		if ( a[x].expl == false && z == 1 && y==1 )
		{
			a[x].expl = true;
			sum += 40;
		}
	}
	cout<<sum<<endl;
	return 0;
}