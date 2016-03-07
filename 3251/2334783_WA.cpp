#include <iostream>
using namespace std;
int n;
char ch[120][120];
struct ac
{
	int x;
	int y;
}v[10001];
int yes(int x1, int y1, int x2, int y2 )
{
	int x3,y3,x4,y4;
	int dx,dy;
	dx = abs(x1-x2);
	dy = abs(y1-y2);
	int k = (y2-y1)*(x2-x1);
	if ( k > 0 )
	{
		x3 =x2+dy;
		y3 =y2-dx;
		x4 =x1+dy;
		y4 =y1-dx;
		if ( x3 < n && y3 >= 0 && x4 < n && y4 >= 0)
		{
			if ( ch[x3][y3] != 'J' && ch[x4][y4] != 'J' )
			{
				return 0;
			}
			else if ( ch[x3][y3] == 'J' && ch[x4][y4] == 'J' )
				return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
			else if ( ch[x3][y3] == '*' || ch[x4][y4] == '*' )
					return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		}
		x3 =x2-dy;
		y3 =x2+dx;
		x4 =x1-dy;
		y4 =x1+dx;
		if ( x3 >= 0 && y3 < n && x4 >= 0 && y4 < n )
		{
			if ( ch[x3][y3] != 'J' && ch[x4][y4] != 'J' )
			{
				return 0;
			}
			else if ( ch[x3][y3] == 'J' && ch[x4][y4] == 'J' )
				return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
			else if ( ch[x3][y3] == '*' || ch[x4][y4] == '*' )
					return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		}
	}
	else
	{
		x3 = x2+dy;
		y3 = y2+dx;
		x4 = x1+dy;
		y4 = y1+dx;
		if ( x3 < n && y3 < n && x4 < n && y4 < n )
		{
			if ( ch[x3][y3] != 'J' && ch[x4][y4] != 'J' )
			{
				return 0;
			}
			else if ( ch[x3][y3] == 'J' && ch[x4][y4] == 'J' )
				return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
			else if ( ch[x3][y3] == '*' || ch[x4][y4] == '*' )
					return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		}
		x3 = x2-dy;
		y3 = x2-dx;
		x4 = x1-dy;
		y4 = x1-dx;
		if ( x3 >= 0 && y3 >= 0 && x4 >= 0 && y4 >= 0 )
		{
			if ( ch[x3][y3] != 'J' && ch[x4][y4] != 'J' )
			{
				return 0;
			}
			else if ( ch[x3][y3] == 'J' && ch[x4][y4] == 'J' )
				return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
			else if ( ch[x3][y3] == '*' || ch[x4][y4] == '*' )
					return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		}
	}
	return 0;
}
int main ()
{
	int i,j,k;
	int stack[10001][2];
	int head = 0;
	scanf("%d",&n);
	for ( i = 0; i < n;i ++ )
		scanf("%s",&ch[i]);
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
			if ( ch[i][j] == 'J' )
			{
				v[head].x = i;
				v[head].y = j;
				head++;
			}
	}
	int max = 0;
	for ( i = 0; i < head-1; i++ )
	{
		for ( j = i+1; j < head; j++ )
		{
			if ( (v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y) <= max )
				continue;
			k = yes(v[i].x,v[i].y,v[j].x,v[j].y);
			if ( k > max )
				max = k;
		}
	}
	cout<<max<<endl;
	return 0;
}