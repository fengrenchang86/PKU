#include <iostream>
using namespace std;
const short MAX = 100;
int main ()
{
	char a[MAX];
	char b[MAX];
	char c[MAX];
	int data;
	int h;
	int i;
	int j;
	int len1;
	int len2;
	cin>>data;
	for ( h = 0; h < data; h++ )
	{
		cin>>a>>b>>c;
		len1 = strlen(a);
		len2 = strlen(c);
		short **t;
		t = new short *[len1+1];
		for ( i = 0; i < len1+1; i++ )
			t[i] = new short[len2+1];
		for ( i = 0; i < len1+1; i++ )
			t[i][0] = 0;
		for ( j = 0; j < len2+1; j++ )
			t[0][j] = 0;
		for ( i = 0; i < len1; i++ )
			for ( j = 0; j < len2; j++ )
			{
				if ( a[i] == c[j] )
					t[i+1][j+1] = t[i][j] + 1;
				else
					t[i+1][j+1] = t[i][j+1]>t[i+1][j]?t[i][j+1]:t[i+1][j];
			}
			if ( t[len1][len2]!=len1 )
			{
				cout<<"no"<<endl;
				continue;
			}
//		cout<<t[len1][len2]<<endl;
		len1 = strlen(b);
		short **p;
		p = new short *[len1+1];
		for ( i = 0; i < len1+1; i++ )
			p[i] = new short[len2+1];
		for ( i = 0; i < len1+1; i++ )
			p[i][0] = 0;
		for ( j = 0; j < len2+1; j++ )
			p[0][j] = 0;
		for ( i = 0; i < len1; i++ )
			for ( j = 0; j < len2; j++ )
			{
				if ( b[i] == c[j] )
					p[i+1][j+1] = p[i][j] + 1;
				else
					p[i+1][j+1] = p[i][j+1]>p[i+1][j]?p[i][j+1]:p[i+1][j];
			}
		if ( p[len1][len2] != len1 )
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
//		cout<<p[len1][len2]<<endl;
	}
	return 1;
}