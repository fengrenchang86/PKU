#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, t, L;
bool stone[22][22];
struct ac
{
	int step;
	short pos[10];
	bool operator()(ac &m1, ac &m2)
	{
		if(m1.step != m2.step)
			return m1.step > m2.step;
		else
			return (m1.pos[0]/20 + m1.pos[0]%20) > (m2.pos[0]/20 + m2.pos[0]%20);
	}
};
short CurPos[10];
priority_queue<ac, vector<ac>, ac>que;
void Input()
{
	
	int i, x, y;
	for(i = 0; i < L; i++)
	{
		scanf("%d %d", &x, &y);
		CurPos[i] = x * 20 + y;
	}
	scanf("%d", &t);
	memset(stone, false, sizeof(stone));
	for(i = 0; i < t; i++)
	{
		scanf("%d %d", &x, &y);
		stone[x][y] = true;
	}
}
void Solve(int tc)
{
	while(!que.empty())
	{
		que.pop();
	}
	ac p, q;
	int i, x, y;
	p.step = 0;
	for(i = 0; i < L; i++)
	{
		p.pos[i] = CurPos[i];
	}
	que.push(p);
	while(!que.empty())
	{
		q = que.top();
		que.pop();
		if(q.pos[0] / 20 == 1 && q.pos[0] % 20 == 1)
		{
			printf("Case %d: %d\n",tc, q.step);
			return;
		}
		for(i = 0; i < L; i++)
		{
			stone[q.pos[i]/20][q.pos[i]%20] = true;
		}
		for(i = 1; i < L; i++)
		{
			p.pos[i] = q.pos[i-1];
		}
		p.step = q.step + 1;
		x = q.pos[0] / 20;
		y = q.pos[0] % 20;
		if(x + 1 <= n && stone[x+1][y] == false)
		{
			p.pos[0] = (x+1) * 20 + y;
			que.push(p);
		}
		if(x - 1 >= 1 && stone[x-1][y] == false)
		{
			p.pos[0] = (x-1) * 20 + y;
			que.push(p);
		}
		if(y + 1 <= m && stone[x][y+1] == false)
		{
			p.pos[0] = x * 20 + y + 1;
			que.push(p);
		}
		if(y - 1 >= 1 && stone[x][y-1] == false)
		{
			p.pos[0] = x * 20 + y - 1;
			que.push(p);
		}
		for(i = 0; i < L; i++)
		{
			stone[q.pos[i]/20][q.pos[i]%20] = false;
		}
	}
	printf("Case %d: -1\n", tc);
}
int main()
{
	int tc = 1;
	while(scanf("%d %d %d", &n, &m, &L) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		Input();
		Solve(tc);
		tc++;
	}
	return 0;
}