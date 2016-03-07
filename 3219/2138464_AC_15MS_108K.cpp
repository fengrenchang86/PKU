#include <iostream>
using namespace std;
int main ()
{
	int n,k;
	int a,b,c;
	int s1,s2;
	int i;
	double t[40];
	t[0] = 1;
	for ( i = 1; i <= 35; i++ )
		t[i] = t[i-1]*2;
	while ( scanf("%d%d",&n,&k) != EOF )
	{
		s1 = 0;
		s2 = 0;
		a = n;
		b = k;
		c = n-k;
		for ( i = 1; i <= 32; i++ )
		{
			s1 += a/t[i];
			s2 += b/t[i];
			s2 += c/t[i];
		}
		if ( s1 > s2 )
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}