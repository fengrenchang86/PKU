#include <iostream>
 
using namespace std;
struct ac
{
	short w;
	short c;
	short add;
	short x;
	short y;
	ac()
	{
		w = c = x = y = 0;
		add = 0;
	}
}d[30][8000];
short ans[4];
int cu = 0;
int f ( int x, int y )
{
	if ( d[x][y].x == 0 && d[x][y].y == 0)
	{
		if ( d[x][y].add != 0 )
			ans[cu++] = d[x][y].add;
	//		printf("%d ",d[x][y].add);
		return 1;
	}
	f (d[x][y].x,d[x][y].y);
	if ( d[x][y].add != 0 )
		ans[cu++] = d[x][y].add;
	//	printf("%d ",d[x][y].add);
	return 1;
}
int g ( short a[], int n, int z )
{
	int i;
	int c = -1;
	for ( i = 1; i < n; i++ )
	{
		if ( a[i] == z )
			c++;
	}
	return c;
}
int h ( int z )
{
	int i;
	int c = -1;
	for ( i = 0; i < cu; i++ )
	{
		if ( ans[i] == z )
			c++;
	}
	return c;
}
int main ()
{
	short a[200];
	int i=1,j,k = 0;
	int t;
	int n;
	int p,q;
	int m;
	int max;
/*	for ( i = 0; i < 150; i++ )
	{
		srand((unsigned)time(NULL)); 
		a[i]=rand()%10; 
	}*/
	while ( scanf("%d",&a[i])!=EOF)
	{
		if ( a[i] != 0 )
		{
			i++;
			continue;
		}
		max = i;
		for ( j = 1; j < i-1; j++ )
		{
			for ( k = j+1; k < i; k++ )
			{
				if ( a[j] < a[k] )
				{
					t = a[j];
					a[j] = a[k];
					a[k] = t;
				}
			}
		}
		t = i;
		for ( j = i-1; j >= 1; j-- )
		{
			a[t++] = a[j];
			a[t++] = a[j];
			a[t++] = a[j];
		}
		bool flag = false;
	//	for ( j = 1; j < t; j++ )
	//		cout<<a[j]<<" ";
	//	cout<<endl;
		while ( cin >> n && n!= 0)
		{
			flag = false;
			for ( i = 1; i < t; i++ )
			{
				for ( j = 0; j <= n; j++ )
				{
					if ( j < a[i] )
					{
						d[i][j].w = d[i-1][j].w;
						d[i][j].c = d[i-1][j].c;
						d[i][j].x = i-1;
						d[i][j].y = j;
					}
					else if ( d[i-1][j].w > d[i-1][j-a[i]].w )
					{
						d[i][j].w = d[i-1][j].w;
						d[i][j].c = d[i-1][j].c;
						d[i][j].x = i-1;
						d[i][j].y = j;
					}
					else
					{
						d[i][j].add = a[i];
						d[i][j].x = i-1;
						d[i][j].y = j-a[i];
						d[i][j].c = d[i-1][j-a[i]].c+1;
						d[i][j].w = d[i-1][j-a[i]].w+a[i];
					}
					if ( d[i][j].w ==n && d[i][j].c <= 4 )
					{
						f( i, j );
						flag = true;
						for ( p = 0; p <120 ; p++ )
							for ( q = 0; q <3000;q++)
								d[p][q].w = d[p][q].c = d[p][q].add = d[p][q].x =d[p][q].y = 0;
						break;
					}					
				}
				if ( flag )
					break;
			}
			if ( flag == false )
					cout<<n<<" ---- "<<"none"<<endl;
			else 
			{
				m = 0;
				int u = 0;
				p = q = 0;
				for ( k = 0; k < cu; k++ )
				{
					q = g(a,max,ans[k]);
					if ( q == h(ans[k]) )
						continue;
					if ( q > 0 )
						p++;
					m += q;
				}
				if ( p > 0 )
				{
					u = 1;
					for(q = 1; q < cu; q++ )
					{
						if ( ans[q] != ans[q-1])
							u++;
					}
					q = g(a,max,ans[0]);
					m = h(ans[0]);
					if ( m != 0 && q!=0)
					{
						if ( q > m)
							u += m;
						else
							u += q;
					}
					p = 1;
					while ( p < cu )
					{
						if ( ans[p] != ans[p-1] )
						{
							q = g(a,max,ans[p]);
							m = h(ans[0]);
							if ( q > m )
								u+=m;
							else
								u+=q;
						}
						p++;
					}
					printf("%d (%d): tie\n",n,u);
				}
				else
				{
					u = 0;
					for ( p = 1; p < cu; p++ )
					{
						if ( ans[p] != ans[p-1] )
							u++;
						else if ( g(a,max,ans[p])!= 0 )
							u++;
					}
					u = cu - u;
					printf("%d (%d): ",n,cu-u+1);
					for ( p = cu-1; p>=0 ;p-- )
						printf("%d ",ans[p]);
					printf("\n");
					cu = 0;
				}
			}
			flag = false;
		}
		i = 1;
		
	/*	for ( i = 11; i >= 0; i-- )
			if ( d[i][7].w == 7 && d[i][7].c <= 4 )
				f(d[i][7].x,d[i][7].y);*/
	}
	return 1;
}