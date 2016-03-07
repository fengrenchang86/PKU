#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
struct ac
{
	int len;
	int v;
	bool boy;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.len > m2.len;
	}
};
struct node
{
	int len;
	int v;
};

priority_queue<ac, vector<ac>, ac>que;
int boy[10010];
int girl[10010];
vector<node>tableBoy[10010];
vector<node>tableGirl[10010];
bool visitGirl[10010];
bool visitBoy[10010];

int n, m, r;
void Init()
{
	int i;
	for(i = 0; i <= n; i++)
	{
		tableBoy[i].clear();
		boy[i] = INF;
	}
	for(i = 0; i <= m; i++)
	{
		tableGirl[i].clear();
		girl[i] = INF;
	}	
	while(!que.empty())
		que.pop();
	memset(visitBoy, false, sizeof(visitBoy));
	memset(visitGirl, false, sizeof(visitGirl));
}
void Input()
{
	scanf("%d %d %d", &n, &m, &r);
	Init();
	int i, x, y, len;
	node p;
	for(i = 0; i < r; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		x++;
		y++;
		p.len = 10000 - len;
		p.v = y;
		tableBoy[x].push_back(p);
		p.v = x;
		tableGirl[y].push_back(p);
	}
}
void Solve()
{
	int i, k;
	int ans = 0;
	node p;
	ac q, t;
	p.len = 10000;
	for(i = 1; i <= n; i++)
	{
		p.v = i;
		tableBoy[0].push_back(p);
	}
	for(i = 1; i <= m; i++)
	{
		p.v = i;
		tableGirl[0].push_back(p);
	}
	boy[0] = 0;
	girl[0] = 0;
	q.boy = true;
	q.len = 0;
	q.v = 0;
	que.push(q);
	q.boy = false;
	que.push(q);
	while(!que.empty())
	{
		q = que.top();
		que.pop();
		if(q.boy)
		{
			if(visitBoy[q.v] || q.len > boy[q.v])
				continue;
			visitBoy[q.v] = true;
			ans += q.len;
			k = tableBoy[q.v].size();
			for(i = 0; i < k; i++)
			{
				p = tableBoy[q.v][i];
				if(false == visitGirl[p.v] && girl[p.v] > p.len)
				{
					girl[p.v] = p.len;
					t.boy = false;
					t.len = p.len;
					t.v = p.v;
					que.push(t);
				}
			}
		}
		else
		{
			if(visitGirl[q.v] || q.len > girl[q.v])
				continue;
			visitGirl[q.v] = true;
			ans += q.len;
			k = tableGirl[q.v].size();
			for(i = 0; i < k; i++)
			{
				p = tableGirl[q.v][i];
				if(false == visitBoy[p.v] && boy[p.v] > p.len)
				{
					boy[p.v] = p.len;
					t.boy = true;
					t.len = p.len;
					t.v = p.v;
					que.push(t);
				}
			}
		}
	}
	printf("%d\n", ans);
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