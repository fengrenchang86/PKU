#include<iostream>
#include<queue>
using namespace std;
#define inf 2000000000
struct ac
{
	int x, y;
	int value;
	bool operator()(ac &m1, ac &m2)
	{
		return m1.value > m2.value;
	}
};
int c[210][210];
int w[210][210];
int n;
priority_queue<ac, vector<ac>, ac>que;

void MissHH()
{
	int i,j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
	}

}
void init()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			w[i][j] = inf;
	}
}
int CanSeeHH(int nMin)
{
	while(!que.empty())
		que.pop();
	init();
	ac p, q;
	int k = c[0][0] > nMin ? c[0][0]:nMin;
	w[0][0] = k;
	p.x = 0;
	p.y = 0;
	p.value = k;
	que.push(p);
	while(!que.empty())
	{
		p = que.top();
		que.pop();
		if(p.value > w[p.x][p.y])
			continue;
		else if(p.x == n-1 && p.y == n-1)
			break;
		if(p.x > 0 && c[p.x-1][p.y] >= nMin)
		{
			k = c[p.x-1][p.y] > p.value ? c[p.x-1][p.y]:p.value;
			if(w[p.x-1][p.y] > k)
			{
				q.x = p.x-1;
				q.y = p.y;
				q.value = k;
				w[q.x][q.y] = k;
				que.push(q);
			}
		}
		if(p.x < n-1 && c[p.x+1][p.y] >= nMin)
		{
			k = c[p.x+1][p.y] > p.value ? c[p.x+1][p.y]:p.value;
			if(w[p.x+1][p.y] > k)
			{
				q.x = p.x+1;
				q.y = p.y;
				q.value = k;
				w[q.x][q.y] = k;
				que.push(q);
			}
		}
		if(p.y > 0 && c[p.x][p.y-1] >= nMin)
		{
			k = c[p.x][p.y-1] > p.value ? c[p.x][p.y-1]:p.value;
			if(w[p.x][p.y-1] > k)
			{
				q.x = p.x;
				q.y = p.y-1;
				q.value = k;
				w[q.x][q.y] = k;
				que.push(q);
			}
		}
		if(p.y < n-1 && c[p.x][p.y+1] >= nMin)
		{
			k = c[p.x][p.y+1] > p.value ? c[p.x][p.y+1]:p.value;
			if(w[p.x][p.y+1] > k)
			{
				q.x = p.x;
				q.y = p.y+1;
				q.value = k;
				w[q.x][q.y] = k;
				que.push(q);
			}
		}
	}
	return w[n-1][n-1];
}

void LoveHH()
{
	int i, j, CC = inf;
	for(i = 0; i <= 200; i++)
	{
		j = CanSeeHH(i);
		if(j != inf && j - i < CC)
			CC = j - i;
	}
	printf("%d\n\n", CC);
}
int main ()
{
	int cc, HH;
	scanf("%d",&HH);
	for(cc = 1; cc <= HH; cc++)
	{
		MissHH();
		printf("Scenario #%d:\n", cc);
		LoveHH();
	}
	return 0;
}