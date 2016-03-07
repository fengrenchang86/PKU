#include <iostream>
using namespace std;
struct ac
{
	bool val;
	bool full;
	bool expand;
	bool vex;
	bool fan;
}tree[400000];
void Init()
{
	int i;
	for (i = 0; i < 400000; i++)
	{
		tree[i].val = false;
		tree[i].full = true;
		tree[i].expand = false;
		tree[i].vex = false;
		tree[i].fan = false;
	}
}
int n = 65536;
int m;
void Reverse(int i, int nBegin, int nEnd, int x, int y, bool vx, bool vy)
{
	int nMid = (nBegin + nEnd) / 2;
	
	if (tree[i].full == true && nBegin == x && nEnd == y && vx)
	{
		if (tree[i].fan)
		{
			tree[i].fan = false;
		}
		else
		{
			tree[i].val = !tree[i].val;
			tree[i].expand = true;
			tree[i].vex = tree[i].val;
		}
		return;
	}
	if (tree[i].fan)
	{
		Reverse(i * 2, nBegin, nMid, nBegin, nMid, true, false);
		Reverse(i * 2 + 1, nMid, nEnd, nMid, nEnd, true, false);
		tree[i].fan = false;
	}
	if (x == y && vy == false)
	{
		return;
	}
	if (nBegin == nEnd - 1)
	{
		if (nBegin == x && nEnd == y)
		{
			if (vx)
			{
				tree[i].vex = !tree[i].vex;
			}
			tree[i].val = !tree[i].val;
			if (tree[i].val == tree[i].vex)
			{
				tree[i].full = true;
			}
			else
				tree[i].full = false;
		}
		else
		{
			tree[i].vex = !tree[i].vex;
			if (tree[i].vex == tree[i].val)
			{
				tree[i].full = true;
			}
			else
				tree[i].full = false;
		}
		return;
	}
	if (tree[i].expand == true && tree[i].full == true)
	{
		tree[i*2].expand = true;
		tree[i*2].full = true;
		tree[i*2].val = tree[i].val;
		tree[i*2].vex = tree[i].val;
		tree[i*2+1].expand = true;
		tree[i*2+1].full = true;
		tree[i*2+1].val = tree[i].val;
		tree[i*2+1].vex = tree[i].val;
		tree[i].expand = false;
	}
	if (nBegin == x && nEnd == y && vx && !vy)
	{
		tree[i].fan = true;
		tree[i*2].fan = tree[i*2+1].fan = false;
		return;
	}
	if (y < nMid)
	{
		Reverse(i*2, nBegin, nMid, x, y, vx, vy);
	}
	else if (x >= nMid)
	{
		Reverse(i*2+1, nMid, nEnd, x, y, vx, vy);
	}
	else
	{
		Reverse(i*2, nBegin, nMid, x, nMid, vx, false);
		Reverse(i*2+1, nMid ,nEnd, nMid, y, true, vy);
	}
	if (tree[i*2].full && tree[i*2+1].full && tree[i*2].val == tree[i*2+1].val)
	{
		tree[i].full = true;
		tree[i].val = tree[i*2].val;
	}
	else
	{
		tree[i].full = false;
	}
}
void Insert(int i, int nBegin, int nEnd, int x, int y, bool val, bool vx, bool vy)
{
	int nMid = (nBegin + nEnd) / 2;
	if (tree[i].fan)
	{
		Reverse(i * 2, nBegin, nMid, nBegin, nMid, true, false);
		Reverse(i * 2 + 1, nMid, nEnd, nMid, nEnd, true, false);
		tree[i].fan = false;
	}
	if (nBegin == x && nEnd == y)
	{
		tree[i].val = val;
		if (vx == true || tree[i].vex == val)
		{
			tree[i].expand = true;
			tree[i].full = true;
			tree[i].vex = val;
		}
		else
		{
			tree[i].expand = false;
			tree[i].full = false;
		}
		return;
	}
	else if (nBegin == nEnd - 1)
	{
		if (vy == false)
		{
			return;
		}
		tree[i].vex = val;
		if (tree[i].vex == tree[i].val)
		{
			tree[i].full = true;
		}
		else
		{
			tree[i].full = false;
		}
		return;
	}
	if (tree[i].expand == true && tree[i].full == true)
	{
		tree[i*2].expand = true;
		tree[i*2].full = true;
		tree[i*2].val = tree[i].val;
		tree[i*2].vex = tree[i].val;
		tree[i*2+1].expand = true;
		tree[i*2+1].full = true;
		tree[i*2+1].val = tree[i].val;
		tree[i*2+1].vex = tree[i].val;
		tree[i].expand = false;
	}
	if (tree[i].full && tree[i].val == val)
	{
		return;
	}
	if (y < nMid)
	{
		Insert(i * 2, nBegin, nMid, x, y, val, vx, vy);
	}
	else if (x >= nMid)
	{
		Insert(i * 2 + 1, nMid, nEnd, x, y, val, vx, vy);
	}
	else
	{
		Insert(i * 2, nBegin, nMid, x, nMid, val, vx, false);
		Insert(i * 2 + 1, nMid, nEnd, nMid, y, val, true, vy);
	}
	if (tree[i*2].full && tree[i*2+1].full && tree[i*2].val == tree[i*2+1].val)
	{
		tree[i].full = true;
		tree[i].val = tree[i*2].val;
	}
	else
	{
		tree[i].full = false;
	}
}
int nx = -1, ny;
bool bx, by;
void Final(int i, int nBegin, int nEnd)
{
	int nMid = (nBegin + nEnd) / 2;
	if (tree[i].fan)
	{
		Reverse(i * 2, nBegin, nMid, nBegin, nMid, true, false);
		Reverse(i * 2 + 1, nMid, nEnd, nMid, nEnd, true, false);
		tree[i].fan = false;
	}
	if (nBegin == nEnd - 1)
	{
		if (tree[i].full && !tree[i].val)
		{
			return;
		}
		if (nx < 0)
		{
			nx = nBegin;
			if (tree[i].full)
			{
				ny = nEnd;
				by = false;
				bx = true;
			}
			else if (tree[i].vex == true)
			{
				ny = nBegin;
				by = true;
				bx = true;
			}
			else
			{
				ny = nEnd;
				by = false;
				bx = false;
			}
		}
		else
		{
			if (nBegin != ny || tree[i].vex == false)
			{
				if (m == 0)
				{
					m++;
				}
				else
					printf(" ");
				if (bx)
				{
					printf("[");
				}
				else
				{
					printf("(");
				}
				printf("%d,%d", nx, ny);
				if (by)
				{
					printf("]");
				}
				else
				{
					printf(")");
				}
				nx = nBegin;
				if (tree[i].full)
				{
					ny = nEnd;
					by = false;
					bx = true;
				}
				else if (tree[i].vex == true)
				{
					ny = nBegin;
					by = true;
					bx = true;
				}
				else
				{
					ny = nEnd;
					by = false;
					bx = false;
				}
			}
			else
			{
				if (tree[i].full)
				{
					ny = nEnd;
					by = false;
				}
				else if (tree[i].vex == true)
				{
					ny = nBegin;
					by = true;
				}
				else
				{
					ny = nEnd;
					by = false;
				}
			}
		}
		return;
	}
	if (tree[i].expand == true && tree[i].full == true)
	{
		tree[i*2].expand = true;
		tree[i*2].full = true;
		tree[i*2].val = tree[i].val;
		tree[i*2].vex = tree[i].val;
		tree[i*2+1].expand = true;
		tree[i*2+1].full = true;
		tree[i*2+1].val = tree[i].val;
		tree[i*2+1].vex = tree[i].val;
		tree[i].expand = false;
	}
	Final(i * 2, nBegin, nMid);
	Final(i * 2 + 1, nMid, nEnd);
}
void ShowAns()
{
	nx = -1;
	Final(1, 0, n);
	if (nx < 0)
	{
		printf("empty set");
	}
	else
	{
		if (m > 0)
		{
			printf(" ");
		}
		if (bx)
		{
			printf("[");
		}
		else
		{
			printf("(");
		}
		printf("%d,%d", nx, ny);
		if (by)
		{
			printf("]");
		}
		else
		{
			printf(")");
		}
	}
	printf("\n");
}
int main()
{
	m = 0;
	Init();
	int i;
	char ch;
	char str[10000];
	bool ix, iy;
	int xx, yy;
	while (scanf(" %c %s", &ch, &str) != EOF)
	{
		if (str[0] == '(')
		{
			ix = false;
		}
		else
		{
			ix = true;
		}
		if (str[strlen(str)-1] == ')')
		{
			iy = false;
		}
		else
			iy = true;
		i = 1;
		xx =  yy = 0;
		while (str[i] != ',')
		{
			xx *= 10;
			xx += (str[i] - '0');
			i++;
		}
		i++;
		while(str[i] >= '0' && str[i] <= '9')
		{
			yy *= 10;
			yy += (str[i] - '0');
			i++;
		}
		if (ch == 'U')
		{
			Insert(1, 0, n, xx, yy, 1, ix, iy);
		}
		else if (ch == 'I')
		{
			if (0 <= xx && !(xx == 0 && ix == true))
			{
				Insert(1, 0, n, 0, xx, 0, true, !ix);
			}
			Insert(1, 0, n, yy, n, 0, !iy, true);
		}
		else if (ch == 'D')
		{
			Insert(1, 0, n, xx, yy, 0, ix, iy);
		}
		else if (ch == 'C')
		{
			if (0 <= xx && !(xx == 0 && ix == true))
			{
				Insert(1, 0, n, 0, xx, 0, true, !ix);
			}
			Insert(1, 0, n, yy, n, 0, !iy, true);
			Reverse(1, 0, n, xx, yy, ix, iy);
		}
		else
		{
			Reverse(1, 0, n, xx, yy, ix, iy);
		}
	}
	ShowAns();
	return 0;
}