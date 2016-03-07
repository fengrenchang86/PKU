#include<iostream>
using namespace std;
struct ac
{
	int x, y;
	char dir;
}robot[120];
int a[120][120];
bool flag;
int A, B, n, m;

void init()
{
	int i, j;
	for(i = 0; i <= 110; i++)
	{
		for(j = 0; j <= 110; j++)
			a[i][j] = -1;
	}
}
void MissHH()
{
	int i;
	scanf("%d %d", &A, &B);
	scanf("%d %d", &n, &m);
	init();
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d %c", &robot[i].x, &robot[i].y, &robot[i].dir);
		a[robot[i].x][robot[i].y] = i;
	}
}
int MeetHH(int id)
{
	int dirx, diry, k;
	int x = robot[id].x;
	int y = robot[id].y;
	char chDir = robot[id].dir;
	if(chDir == 'N')
	{
		dirx = 0;
		diry = 1;
	}
	else if(chDir == 'S')
	{
		dirx = 0;
		diry = -1;
	}
	else if(chDir == 'W')
	{
		dirx = -1;
		diry = 0;
	}
	else
	{
		dirx = 1;
		diry = 0;
	}
	if(x + dirx == 0 || x+dirx == A+1 || y+diry == 0 || y + diry == B+1)
		return -2;
	k = a[x + dirx][y + diry];
	a[x+dirx][y+diry] = id;
	robot[id].x = x+dirx;
	robot[id].y = y+diry;
	a[x][y] = -1;
	return k;
}
int TurnToHH(int id, char chDir)
{
	if(chDir == 'L')
	{
		if(robot[id].dir == 'N')
			robot[id].dir = 'W';
		else if(robot[id].dir == 'W')
			robot[id].dir = 'S';
		else if(robot[id].dir == 'S')
			robot[id].dir = 'E';
		else
			robot[id].dir = 'N';
	}
	else
	{
		if(robot[id].dir == 'W')
			robot[id].dir = 'N';
		else if(robot[id].dir == 'S')
			robot[id].dir = 'W';
		else if(robot[id].dir == 'E')
			robot[id].dir = 'S';
		else
			robot[id].dir = 'E';
	}
	return 0;
}
void LoveHH()
{
	int i, j;
	int x, y, crash = -1, incrash = -1;
	char chOper;
	flag = false;
	for(i = 0; i < m; i++)
	{
		scanf(" %d %c %d", &x, &chOper, &y);
		if(flag)
			continue;
		if(chOper != 'F')
		{
			for(j = 0; j < y; j++)
				TurnToHH(x, chOper);
		}
		else
		{
			for(j = 0; j < y; j++)
			{
				incrash = MeetHH(x);
				if(incrash != -1)
				{
					crash = x;
					flag = true;
					break;
				}
			}
		}
	}
	if(flag == false)
		printf("OK\n");
	else if(incrash == -2)
		printf("Robot %d crashes into the wall\n", crash);
	else
		printf("Robot %d crashes into robot %d\n", crash, incrash);
}
int main ()
{
	int HH = 1;
	scanf("%d", &HH);
	while(HH--)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}