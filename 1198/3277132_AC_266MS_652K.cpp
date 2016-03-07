#pragma   warning(disable:4786)
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;
struct ac
{
	int t[8];
}x[166000],y[66000];
map<int,int>kt;
char v[12][12];
int flag,e1,e2,ans;
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	int i;
	for ( i = 0; i < 8; i++ )
	{
		if ( c->t[i] != d->t[i] )
			return c->t[i] - d->t[i];
	}
	return 0;
}
void s ( int t[] )
{
	int k[2],i,j;
	for ( i = 0; i < 8; i+=2 )
	{
		for ( j = i+2; j < 8; j+= 2 )
		{
			if ( t[i] > t[j] || t[i]==t[j]&&t[i+1]>t[j+1] )
			{
				k[0] = t[i];
				k[1] = t[i+1];
				t[i] = t[j];
				t[i+1] = t[j+1];
				t[j] = k[0];
				t[j+1] = k[1];
			}
		}
	}
}
void fz ( int t[], int p[] )
{
	int i;
	for ( i = 0; i < 8; i++ )
		t[i] = p[i];
}
void init ()
{
	strcpy(v[0],"0000000000");
	strcpy(v[1],"0111111110");
	strcpy(v[2],"0111111110");
	strcpy(v[3],"0111111110");
	strcpy(v[4],"0111111110");
	strcpy(v[5],"0111111110");
	strcpy(v[6],"0111111110");
	strcpy(v[7],"0111111110");
	strcpy(v[8],"0111111110");
	strcpy(v[9],"0000000000");
}
void dfs ( int t[], int lay )
{
	if ( lay == 6 )
		return;
	int i;
	int k = 0;
	int p[8];
	fz(p,t);
	s(p);
	for ( i = 0; i < 8; i++ )
	{
		k *= 10;
		k += p[i];
	}
	if ( k == ans && lay != 1 )
		return;
	if ( kt[k] != 0 && kt[k] <= lay )
		return;
	if ( flag == 0 )
	{
		fz(x[e1].t,p);
		e1++;
	}
	else
	{
		fz(y[e2].t,p);
		e2++;
	}
	fz(p,t);
	kt[k] = lay;
	for ( i = 0; i < 8; i+= 2 )
	{
		if ( v[p[i]-1][p[i+1]] == '1' )//up1
		{
			v[p[i]-1][p[i+1]] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i] = p[i]-1;
			dfs(t,lay+1);
			t[i] = p[i];
			v[p[i]][p[i+1]] = '0';
			v[p[i]-1][p[i+1]] = '1';
		}
		else if ( p[i] >= 3 && v[p[i]-2][p[i+1]] == '1' )//up2
		{
			v[p[i]-2][p[i+1]] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i] = p[i]-2;
			dfs(t,lay+1);
			t[i] = p[i];
			v[p[i]][p[i+1]] = '0';
			v[p[i]-2][p[i+1]] = '1';
		}
		if ( v[p[i]+1][p[i+1]] == '1' )//down1
		{
			v[p[i]+1][p[i+1]] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i] = p[i]+1;
			dfs(t,lay+1);
			t[i] = p[i];
			v[p[i]][p[i+1]] = '0';
			v[p[i]+1][p[i+1]] = '1';
		}
		else if ( p[i] <= 6 && v[p[i]+2][p[i+1]] == '1' )//down2
		{
			v[p[i]+2][p[i+1]] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i] = p[i]+2;
			dfs(t,lay+1);
			t[i] = p[i];
			v[p[i]][p[i+1]] = '0';
			v[p[i]+2][p[i+1]] = '1';
		}
		if( v[p[i]][p[i+1]-1] == '1' )//left1
		{
			v[p[i]][p[i+1]-1] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i+1] = p[i+1]-1;
			dfs(t,lay+1);
			t[i+1] = p[i+1];
			v[p[i]][p[i+1]] = '0';
			v[p[i]][p[i+1]-1] = '1';
		}
		else if ( p[i+1] >= 3 && v[p[i]][p[i+1]-2] == '1' )//left2
		{
			v[p[i]][p[i+1]-2] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i+1] = p[i+1]-2;
			dfs(t,lay+1);
			t[i+1] = p[i+1];
			v[p[i]][p[i+1]] = '0';
			v[p[i]][p[i+1]-2] = '1';
		}
		if( v[p[i]][p[i+1]+1] == '1' )//right1
		{
			v[p[i]][p[i+1]+1] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i+1] = p[i+1]+1;
			dfs(t,lay+1);
			t[i+1] = p[i+1];
			v[p[i]][p[i+1]] = '0';
			v[p[i]][p[i+1]+1] = '1';
		}
		else if ( p[i+1] <= 6 && v[p[i]][p[i+1]+2] == '1' )//right2
		{
			v[p[i]][p[i+1]+2] = '0';
			v[p[i]][p[i+1]] = '1';
			t[i+1] = p[i+1]+2;
			dfs(t,lay+1);
			t[i+1] = p[i+1];
			v[p[i]][p[i+1]] = '0';
			v[p[i]][p[i+1]+2] = '1';
		}
	}
}
int big ( int m1[], int m2[] )
{
	int i;
	for ( i = 0; i < 8; i++ )
	{
		if ( m1[i] != m2[i] )
			return m1[i]-m2[i];
	}
	return 0;
}
int main ()
{
	int b1[8],b2[8];
	int i,j,k;
	while ( scanf("%d",&b1[0]) != EOF )
	{
		kt.clear();
		e1 = e2 = 0;
		for ( i = 1; i < 8; i++ )
			scanf("%d",&b1[i]);
		for ( i = 0; i < 8; i++ )
			scanf("%d",&b2[i]);
		s(b1);
		s(b2);
		ans = 0;
		for ( i = 0; i < 8; i++ )
		{
			ans *= 10;
			ans += b1[i];
		}
		init();
		for ( i = 0; i < 8; i+=2 )
			v[b1[i]][b1[i+1]] = '0';
		flag = 0;
		dfs(b1,1);

		kt.clear();
		init();
		for ( i = 0; i < 8; i+=2 )
			v[b2[i]][b2[i+1]] = '0';
		flag = 1;
		ans = 0;
		for ( i = 0; i < 8; i++ )
		{
			ans *= 10;
			ans += b2[i];
		}
		dfs(b2,1);

		qsort(x,e1,sizeof(x[0]),cmp);
		qsort(y,e2,sizeof(y[0]),cmp);

		k = i = j = 0;
		while ( i < e1 && j < e2 )
		{
			k = big(x[i].t,y[j].t);
			if ( k < 0 )
				i++;
			else if ( k > 0 )
				j++;
			else
				break;
		}
		if ( k == 0 )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
