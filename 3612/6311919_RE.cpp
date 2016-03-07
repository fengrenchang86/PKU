#include <iostream>
using namespace std;
#define INF 2000000000
int h[100100];
int dp[100100][110];
int n, c;
int low[100100], hight[100100];
int a[10010][110], b[100100][110];
int Getmin(int x, int y)
{
	return x < y ? x : y;
}
int Getmin(int x, int y, int z)
{
	return Getmin(x, y < z ? y : z);
}
int Getmax(int x, int y)
{
	return x > y ? x : y;
}
int Getmax(int x, int y, int z)
{
	return Getmax(x > y ? x : y, z);
}
unsigned char buff[65536];
short data[65536][30];
void ReadSth()
{
	FILE *fp;
	fp = fopen("e:\\tmp\\originalVolt.txt", "rb");
	fread(buff, 1, 65536, fp);
	fclose(fp);
	fp = fopen("E:\\tmp\\dig.txt", "w");
	int i, j, k;
	k = 0;
	i = 1;
	for (i = 1; k < 65536; i++)
	{
		for (j = 25; j >= 1; j--)
		{
			data[i][j] = (short)buff[k];
			k++;
		}
	}
	for (i = 1; i < 1000; i++)
	{
		fprintf(fp, "%04d", i);
		for (j = 1; j <= 25; j++)
		{
			fprintf(fp, " %3d", data[i][j]);
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	fclose(fp);
}
int main()
{
//	ReadSth();
	int i, j, k;
	scanf("%d %d", &n, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
	}
	a[0][h[0]-1] = INF;
	b[0][101] = INF;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= 100; j++)
		{
			a[i][j] = b[i][j] = INF;
			dp[i][j] = INF;
		}
	}
	for (j = h[0]; j <= 100; j++)
	{
		dp[0][j] = (j-h[0])*(j-h[0]);
		a[0][j] = Getmin(dp[0][j] - c * j, a[0][j-1]);
	}
	for (j = 100; j >= 1; j--)
	{
		b[0][j] = Getmin(dp[0][j] + c * j, b[0][j+1]);
	}
	for (i = 1; i < n; i++)
	{
		a[i][h[i]-1] = INF;
		b[i][101] = INF;
		for (j = h[i]; j <= 100; j++)
		{
			dp[i][j] = Getmin(a[i-1][j] + c * j, b[i-1][j] - c * j) + (j-h[i])*(j-h[i]);
			a[i][j] = Getmin(dp[i][j] - c * j, a[i][j-1]);
		}
		for (j = 100; j >= 1; j--)
		{
			b[i][j] = Getmin(dp[i][j] + c * j, b[i][j+1]);
		}
	}
	k = INF;
	for (j = h[i]; j <= 100; j++)
	{
		k = Getmin(k, dp[n-1][j]);
	}
	printf("%d\n", k);
	return 0;
}
