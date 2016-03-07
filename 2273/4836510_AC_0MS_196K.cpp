#include <iostream>
using namespace std;
int ans[100];

int Solve(int n)
{
	int i = 0;
	int j = 26;
	int k = 1;
	while(n >= j)
	{
		n -= j;
		j *= 26;
		k++;
	}
	for(i = 0; i < k; i++)
	{
		ans[i] = n % 26;
		n -= ans[i];
		n /= 26;
	}
	return k;
}
int main()
{
	char ch[100];
	int x, y, i, n;
	while(scanf("%s", ch) != EOF)
	{
		x = y = 0;
		for(i = 1; ch[i] != 'C'; i++)
		{
			x *= 10;
			x += (ch[i]-'0');
		}
		i++;
		while(ch[i] != NULL)
		{
			y *= 10;
			y += (ch[i]-'0');
			i++;
		}
		if(x == 0 && y == 0)
			break;
		n = Solve(y-1);
		for(i = n-1; i >= 0; i--)
		{
			printf("%c", ans[i]+'A');
		}
		printf("%d\n", x);
	}
	return 0;
}