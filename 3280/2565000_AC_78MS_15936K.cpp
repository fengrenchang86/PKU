#include <iostream>
using namespace std;
int c[2010][2010];
int v[2010];
int min ( int x, int y )
{
	return x < y ? x:y;
}
int min ( int x, int y, int z )
{
	return min(min(x,y),min(y,x));
}
int main ()
{
	int n,len,i,j,x,y;
	char ch[2010];
	char cf[2010];
	char word;
	int list[26];
	scanf("%d%d",&n,&len);
	cin>>ch;
	for ( i = 0; i < len; i++ )
		cf[len-i-1] = ch[i];
	cf[len] = NULL;
	for ( i = 0; i < n; i++ )
	{
		cin>>word>>x>>y;
		list[word-'a'] = min(x,y);
	}
	c[0][0] = 0;
	for ( i = 0; i < len; i++ )
	{
		c[0][i+1] = c[0][i]+list[cf[i]-'a'];
		c[i+1][0] = c[i][0]+list[ch[i]-'a'];
	}
	x = c[0][len];
	for ( i = 0; i < len; i++ )
	{
		for ( j = 0; j < len; j++ )
		{
			if ( ch[i] == cf[j] )
				c[i+1][j+1] = c[i][j];
			else
				c[i+1][j+1] = min(c[i+1][j]+list[cf[j]-'a'],c[i][j+1]+list[ch[i]-'a']);
		}
		if ( c[i+1][j] < x )
			x = c[i+1][j];
	}
	cout<<c[len][len]/2<<endl;
	return 0;
}
