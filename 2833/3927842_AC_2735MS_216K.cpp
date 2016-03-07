
#include<iostream>
#include <algorithm>
#include<queue>
using namespace std;

int n, x, y;
int hui[20];
int chang[20];


void LoveHH()
{
	int i, j, k, data;
	int lx = 0, ly = 0;
	__int64 sum = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &data);
		sum += __int64(data);
		hui[lx++] = data;
		chang[ly++] = data;
		for(j = 1; j < lx; j++)
		{
			if(hui[j-1] < hui[j])
			{
				k = hui[j-1];
				hui[j-1] = hui[j];
				hui[j] = k;
			}
		}
		for(j = 1; j < ly; j++)
		{
			if(chang[j-1] > chang[j])
			{
				k = chang[j-1];
				chang[j-1] = chang[j];
				chang[j] = k;
			}
		}
		if(lx > x)
			lx--;
		if(ly > y)
			ly--;
	}
	for(i = 0; i < y; i++)
		sum -= chang[i];
	for(i = 0; i < x; i++)
		sum -= hui[i];
	double HH = double(sum) / double(n - x - y);
	printf("%.6lf\n", HH);
}
int main ()
{
	while(scanf("%d%d%d", &x, &y, &n) != EOF)
	{
		if(n == x && x == y && y == 0)
			break;
		LoveHH();
	}
	return 0;
}