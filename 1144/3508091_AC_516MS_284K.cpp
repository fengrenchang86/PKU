#include<iostream>
#include<queue>
using namespace std;
int g[110][110];
int gc[110][110];
int n;
int cnt,num;
bool visit[110];
bool vis[110];
bool flag;
void in()
{
	int i;
    int t,a,b;
	char ch[10000];
	 while(scanf("%[^\n]%*c",ch))
	 {
		if(ch[0] == '0')
			return;
		t = 0;i = 0;
		while ( ch[i] == ' ' )
			i++;
		while(ch[i] != ' ')
		{
			t *= 10;
			t += (ch[i] - '0');
			i++;
		}
		i++;
		a = t;
		t = 0;
		while(1)
		{
          if(ch[i] == ' ')
		  {
             b = t;
			 t = 0;
			 g[a][b] = g[b][a] = 1;
			 i++;
		  }
          if(ch[i] == '\0')
		  {
             b = t;
			 t = 0;
			 g[a][b] = g[b][a] = 1;
			 break;
		  }
		  else
		  {
           t *= 10;
		   t += (ch[i] -'0');
		   i++;
		  }
		}
	 }
}
void dfs(int k,int father,int ft)
{
  int i;
  num++;
  if( num >= n)
  {
	  flag = true;
	  return;
  }
  if(flag)
	  return;
  visit[k] = 1;
  for(i = 1; i <= n; i++)
  {
	  if(i != ft && g[k][i] == 1 && !visit[i] && i != father)
	  {
            visit[i] = 1;
			dfs(i,k,ft);
			visit[i] = 0;
	  }
  }
  visit[k] = 0;
}
void bfs(int k,int kk) //shan kk
{
  int i;
  queue<int > q;
  int t;
  visit[k] = 1;
  visit[kk] = 1;
  for(i = 1; i <= n; i++)
  {
	  if(!visit[i] && g[i][k] == 1)
	  {
		  q.push(i);
		  visit[i] = 1;
		  num++;
	  }
  }
  while(!q.empty() && n > num)
  {
	  t = q.front();
	  q.pop();
	  for(i = 1; i <= n; i++)
	  {
		  if(!visit[i]&& g[i][t] == 1)
		  {
			  q.push(i);
			  visit[i] = 1;
			  num++;
		  }
	  }
  }
}
void st()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		flag = false;
		num = 2;
	//	memset(vis,0,sizeof(vis));
		memset(visit,0,sizeof(visit));
        bfs(i%n+1,i);
	//	visit[(i+1)%n] = 1;
	//	visit[1%n+1] = 1;
	//	visit[i] = 1;
      // dfs( i%n+1,-1,i);
		if(num < n)
			cnt++;
	}
	printf("%d\n",cnt);
}
void init()
{
	int i,j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			g[i][j] = 0;
}
int main()
{
	while(scanf("%d",&n) && n)
	{
	   cin.ignore();
	   init();
       in();
       cnt = 0;
	   st();
	}
	return 0;
}