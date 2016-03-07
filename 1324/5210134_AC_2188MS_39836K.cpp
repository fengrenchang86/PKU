#include <iostream>
#include <queue>
using namespace std;

int n, m, t, L;
bool stone[22][22];
int w[10000000];
#define INF 2000000000
int CurPos[10][2];
unsigned int nBeginStatue;
int nx, ny;
queue<int>que;
unsigned int GetStatue()
{
	int i;
	unsigned int nFistPos = CurPos[0][0] * 20 + CurPos[0][1];
	unsigned int nDir = 0;
	for(i = L-1; i >= 1; i--)
	{
		nDir <<= 2;
		if(CurPos[i][0] == CurPos[i-1][0] + 1)		//down
			nDir |= 2;
		else if(CurPos[i][0] == CurPos[i-1][0] - 1)	//up
			nDir |= 1;
		else if(CurPos[i][1] == CurPos[i-1][1] + 1)	//right
			nDir |= 3;		
	}
	unsigned int nStatue = nDir;
	nStatue <<= 9;
	nStatue |= nFistPos;
	return nStatue;
}
void Input()
{
	memset(w, 0, sizeof(w));
	int i, x, y;
	for(i = 0; i < L; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		CurPos[i][0] = x;
		CurPos[i][1] = y;
	}
	nBeginStatue = GetStatue();
	scanf("%d", &t);
	memset(stone, false, sizeof(stone));
	for(i = 0; i < t; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		stone[x][y] = true;
	}
}
void SetStone(int nStatue)
{
	int x, y, i;
	unsigned int z = (nStatue & 0x1FF);
	x = z / 20;
	y = z % 20;
	nx = x;
	ny = y;
	nStatue >>= 9;
	stone[x][y] = !stone[x][y];
	for(i = 1; i < L; i++)
	{
		if((nStatue & 0x3) == 1)
			x--;
		else if((nStatue & 0x3) == 2)
			x++;
		else if((nStatue & 0x3) == 3)
			y++;
		else
			y--;
		nStatue >>= 2;
		stone[x][y] = !stone[x][y];
	}
}
void Solve(int tc)
{
	while(!que.empty())
	{
		que.pop();
	}
	que.push(nBeginStatue);
	int p, q;
	int nStep;
	int nStatue;
	unsigned int z;
	while(!que.empty())
	{
		p = que.front();
		que.pop();
		nStatue = (p & 0x7FFFFF);
		nStep = (p >>= 23);
		if(w[nStatue] != 0 && w[nStatue] < nStep)
			continue;
		nStep ++;
		SetStone(nStatue);
		if(nx == 0 && ny == 0)
		{
			printf("Case %d: %d\n", tc, nStep - 1);
			return;
		}
		if(nx + 1 < n && !stone[nx + 1][ny])
		{
			z = (nx+1) * 20 + ny;
			q = (nStatue << 2);
			q &= (0x7FF800);
			q |= (1 << 9);
			q |= z;
			if(w[q] == 0 || w[q] > nStep)
			{
				w[q] = nStep;
				q |= (nStep << 23);
				que.push(q);
			}
		}
		if(nx - 1 >= 0 && !stone[nx - 1][ny])
		{
			z = (nx - 1) * 20 + ny;
			q = (nStatue << 2);
			q &= (0x7FF800);
			q |= (2 << 9);
			q |= z;
			if(w[q] == 0 || w[q] > nStep)
			{
				w[q] = nStep;
				q |= (nStep << 23);
				que.push(q);
			}
		}
		if(ny + 1 < m && !stone[nx][ny + 1])
		{
			z = nx * 20 + ny + 1;
			q = (nStatue << 2);
			q &= (0x7FF800);
			
			q |= z;
			if(w[q] == 0 || w[q] > nStep)
			{
				w[q] = nStep;
				q |= (nStep << 23);
				que.push(q);
			}
		}
		if(ny - 1 >= 0 && !stone[nx][ny - 1])
		{
			z = nx * 20 + ny - 1;
			q = (nStatue << 2);
			q &= (0x7FF800);
			q |= (3 << 9);
			q |= z;
			if(w[q] == 0 || w[q] > nStep)
			{
				w[q] = nStep;
				q |= (nStep << 23);
				que.push(q);
			}
		}
		SetStone(nStatue);
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