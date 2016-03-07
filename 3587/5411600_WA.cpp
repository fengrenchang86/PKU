#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
const int N = 5000;
int n;
struct point
{
	double x;
	double y;
}p[N],up[N],down[N];//分别保存：所有的点，上凸包，下凸包
struct ac
{
	double k,b;
	double x;
};
double juli[660][660];
ac GetLine(point m1, point m2)
{
	ac l;
	point m3;
	m3.x = (m1.x + m2.x) / 2;
	m3.y = (m1.y + m2.y) / 2;
	if (m2.y == m1.y)
	{
		l.x = m3.x;
		return l;
	}
	l.x = -1;
	l.k = (m1.x - m2.x) / (m2.y - m1.y);
	l.b = m3.y - m3.x * l.k;
	return l;
}
point GetCommonPoint(ac l1, ac l2)
{
	point pp;
	if (l1.x != -1)
	{
		pp.x = l1.x;
		pp.y = l2.k * pp.x + l2.b;
	}
	else if (l2.x != -1)
	{
		pp.x = l2.x;
		pp.y = l1.k * pp.x + l1.b;
	}
	else
	{
		pp.x = (l1.b - l2.b) / (l2.k - l1.k);
		pp.y = l1.k * pp.x + l1.b;
	}
	return pp;
}
double GetDis(point m1, point m2)
{
	return sqrt(double((m1.x - m2.x)*(m1.x - m2.x) + (m1.y - m2.y)*(m1.y-m2.y)));
}
int cmp( const void *a , const void *b ) 
{ 
    struct point *c = (point *)a; 
    struct point *d = (point *)b; 
    if(c->x != d->x) return c->x - d->x; 
    else return d->y - c->y; 
}
int right ( point t[], int a, int b, int c )//判断t[a],t[b],t[c]是否右拐
{
	int m = (t[b].x-t[a].x)*(t[c].y-t[a].y)-(t[c].x-t[a].x)*(t[b].y-t[a].y);
	if ( m < 0 )
		return 1;
	else
		return 0;
	return 0;
}
int make_up ( int n )
{
	int k,i;
	up[0] = p[0];
	up[1] = p[1];
	i = 2;
	k = 2;
	while ( i < n )
	{
		up[k] = p[i];
		while ( k > 1 && right(up,k-2,k-1,k) == 0 )
		{
			up[k-1] = up[k];
			k--;
		}
		k++;
		i++;
	}
	return k;
}
int make_down ( int n )
{
	int k,i;
	down[0] = p[n-1];
	down[1] = p[n-2];
	k = 2;
	i = n-3;
	while ( i >= 0 )
	{
		down[k] = p[i];
		while ( k > 1 && right(down,k-2,k-1,k) == 0 )
		{
			down[k-1] = down[k];
			k--;
		}
		k++;
		i--;
	}
	return k;
}
void Input()
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%llf %llf", &p[i].x, &p[i].y);
	}
	qsort(p, n, sizeof(p[0]), cmp);
}
void Solve()
{
	int n1, n2, m;
	n1 = make_up(n);
	n2 = make_down(n);
	int i, j, k;
	for (i = 0; i < n2; i++)
	{
		up[i+n1] = down[i];
	}
	m = i + n1;
	double ans = 0.0, dis;
	ac l1, l2;
	point pp;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			juli[i][j] = GetDis(up[i], up[j]);
		}
	}
	double a,b,c,s;
	for (i = 0; i < m - 2; i++)
	{
		for (j = i + 1; j < m - 1; j++)
		{
			if (up[i].x == up[j].x && up[i].y == up[j].y)
			{
				continue;
			}
			for (k = j + 1; k < m; k++)
			{
				if(up[i].x == up[k].x && up[i].y == up[k].y)
					continue;
				if(up[j].x == up[k].x && up[j].y == up[k].y)
					continue;
				a = juli[i][j];
				b = juli[j][k];
				c = juli[k][i];
				s = (a + b + c) / 2.0;
				dis = a * b * c / 4.0 / sqrt(s * (s-a) * (s-b) * (s-c));
				if (dis > ans)
				{
					ans = dis;
				}
			}
		}
	}
	printf("%.3lf\n", ans);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}
