#include <iostream>
using namespace std;
int c[310][310];
int len;
char ch[310];
int f ( int pos, char *a, int &end )
{
	int len1 = strlen(a);
	int i = pos, j = 0;
	while ( ch[i] != NULL && a[j] != NULL )
	{
		if ( ch[i] == a[j] )
			j++;
		i++;
	}
	if ( a[j] == NULL )
	{
		end = i-1;
		return i-pos-len1;
	}
	else
	{
		end = pos;
		return 1;
	}
}
char input[610][310];
int main ()
{
	int v[310];
	int end;
	int n,i,j,k;
	cin>>n>>len;
	cin>>ch;
	for ( i = 0; i < n; i++ )
		cin>>input[i];
	v[len] = 0;
	for ( i = len-1; i>=0; i-- )
	{
		v[i] = v[i+1]+1;
		for ( j = 0; j < n; j++ )
		{
			k = f(i,input[j],end);
			if ( v[i] > k+v[end+1] )
				v[i] = k+v[end+1];
		}
	}
	cout<<v[0]<<endl;
	return 0;
}