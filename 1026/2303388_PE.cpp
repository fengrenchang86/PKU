#include <iostream>
using namespace std;
int main ()
{
	int v[210];
	bool visit[210];
	int a[210];
	char ch[210];
	char out[210];
	int n,i,j,r,c,t,count,len;
	while ( cin>>n && n != 0 )
	{
		for ( i = 1; i <= n; i++ )
			cin>>a[i];
		for ( i = 1; i <= n; i++ )
			visit[i] = false;
		c = 0;
		while ( c < n )
		{
			i = 1;
			while ( i <= n )
			{
				if ( visit[i] == false )
					break;
				i++;
			}
			t = i;
			count = 0;
			while ( visit[i] == false )
			{
				visit[i] = true;
				i = a[i];
				c++;
				count++;
			}
			v[t] = count;
			i = a[t];
			while ( i != t )
			{
				v[i] = count;
				i = a[i];
			}
		}
		while ( cin >> t && t != 0 )
		{
			cin.ignore();
			cin.getline(out,250,'\n');
			len = strlen(out);
			i = len;
			while ( i < n )
			{
				out[i] = ' ';
				i++;
			}
			out[i] = NULL;
			for ( i = 0; i < n; i++ )
				ch[i+1] = out[i];
			ch[i+1] = NULL;
			for ( i = 1; i <= n; i++ )
			{
				j = i;
				r = t;
				r %= v[j];
				c = 0;
				while ( c < r )
				{
					j = a[j];
					c++;
				}
				out[j] = ch[i];
			}
			j = n;
			while ( out[j] == ' ' )
				j--;
			for ( i = 1; i <= n; i++ )
				cout<<out[i];
			cout<<endl;
		}
	}
	return 0;
}