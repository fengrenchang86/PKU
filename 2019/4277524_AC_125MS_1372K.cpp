#include <iostream>
using namespace std;
#define INF 1000000000
#define N 260
struct ac
{
	int acMin, acMax;
}t[N][N];
int a[N][N];
int n, m, K;
int GetMax(int x, int y)
{
	return x > y ? x:y;
}
int GetMax(int x, int y, int z)
{
	return GetMax(x, GetMax(y, z));
}
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
int GetMin(int x, int y, int z)
{
	return GetMin(x, GetMin(y, z));
}
void Input()
{
	scanf("%d %d %d", &n, &m, &K);
	int i, j;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			t[i][j].acMax = t[i][j].acMin = a[i][j];
		}
	}
}
void Solve()
{
	int i, j, k, x, y;
	for(k = 2; k <= m; k++)
	{
		for(i = n; i >= k; i--)
		{
			for(j = n; j >= k; j--)
			{
				t[i][j].acMin = GetMin(GetMin(t[i-1][j].acMin, a[i][j]), t[i][j-1].acMin, t[i-1][j-1].acMin);
				t[i][j].acMax = GetMax(GetMax(t[i-1][j].acMax, a[i][j]), t[i][j-1].acMax, t[i-1][j-1].acMax);
			}
		}
	}
// 	for(i = 1; i <= n; i++)
// 	{
// 		for(j = 1; j <= n; j++)
// 			printf("%3d ", a[i][j]);
// 		printf("\n");
// 	}
// 	cout<<"min"<<endl;
// 	for(i = 1; i <= n; i++)
// 	{
// 		for(j = 1; j <= n; j++)
// 			printf("%3d ", t[i][j].acMin);
// 		printf("\n");
// 	}
// 	cout<<"max"<<endl;
// 	for(i = 1; i <= n; i++)
// 	{
// 		for(j = 1; j <= n; j++)
// 			printf("%3d ", t[i][j].acMax);
// 		printf("\n");
// 	}
	while(K--)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", t[x+m-1][y+m-1].acMax - t[x+m-1][y+m-1].acMin);
	}
}
int main()
{
// 	char ch[100];
// 	strcpy(ch, "cornfld.4.in");
// 	FILE *fp = fopen(ch, "r");
// 	fp = freopen(ch, "r", stdin);
	Input();
	Solve();
	return 0;
}