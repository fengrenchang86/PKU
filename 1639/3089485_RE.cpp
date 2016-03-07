#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	short len;
	short x,y;
}t[500];
int n,m,end;
short c[22][22];
short use[22];
bool d[22][22];
char brother[30][20];
int cmp ( const void*a, const void*b )
{
	ac *tc = (ac*)a;
	ac *td = (ac*)b;
	return tc->len-td->len;
}
int get ( char *ch )
{
	int i;
	for ( i = 0; i < end; i++ )
	{
		if ( strcmp(ch,brother[i]) == 0 )
			return i;
	}
	strcpy(brother[i],ch);
	end++;
	return i;
}
void input()
{
	int i,j,len,x,y;
	char ta[30],tb[30];
	end = 1;
	strcpy(brother[0],"Park");
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf(" %s %s %d",&ta,&tb,&len);
		x = get(ta);
		y = get(tb);
		c[x][y] = len;
		c[y][x] = len;
		t[i].len = len;
		if ( x < y )
		{
			t[i].x = x;
			t[i].y = y;
		}
		else
		{
			t[i].x = y;
			t[i].y = x;
		}
	}
	qsort(t,n,sizeof(t[0]),cmp);
	for ( i = 0; i < end; i++ )
	{
		for ( j = 0; j < end; j++ )
			d[i][j] = false;
		use[i] = 0;
	}
	scanf("%d",&m);
}
void updata ( int y )
{
	int i;
	for ( i = 1; i < end; i++ )
	{
		if ( d[y][i] == true )
		{
			use[i] = 3;
			updata(i);
		}
	}
}
void run ()
{
	int count = 0;
	int i,ans=0;
	for ( i = 0; i < n; i++ )
	{
		if ( t[i].x == 0 )
		{
			if ( m > 0 && use[t[i].y] < 2 )
			{
				use[t[i].y] = 3;
				updata(t[i].y);
				m--;
				ans += t[i].len;
			}
		}
		else if ( use[t[i].x] == 3 && use[t[i].y] != 3 )
		{
			use[t[i].y] = 3;
			ans += t[i].len;
		}
		else if ( use[t[i].y] == 3 && use[t[i].x] != 3 )
		{
			use[t[i].x] = 3;
			ans += t[i].len;
		}
		else if ( use[t[i].x] <= 1 && use[t[i].y] <= 1 )
		{
			use[t[i].x]++;
			use[t[i].y]++;
			ans += t[i].len;
			d[t[i].x][t[i].y] = true;
			d[t[i].y][t[i].x] = true;
		}
	}
	printf("Total miles driven: %d\n",ans);
}
int main ()
{
	input();
	run();
	return 0;
}