#include <iostream>
#include <string>
using namespace std;
bool visit[30];
bool v[30];
int letter[30];
bool vl[10];
int n;
bool flag;
char a[100],b[100],c[100],d[100];
void init ()
{
	flag = false;
	char ch[10000];
	memset(visit,false,sizeof(visit));
	memset(vl,false,sizeof(vl));
	memset(v,false,sizeof(v));
	cin>>ch;
	int i,j,k;
	for ( i = 0; ch[i] != NULL; i++ )
	{
		if ( ch[i] >= 'A' && ch[i] <= 'Z' )
			v[ch[i]-'A'] = true;
	}
	i = 0;
	j = 0;
	while ( ch[i] != '+' && ch[i] != '-' )
		a[j++] = ch[i++];
	a[j] = NULL;
	n = j;
	for ( j = 0; j < n; j++ )
		d[j] = a[n-j-1];
	d[j] = NULL;
	strcpy(a,d);
	if ( ch[i] == '+' )
		k = 1;
	else
		k = -1;
	i++;
	j = 0;
	while ( ch[i] != '=' )
		b[j++] = ch[i++];
	n = j;
	for ( j = 0; j < n; j++ )
		d[j] = b[n-j-1];
	d[j] = NULL;
	strcpy(b,d);
	b[j] = NULL;
	i++;
	j = 0;
	while ( ch[i] != NULL )
		c[j++] = ch[i++];
	c[j] = NULL;
	n = j;
	for ( j = 0; j < n; j++ )
		d[j] = c[n-j-1];
	d[j] = NULL;
	strcpy(c,d);
	if ( k == -1 )
	{
		strcpy(d,a);
		strcpy(a,c);
		strcpy(c,d);
	}
	n = 0;
	if ( strlen(a) > n )
		n = strlen(a);
	if ( strlen(b) > n )
		n = strlen(b);
	if ( strlen(c) > n )
		n = strlen(c);
	n++;
	for ( i = strlen(a); i < n; i++ )
		a[i] = '0';
	a[i] = NULL;
	for ( i = strlen(b); i < n; i++ )
		b[i] = '0';
	b[i] = NULL;
	for ( i = strlen(c); i < n; i++ )
		c[i] = '0';
	c[i] = NULL;
}
bool isdig ( char ch )
{
	if (ch >= '0' && ch <= '9' )
		return true;
	else
		return false;
}
void dfs ( int lay, int jin )
{
	if ( lay == n )
	{
		flag = true;
		return;
	}
	int i,j,k;
	if ( !isdig(a[lay]) && visit[a[lay]-'A'] == false )
	{
		visit[a[lay]-'A'] = true;
		for ( i = 0; i < 10; i++ )
		{
			if ( vl[i] == true )
				continue;
			vl[i] = true;
			letter[a[lay]-'A'] = i;
			if ( !isdig(b[lay]) && visit[b[lay]-'A'] == false )
			{
				visit[b[lay]-'A'] = true;
				for ( j = 0; j < 10 ; j++ )
				{
					if ( vl[j] == true )
						continue;
					vl[j] = true;
					letter[b[lay]-'A'] = j;
					if ( !isdig(c[lay]) && visit[c[lay]-'A'] == false )
					{
						visit[c[lay]-'A'] = true;
						for ( k = 0; k < 10; k++ )
						{
							if ( vl[k] == true )
								continue;
							vl[k] = true;
							letter[c[lay]-'A'] = k;
							if ( (i+j+jin)%10 == k )
							{
								dfs(lay+1,(i+j+jin)/10);
								if ( flag == true )
									return;
							}
							vl[k] = false;
						}
						visit[c[lay]-'A'] = false;
					}
					else
					{
						if ( isdig(c[lay]) )
							k = c[lay]-'0';
						else
							k = letter[c[lay]-'A'];
						if ( (i+j+jin)%10 == k )
						{
							dfs(lay+1,(i+j+jin)/10);
							if ( flag == true )
								return;
						}
					}
					vl[j] = false;
				}
				visit[b[lay]-'A'] = false;
			}
			else
			{
				if ( isdig(b[lay]) )
					j = b[lay]-'0';
				else
					j = letter[b[lay]-'A'];
				if ( !isdig(c[lay]) && visit[c[lay]-'A'] == false )
				{
					visit[c[lay]-'A'] = true;
					for ( k = 0; k < 10; k++ )
					{
						if ( vl[k] == true )
							continue;
						vl[k] = true;
						letter[c[lay]-'A'] = k;
						if ( (i+j+jin)%10 == k )
						{
							dfs(lay+1,(i+j+jin)/10);
							if ( flag == true )
								return;
						}
						vl[k] = false;
					}
					visit[c[lay]-'A'] = false;
					}
				else
				{
					if ( isdig(c[lay]) )
						k = c[lay]-'0';
					else
						k = letter[c[lay]-'A'];
					if ( (i+j+jin)%10 == k )
					{
						dfs(lay+1,(i+j+jin)/10);
					if ( flag == true )
							return;
					}
				}
			}
			vl[i] = false;
		}
		visit[a[lay]-'A'] = false;
	}
	else
	{
		if ( isdig(a[lay]) )
			i = a[lay]-'0';
		else
			i = letter[a[lay]-'A'];
		if ( !isdig(b[lay]) && visit[b[lay]-'A'] == false )
		{
			visit[b[lay]-'A'] = true;
			for ( j = 0; j < 10 ; j++ )
			{
				if ( vl[j] == true )
					continue;
				vl[j] = true;
				letter[b[lay]-'A'] = j;
				if ( !isdig(c[lay]) && visit[c[lay]-'A'] == false )
					{
						visit[c[lay]-'A'] = true;
						for ( k = 0; k < 10; k++ )
						{
							if ( vl[k] == true )
								continue;
							vl[k] = true;
							letter[c[lay]-'A'] = k;
							if ( (i+j+jin)%10 == k )
							{
								dfs(lay+1,(i+j+jin)/10);
								if ( flag == true )
									return;
							}
							vl[k] = false;
						}
						visit[c[lay]-'A'] = false;
					}
				else
				{
					if ( isdig(c[lay]) )
						k = c[lay]-'0';
					else
						k = letter[c[lay]-'A'];
					if ( (i+j+jin)%10 == k )
					{
						dfs(lay+1,(i+j+jin)/10);
						if ( flag == true )
							return;
					}
				}
				vl[j] = false;
			}
			visit[b[lay]-'A'] = false;
		}
		else
		{
			if ( isdig(b[lay]) )
				j = b[lay]-'0';
			else
				j = letter[b[lay]-'A'];
			if ( !isdig(c[lay]) && visit[c[lay]-'A'] == false )
			{
				visit[c[lay]-'A'] = true;
				for ( k = 0; k < 10; k++ )
				{
					if ( vl[k] == true )
						continue;
					vl[k] = true;
					letter[c[lay]-'A'] = k;
					if ( (i+j+jin)%10 == k )
					{
						dfs(lay+1,(i+j+jin)/10);
						if ( flag == true )
							return;
					}
					vl[k] = false;
				}
				visit[c[lay]-'A'] = false;
			}
			else
			{
				if ( isdig(c[lay]) )
					k = c[lay]-'0';
				else
					k = letter[c[lay]-'A'];
				if ( (i+j+jin)%10 == k )
				{
					dfs(lay+1,(i+j+jin)/10);
					if ( flag == true )
						return;
				}
			}
		}
	}
}
int main ()
{
	init();
	dfs(0,0);
	int i;
	if ( flag == false )
		cout<<"NO"<<endl;
	for ( i = 0; i < 26; i++ )
	{
		if ( v[i] == false )
			continue;
		cout<<char(i+'A')<<" "<<letter[i]<<endl;
	}
	return 0;
}
