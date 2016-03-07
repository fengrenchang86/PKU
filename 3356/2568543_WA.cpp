#include <iostream>
using namespace std;
int min ( int a, int y )
{
	return a<y?a:y;
}
int min ( int a, int b, int c )
{
	return min(min(a,b),min(b,c));
}
int main ()
{
	int len1,len2;
	char a[500000],b[500000];
	cin>>len1>>a;
	cin>>len2>>b;
	int i,j,c[2][500001];
	for ( i = 0; i <= 500000; i++ )
		c[0][i] = 0;
	for ( i = 0; i < len1; i++ )
	{
		c[(i+1)%2][0] = 0;
		for ( j = 0; j < len2; j++ )
		{
			if ( a[i] == b[j] )
				c[(i+1)%2][j+1] = min(c[i%2][j],c[i%2][j+1]+1,c[i%2][j]+1);
			else
				c[(i+1)%2][j+1] = min(c[(i+1)%2][j]+1,c[i%2][j+1]+1,c[i%2][j]+1);
		}
	}
	cout<<c[len1%2][len2]<<endl;
	return 0;
}
