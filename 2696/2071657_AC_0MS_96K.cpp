#include <iostream>
using namespace std;
int a,b,c,d,e,f,g,h;
int main ()
{
	int v[1200];
	int tcase,it;
	int i,j;
	cin>>tcase;
	for ( it = 0; it < tcase; it++ )
	{
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
		v[0] = a;
		v[1] = b;
		v[2] = c;
		for ( j = 3; j <= i; j++ )
		{
			if ( j % 2 == 0 )
				v[j] = ((f*v[j-1])%h-(d*v[j-2])%h+(e*v[j-3])%h+1000*h)%h;
			else
				v[j] = ((d*v[j-1])%g+(e*v[j-2])%g-(f*v[j-3])%g+1000*g)%g;
		}
		cout<<v[i]<<endl;
	}
	return 0;
}