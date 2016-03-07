#include<iostream>
#include<deque>
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
deque<re > q;//here
ac a[110];

int n,m,k;

int bfs()
{  
   re p,tp;
   p.cost = 0;
   p.x = p.y = 0;
   
   q.push_back(p);
   int i,j,y,x,c,_min = _max;
   int dp[110][110];
   for(i = 0; i <= n; i++)
	   for(j = 0; j <= m; j++)
	   {
		   dp[i][j] = _max;
	   }
	dp[0][0] = 0;//here
   while(!q.empty())
   {
       tp = q.front();
	   q.pop_front();
	   if ( dp[tp.x][tp.y] < tp.cost )//here
		   continue;
       for(i = 0; i < k; i++)
	   {
		   x = tp.x + a[i].x;
		   y = tp.y + a[i].y;
		   c = tp.cost + a[i].c;
		   p.x = x; p.y = y;
		   p.cost = c;
		   if(x <= n && y <= m && x >= 0 && y >= 0)
		   {
			   if(dp[x][y]>c)//here
			   {
				   dp[x][y] = c;
				   q.push_back(p);
			   }
//			   if(dp[x][y] > c)//here
//			     dp[x][y] = c;
		   }
	   }
   }
   return dp[n][m];
}
int main()
{
	int i;
    int x,y,c,j;
	while(scanf("%d%d%d",&n,&m,&k) && n+m+k && n*m)
	{
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