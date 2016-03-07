#include <iostream>
using namespace std;
int n;
struct ac
{
	int v;
	ac *next;
}*list[1200];
int pow[1200];
int s[3000000];
int min[1200];
void insert ( int a ,int b )
{
	ac *p  = new ac;
	p->v = b;
	p->next=list[a];
	list[a] = p;
}
void qq ( int k, char *a )
{
	int i,j = 0;
	for ( i = 0; a[i] != NULL; )
	{
		while ( a[i] == ' ' && a[i] != NULL )
			i++;
		if ( a[i] == NULL )
			break;
		while ( a[i] >= '0' && a[i] <= '9' )
		{
			j *= 10;
			j += (a[i]-'0');
			i++;
		}
		while ( a[i] == ' ' && a[i] != NULL )
			i++;
		if ( j != 0 )
			insert(k,j);
		j = 0; 
		if ( a[i] == NULL )
			break;
	}
}
int bfs ( int x, int& stone )
{
	min[x] = 0;
	int begin = 0, end = 1;
	int m=0;
	s[0] = x;
	ac *p;
	while ( begin < end )
	{
		x = s[begin++];
		p = list[x];
		while (p != NULL )
		{
			if ( min[p->v] > min[x]+1 && pow[x] >= pow[p->v] )
			{
				min[p->v] = min[x]+1;
				s[end++] = p->v;
			}
			p = p->next;
		}
	}
	m = min[1];
	stone = 1;
	for ( int i = 1 ; i<= n; i++ )
	{
		if ( min[i] == 2000000000 )
			return -1;
		else if ( min[x] > m )
		{
			stone = x;
			m = min[x];
		}
	}
	return m;
}
int main ()
{
	int i,j,max=0;
	char ch[10000];
	cin>>n;
	for ( i = 1; i <= n; i++ )
		list[i] = NULL;
	for ( i = 1; i <= n; i++ )
	{
		cin>>pow[i];
		if ( max < pow[i] )
			max = pow[i];
		cin.getline(ch,100000,'\n');
		qq(i,ch);
	}
	int stone;
	int k,t;
	int y;
	t = -1;
	for ( i = 1 ;i <= n; i++ )
	{
		if ( pow[i] == max )
		{
			for ( y = 0; y <= n; y++ )
				min[y] = 2000000000;
			j = bfs(i,stone);
			if  ( j >= t )
			{
				t = j;
				k = i;
			}
		}
	}
	if ( t == -1 )
		cout<<"impossible"<<endl;
	else
	{
		cout<<t<<endl;cout<<k<<endl;
	}
	return 0;
}
