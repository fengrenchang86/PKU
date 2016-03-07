#include <iostream>
using namespace std;
int in[2100];
int n;
int C, F1, F2, D;
int lowbit(int t)
{ 
	return t & (t^(t-1)); 
}
void modify(int pos,int num)

{
	while (pos<=n) 
	{
		in[pos]+=num;
		pos+=lowbit(pos);
	}
}
int query(int end)
{
	int sum=0;
	while (end>0) 
	{
		sum+=in[end];
		end-=lowbit(end);
	}
	return sum;
}
int main()
{
	memset(in, 0, sizeof(in));
	scanf("%d %d %d %d", &C, &F1, &F2, &D);
	int i, x, y, j;
	n = 2000;
	for (i = 0; i < C; i++)
	{
		scanf("%d %d", &x, &y);
		for (j = x; j <= y; j++)
		{
			modify(j, 1);
		}
	}
	y = query(D);
	for (i = D - 1; i > 1; i--)
	{
		x = query(i);
		if (y - x == F1 - F2)
		{
			printf("%d\n", i+1);
			break;
		}
	}
	return 0;
}