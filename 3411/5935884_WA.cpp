#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
struct ACM
{
	int v;
	int c;
	int p, r;
	ACM *next;
}*pList[20];
struct WF
{
	int nStatus;
	int pos;
	int val;
	bool operator()(WF &m1, WF &m2)
	{
		return m1.val > m2.val;
	}
};
priority_queue<WF, vector<WF>, WF>que;
int w[2200][20];
int n, m;
void Insert(int a, int b, int c, int p, int r)
{
	ACM *q = new ACM;
	q->v = b;
	q->c = c;
	q->p = p;
	q->r = r;
	q->next = pList[a];
	pList[a] = q;
}
void Input()
{
	int i, a, b, c, p, r;
	for (i = 0; i <= n; i++)
	{
		pList[i] = NULL;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d %d %d", &a, &b, &c, &p, &r);
		Insert(a, b, c, p, r);
	}
}
void Solve()
{
	while (!que.empty())
	{
		que.pop();
	}
	int i, j;
	for (i = 0; i < 1200; i++)
	{
		for (j = 0; j < 20; j++)
		{
			w[i][j] = INF;
		}
	}
	WF x, y;
	ACM *pAcm;
	x.nStatus = (1 << 1);
	x.pos = 1;
	x.val = 0;
	w[2][1] = 0;
	que.push(x);
	while (!que.empty())
	{
		x = que.top();
		que.pop();
		if (x.val > w[x.nStatus][x.pos])
		{
			continue;
		}
		pAcm = pList[x.pos];
		while (pAcm != NULL)
		{
			y.nStatus = (x.nStatus | (1 << pAcm->v));
			y.pos = pAcm->v;
			if ((x.nStatus | (1 << pAcm->c)) == x.nStatus)
			{
				y.val = x.val + pAcm->p;
			}
			else
			{
				y.val = x.val + pAcm->r;
			}
			if (y.val < w[y.nStatus][y.pos])
			{
				w[y.nStatus][y.pos] = y.val;
				que.push(y);
			}
			pAcm = pAcm->next;
		}
	}
	int ans = INF;
	for (i = 1; i <= 2048; i++)
	{
		if (w[i][n] < ans)
		{
			ans = w[i][n];
		}
	}
	if (ans == INF)
	{
		printf("impossible\n");
		return;
	}
	printf("%d\n", ans);
}
int main()
{
//	while(scanf("%d %d", &n, &m) != EOF)
	{
		cin>>n>>m;
		Input();
		Solve();
	}
	return 0;
}