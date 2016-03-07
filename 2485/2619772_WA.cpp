	#include <iostream>
	using namespace std;
	int c[510][510];
	struct ac
	{
		int x,y;
		int len;
	}a[10000];
	int root[600];

	int find ( int a )
	{
		while ( root[a] != a )
			a = root[a];
		return a;
	}
	void join ( int a, int b )
	{
		root[find(a)] = find(b);
	}
	void SmallHeapInsert ( int& CurrentSize, ac x )
	{
		int i = CurrentSize;
		while ( i > 1 )
		{
			if ( a[i/2].len > x.len )
			{
				a[i] = a[i/2];
				i /= 2;
			}
			else
				break;
		}
		a[i] = x;
		CurrentSize++;
	}
	int SmallDel ( int& CurrentSize )
	{
		CurrentSize--;
		int t = a[1].len;
		ac item = a[CurrentSize];
		int i = 2;
		while ( i <= CurrentSize )
		{
			if ( i < CurrentSize && a[i].len > a[i+1].len )
				i++;
			if ( item.len <= a[i].len )
				break;
			a[i/2] = a[i];
			i *= 2;
		}
		a[i/2] = item;
		return t;
	}
	int main ()
	{
		int tcase;
		bool visit[510];
		int w[510];
		int i,j,k,n,CurrentSize;
		int x,y;
		scanf("%d",&tcase);
		while ( tcase )
		{
			tcase--;
			scanf("%d",&n);
			k = 0;
			CurrentSize = 1;
			for ( i = 1; i <= n; i++ )
			{
				visit[i] = false;
				root[i] = i;
				for ( j = 1; j <= n; j++ )
				{
					scanf("%d",&c[i][j]);
					if ( i > j )
					{
						a[k].x = i;
						a[k].y = j;
						a[k].len = c[i][j];
						SmallHeapInsert(CurrentSize,a[k]);
						k++;
					}
				}
			}
			for ( i = 1; i < n; i++ )
			{
				x = a[1].x;
				y = a[1].y;
				SmallDel(CurrentSize);
				if ( find(x)==find(y) )
				{
					i--;
					continue;
				}
				join(x,y);
			}
			cout<<c[x][y]<<endl;
		}
		return 0;
	}
