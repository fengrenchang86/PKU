#include<iostream>
#include<queue>
using namespace std;
#define _max 2000000000
struct ac
{
	int x,y,c;
};
struct re
{
	int x,y;
	int cost;
};

ac a[110];

int n,m,k;

int bfs()
{  
   re p,tp;
   p.cost = 0;
   p.x = p.y = 0;
   queue<re > q;
   q.push(p);
   int i,j,y,x,c,_min = _max;
   int dp[110][110];
   bool visit[110][110];
   for(i = 0; i <= n; i++)
	   for(j = 0; j <= m; j++)
	   {
		   visit[i][j] = 0;
		   dp[i][j] = _max;
	   }
   while(!q.empty())
   {
       tp = q.front();
	   q.pop();
	   if ( dp[tp.x][tp.y] < tp.cost )
		   continue;
       for(i = 0; i < k; i++)
	   {
		   x = tp.x + a[i].x;
		   y = tp.y + a[i].y;
		   c = tp.cost + a[i].c;
		   p.x = x; p.y = y;
		   if(x <= n && y <= m && x >= 0 && y >= 0)
		   {
			   if( dp[x][y] > c)
			   {
				   dp[x][y] = c;
				   p.cost = c;
				   q.push(p);
			   }
		   }
	   }
   }
   return dp[n][m];
}
int main()
{
	int i;
    int x,y,c,j;
	while(scanf("%d%d%d",&n,&m,&k) != EOF )
	{
		if ( n==0&&m==0&&k==0 )
			break;
		for(i = 0,j=0; i < k; i++)
		{
			scanf("%d%d%d",&x,&y,&c);
            if(x < 0)
				continue;
			a[j].x = x;
			a[j].y = y;
			a[j++].c = c;
		}
		k = j;
		y = bfs();
        if(y == _max)
			printf("-1\n");
		else
			printf("%d\n",y);
	}
	return 0;
}