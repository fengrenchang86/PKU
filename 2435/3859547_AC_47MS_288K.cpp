#include<iostream>
#include <string>
#include <queue>
using namespace std;
#define inf 2000000000;

struct ac
{
	int step;
	int x, y;
	int px, py;
	string str;
	ac(){str = "";}
};
char b[142][142];
int w[142][142];
int n, m;
int bx, by, ex, ey;
queue<ac>que;
char MeetHH(int x1, int y1, int x2, int y2)
{
	if(x1 == x2 && y1 > y2)
		return 'W';
	else if(x1 == x2 && y1 < y2)
		return 'E';
	else if(y1 == y2 && x1 > x2)
		return 'N';
	else
		return 'S';
}
void MissHH()
{
	scanf("%d %d", &n, &m);
	n = 2*n-1;
	m = 2*m-1;
	int i, j;
	for(i = 0; i < n; i++)
		scanf(" %s", &b[i]);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			w[i][j] = inf;
			if(b[i][j] == 'S')
			{
				bx = i;
				by = j;
			}
			else if(b[i][j] == 'E')
			{
				b[i][j] = '+';
				ex = i;
				ey = j;
			}
		}
	}
}
void LoveHH()
{
	ac p, q;
	p.x = bx;
	p.y = by;
	p.px = p.x;
	p.py = p.y;
	p.step = 0;
	w[p.x][p.y] = p.step;
	que.push(p);
	while(!que.empty())
	{
		p = que.front();
		que.pop();
		if(w[p.x][p.y] < p.step)
			continue;
		if(p.x == ex && p.y == ey)
			break;
		if(p.x-1 >= 0 && b[p.x-1][p.y] != '.' && b[p.x-1][p.y] != '-')
		{
			q.x = p.x-1;
			q.y = p.y;
			if(b[q.x][q.y] == '+')
			{
				q.str = p.str + MeetHH(p.px, p.py, q.x, q.y);
				q.step = p.step;
				q.px = q.x;
				q.py = q.y;
			}
			else
			{
				q.str = p.str;
				q.step = p.step + 1;
				q.px = p.px;
				q.py = p.py;
			}
			if(w[q.x][q.y] > q.step)
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
		if(p.x+1 < n && b[p.x+1][p.y] != '.' && b[p.x+1][p.y] != '-')
		{
			q.x = p.x+1;
			q.y = p.y;
			if(b[q.x][q.y] == '+')
			{
				q.str = p.str + MeetHH(p.px, p.py, q.x, q.y);
				q.step = p.step;
				q.px = q.x;
				q.py = q.y;
			}
			else
			{
				q.str = p.str;
				q.step = p.step + 1;
				q.px = p.px;
				q.py = p.py;
			}
			if(w[q.x][q.y] > q.step)
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
		if(p.y-1 >= 0 && b[p.x][p.y-1] != '.' && b[p.x][p.y-1] != '|')
		{
			q.x = p.x;
			q.y = p.y-1;
			if(b[q.x][q.y] == '+')
			{
				q.str = p.str + MeetHH(p.px, p.py, q.x, q.y);
				q.step = p.step;
				q.px = q.x;
				q.py = q.y;
			}
			else
			{
				q.str = p.str;
				q.step = p.step + 1;
				q.px = p.px;
				q.py = p.py;
			}
			if(w[q.x][q.y] > q.step)
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
		if(p.y+1 < m && b[p.x][p.y+1] != '.' && b[p.x][p.y+1] != '|')
		{
			q.x = p.x;
			q.y = p.y+1;
			if(b[q.x][q.y] == '+')
			{
				q.str = p.str + MeetHH(p.px, p.py, q.x, q.y);
				q.step = p.step;
				q.px = q.x;
				q.py = q.y;
			}
			else
			{
				q.str = p.str;
				q.step = p.step + 1;
				q.px = p.px;
				q.py = p.py;
			}
			if(w[q.x][q.y] > q.step)
			{
				w[q.x][q.y] = q.step;
				que.push(q);
			}
		}
	}
	int i = 0, j = 1, k = p.str.length();
	while(i < k)
	{
		printf("%c",p.str[i]);
		j = 1;
		while(i + 1 < k && p.str[i] == p.str[i+1])
		{
			i++;
			j++;
		}
		printf(" %d\n",j);
		i++;
	}
	//cout<<p.str<<endl;
}
int main ()
{
	MissHH();
	LoveHH();
	return 0;
}