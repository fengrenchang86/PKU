#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define inf 2000000000
struct ac
{
	int value;
	int step;
	int x,y;
	bool operator()(ac &m1, ac &m2)
	{
		if(m1.value != m2.value)
			return m1.value > m2.value;
		else
			return m1.step > m2.step;
	}
};
int endX, endY, n;
int w[1010][1010];
bool b[1010][1010];
priority_queue<ac,vector<ac>,ac>que;
void input()
{
	int i, j, x, y;
	scanf("%d %d",&endX, &endY);
	endX += 502;
	endY += 502;
	scanf("%d",&n);
	for(i = 0; i < 1010; i++)
	{
		for(j = 0; j < 1010; j++)
		{
			w[i][j] = inf;
			b[i][j] = false;
		}
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d%d",&x, &y);
		x += 502;
		y += 502;
		b[x][y] = true;
	}
}
void solve ()
{
	ac p, q;
	p.x = 502;
	p.y = 502;
	p.step = 0;
	p.value = abs(endX-p.x)+abs(endY-p.y);
	que.push(p);
	w[502][502] = 0;
	while( !que.empty())
	{
		p = que.top();
		que.pop();
		if(w[p.x][p.y] < p.step)
			continue;
		if(p.x == endX && p.y == endY)
			break;
		if(!b[p.x-1][p.y] && w[p.x-1][p.y] > p.step+1)
		{
			q.x = p.x-1;
			q.y = p.y;
			q.step = p.step+1;
			q.value = q.step+abs(endX-q.x)+abs(endY-q.y);
			w[q.x][q.y] = q.step;
			que.push(q);
		}
		if(!b[p.x+1][p.y] && w[p.x+1][p.y] > p.step+1)
		{
			q.x = p.x+1;
			q.y = p.y;
			q.step = p.step+1;
			q.value = q.step+abs(endX-q.x)+abs(endY-q.y);
			w[q.x][q.y] = q.step;
			que.push(q);
		}
		if(!b[p.x][p.y-1] && w[p.x][p.y-1] > p.step+1 )
		{
			q.x = p.x;
			q.y = p.y-1;
			q.step = p.step+1;
			q.value = q.step + abs(endX-q.x)+abs(endY-q.y);
			w[q.x][q.y] = q.step;
			que.push(q);
		}
		if(!b[p.x][p.y+1] && w[p.x][p.y+1] > p.step+1)
		{
			q.x = p.x;
			q.y = p.y+1;
			q.step = p.step+1;
			q.value = q.step+abs(endX-q.x)+abs(endY-q.y);
			w[q.x][q.y] = q.step;
			que.push(q);
		}
	}
	printf("%d\n",w[endX][endY]);
}
int main ()
{
	input();
	solve();
	return 0;
}