#include <iostream.h>
void main ()
{
	int n,m,p,c;
	int k;
	while (cin>>n>>m>>p>>c && n!=0 && m!= 0 && p!= 0 && c!= 0 )
	{
		k = p+n-m;
		cout<<k<<endl;
	}
}