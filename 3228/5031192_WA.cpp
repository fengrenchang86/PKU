#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>vec;
vector<int>vecSide;
struct ac
{
	int v;
	int len;
	ac *next;
}*pList[210];
int n, m;
int a[210], b[210];
bool visit[210];
void Insert(int x, int y, int len)
{
	ac *p = new ac;
	p->next = pList[x];
	p->v = y;
	p->len = len;
	pList[x] = p;
}
void Init()
{
	int i;
	for(i =0 ; i < n; i++)
	{
		pList[i] = NULL;
	}
	vec.clear();
	vecSide.clear();
}
void dfs(int node, int* nFrom, int* nTo, int nSide)
{
	*nFrom += a[node];
	*nTo += b[node];
	visit[node] = true;
	ac *p = pList[node];
	while(p != NULL)
	{
		if(p->len > nSide)
		{
			p = p->next;
			continue;
		}
		if(!visit[p->v])
		{
			dfs(p->v, nFrom, nTo, nSide);
		}
		p = p->next;
	}
}
bool Judge(int nMid)
{
	int i;
	int x = 0, y = 0;
	memset(visit, false, sizeof(visit));
	for(i = 0; i < n; i++)
	{
		if(!visit[i])
		{
			x = y = 0;
			dfs(i, &x, &y, nMid);
			if(x > y)
				return false;
		}
	}
	return true;
}
void Solve()
{
	int nBegin, nEnd, nMid;
	int t = vecSide.size();
	nBegin = 0;
	nEnd = t - 1;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if(true == Judge(vecSide[nMid]))
			nEnd = nMid;
		else
			nBegin = nMid + 1;
	}
	printf("%d\n", vecSide[nBegin]);
}
void Input()
{
	int i, x, y, len;
	Init();
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	scanf("%d", &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		x--;
		y--;
		Insert(x, y, len);
		Insert(y, x, len);
		vec.push_back(len);
	}
	sort(vec.begin(), vec.end());
	vecSide.push_back(vec[0]);
	for(i = 1; i < vec.size(); i++)
	{
		if(vec[i] != vec[i-1])
			vecSide.push_back(vec[i]);
	}
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}