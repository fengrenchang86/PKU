
#include <iostream>
using namespace std;
int n, ans;
char board[6][6];
void dfs(int z, int data)
{
	if(z == n*n)
	{
		if(data > ans)
			ans = data;
		return;
	}
	int x, y;
	x = z / n;
	y = z % n;
	if(board[x][y] == 'X')
	{
		dfs(z+1, data);
		return;
	}
	int i, j;
	for(i = x - 1; i >= 0; i--)
	{
		if(board[i][y] == 'X' || board[i][y] == 'a')
			break;
	}
	for(j = y - 1; j >= 0; j--)
	{
		if(board[x][j] == 'X' || board[x][j] == 'a')
			break;
	}
	if((board[i][y] == 'X' || i == -1) && (board[x][j] == 'X' || j == -1))
	{
		board[x][y] = 'a';
		dfs(z + 1, data + 1);
		board[x][y] = '.';
	}
	dfs(z+1, data);
}

void Solve()
{
	int i;
	for(i = 0; i < n; i++)
		scanf(" %s", board[i]);
	ans = 0;
	dfs(0, 0);
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Solve();
	}
	return 0;
}