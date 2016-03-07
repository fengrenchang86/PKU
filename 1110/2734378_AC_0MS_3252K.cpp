#include <iostream>
using namespace std;
char a[20][100];
int d[1000][1000];
bool visit[100];
int n,r,c;
int main ()
{
	void init();
	bool single(int);
	void second(int);
	bool ok(int);
	int i,t=1;
	while ( scanf("%d%d%d",&n,&r,&c) )
	{
		if ( n+r+c==0)
			break;
		init();
		cin.ignore();
		for ( i = 0; i < r; i++ )
			gets(a[i]);
//			cin.getline(a[i],100,'\n');
		for ( i = 0; i < n; i++ )
			visit[i] = single(i);
		for ( i = 0; i < n; i++ )
			second(i);
		for ( i = 0; i < n; i++ )
		{
			if ( visit[i] == false )
			{
				visit[i] = ok(i);
				if ( visit[i] == false )
					break;
			}
		}
		printf("Test %d\n",t);
		t++;
		if ( i < n )
			cout<<"impossible"<<endl;
		else
		{
			for ( i = 0; i < r; i++ )
				printf("%s\n",a[i]);
		}
	}
	return 0;
}
void init ()
{
	int i,j,k = r*c;
	for ( i = 0; i < k; i++ )
		for ( j =0 ; j < k; j++ )
			d[i][j] = 0;
	for ( i = 0; i < n; i++ )
		visit[i] = false;
}
bool ok ( int k )
{
	int i,j,x;
	x = r*c;
	for ( i = 0; i < x; i++ )
	{
		if ( a[i/c][i%c+k*(c+1)] != 'o' )
			continue;
		for ( j = i+1; j < x; j++ )
		{
			if ( a[j/c][j%c+k*(c+1)] != 'o' )
				continue;
			if ( d[i][j] == 1 )
			{
				a[i/c][i%c+k*(c+1)] = '#';
				a[j/c][j%c+k*(c+1)] = '#';
				return true;
			}
		}
	}
	return false;
}
void second ( int k )
{
	int i,j,x;
	x = r*c;
	for ( i = 0; i < x; i++ )
	{
		if ( a[i/c][i%c+k*(c+1)] != 'o' )
			continue;
		for ( j = i+1; j < x; j++ )
		{
			if ( a[j/c][j%c+k*(c+1)] != 'o' )
				continue;
			d[i][j] ++;
		}
	}
}
bool single ( int k )
{
	int i,j,z,t;
	for ( i = 0; i < r; i++ )
	{
		for ( z = 0; z < c; z++ )
		{
			j = z+k*(c+1);
			if ( a[i][j] == 'o' )
			{
				for ( t = 0; t < n; t++ )
				{
					if ( t == k )
						continue;
					if ( a[i][z+t*(c+1)] == 'o' )
						break;
				}
				if ( t == n )
				{
					a[i][j] = '#';
					return true;
				}
			}
		}
	}
	return false;
}