#include <iostream>
using namespace std;
bool a[10][10];
char ans[10000];

int main()
{
	int tc;
	scanf("%d", &tc);
	int n, k, i, t, nCarry = 0;
	while (tc--)
	{
		scanf("%d %d", &n, &k);
		memset(a, 0, sizeof(a));
		i = 1;
		ans[0] = char(k + '0');
		t = k;
		nCarry = 0;
		while (1)
		{
			t = (t * n + nCarry);
			nCarry = t / 10;
			t %= 10;
			if (nCarry == 0 && t == k)
			{
				break;
			}
			else if (nCarry == 0 && a[t][nCarry])
			{
				printf("0");
				i = -1;
				break;
			}
			ans[i] = char(t + '0');
			a[t][nCarry] = true;
			i++;
		}
		for (i--; i >= 0; i--)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
}