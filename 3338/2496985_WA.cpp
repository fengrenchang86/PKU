#include <iostream>
using namespace std;
int v[23][23];
class ac
{
public:
	int x1,y1,x2,y2;
	int s;
	bool yes;
}a[60];
int c=1;
int w;
void dfs ( int x, int y, int key, int l )
{
	if ( x-1 > a[l].x1 && v[x-1][y]==key )
	{
		v[x-1][y] = c;
		w++;
		dfs(x-1,y,key,l);
	}
	if ( x+1 < a[l].x2 && v[x+1][y] == key )
	{
		v[x+1][y] = c;
		w++;
		dfs(x+1,y,key,l);
	}
	if ( y-1 > a[l].y1 && v[x][y-1] == key )
	{
		v[x][y-1] = c;
		w++;
		dfs(x,y-1,key,l);
	}
	if( y+1 < a[l].y2 && v[x][y+1] == key )
	{
		v[x][y+1] = c;
		w++;
		dfs(x,y+1,key,l);
	}
}
int main ()
{
	int n,m,k;
	int i,j,l,t,max;
	while ( scanf("%d%d",&n,&m) && !(m==0&&n==0) )
	{
		c = 1;
		for ( i = 0; i <= n; i++ )
			for ( j = 0; j <= m; j++ )
				v[i][j] = 0;
		scanf("%d",&k);
		a[0].x1 = 0;
		a[0].y1 = 0;
		a[0].x2 = m;
		a[0].y2 = n;
		for ( l = 1; l <= k; l++ )
		{
			scanf("%d%d%d%d",&a[l].x1,&a[l].y1,&a[l].x2,&a[l].y2);
			a[l].yes = true;
			if ( a[l].x1 > a[l].x2 )
				swap(a[l].x1,a[l].x2);
			if ( a[l].y1 > a[l].y2 )
				swap(a[l].y1,a[l].y2);
			a[l].s = (a[l].y2-a[l].y1)*(a[l].x2-a[l].x1);
		}
		
		for ( i = 1; i < k; i++ )
		{
			for ( j = i+1; j <= k; j++ )
			{
				if ( a[i].s > a[j].s )
					continue;
				if ( a[i].s < a[j].s )
					swap(a[i],a[j]);
				else if ( a[i].x1 > a[j].x1 )
					swap(a[i],a[j]);
				else if ( a[i].x1 == a[i].x1 &&a[i].x2 > a[j].x2 )
					swap ( a[i],a[j]);
				else if ( a[i].x1 == a[i].x1 && a[i].x2 == a[j].x2 && a[i].y1 > a[j].y1 )
					swap(a[i],a[j]);
				else if ( a[i].x1 == a[i].x1 && a[i].x2==a[j].x2&&a[i].y1==a[j].y1&&a[i].y2>a[j].y2)
					swap(a[i],a[j]);
			}
		}
		for ( i = 1; i <= k; i++ )
		{
			if ( a[i].x1==a[i-1].x1&&a[i].x2==a[i-1].x2&&a[i].y1==a[i-1].y1&&a[i].y2==a[i-1].y2)
				a[i].yes = false;
		}
		for ( l = 1; l <= k; l++ )
		{
			if ( a[l].yes == false )
				continue;
			max = c;
			for ( i = a[l].x1; i < a[l].x2; i++ )
			{
				for ( j = a[l].y1; j < a[l].y2; j++ )
				{
					t = v[i][j];
					if ( t < max )
					{
						v[i][j] = c;
						w = 1;
						dfs(i,j,t,l);
				//		if ( w != a[l].s )
							c++;
					}
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
}