#include <iostream>
using namespace std;
const short MAX = 401;
int main ()
{
	char a[MAX/2];
	char b[MAX/2];
	char c[MAX];
	int data;
	int h;
	int i;
	int j;
	int len1;
	int len2;
	int len;
	int cc = 1;
	while (cin>>data)
	{
//		cin>>data;
	for ( h = 0; h < data; h++ )
	{
		cin>>a>>b>>c;
		len1 = strlen(a);
		len2 = strlen(b);
		len = len1>len2?len1:len2;
		len2 = strlen(c);
		short *p = new short[128];
		for ( i = 0; i < 128; i++ )
			p[i] = 0;
		for ( i = 0; a[i]!=NULL; i++ )
			p[a[i]]++;
		for ( i = 0; b[i]!=NULL; i++ )
			p[b[i]]++;
		for ( i = 0; c[i]!=NULL; i++ )
			p[c[i]]--;
		for ( i = 0; i < 128; i++ )
		{
			if ( p[i] != 0 )
			{
				len = 0;
				cout<<"Data set "<<cc++<<": no"<<endl;
				break;
			}
		}
		if ( len == 0 )
			continue;
		short **t;
		t = new short *[len+1];
		for ( i = 0; i < len+1; i++ )
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
				cout<<"Data set "<<cc++<<": no"<<endl;
				continue;
			}
//		cout<<t[len1][len2]<<endl;
		len1 = strlen(b);
		for ( i = 0; i < len1+1; i++ )
			t[i][0] = 0;
		for ( j = 0; j < len2+1; j++ )
			t[0][j] = 0;
		for ( i = 0; i < len1; i++ )
			for ( j = 0; j < len2; j++ )
			{
				if ( b[i] == c[j] )
					t[i+1][j+1] = t[i][j] + 1;
				else
					t[i+1][j+1] = t[i][j+1]>t[i+1][j]?t[i][j+1]:t[i+1][j];
			}
		if ( t[len1][len2] != len1 )
			cout<<"Data set "<<cc++<<": no"<<endl;
		else
			cout<<"Data set "<<cc++<<": yes"<<endl;
//		cout<<p[len1][len2]<<endl;
	}
	}
	return 1;
}