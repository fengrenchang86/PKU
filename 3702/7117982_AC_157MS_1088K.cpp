#include <iostream>
#include <queue>
using namespace std;
struct ac
{
	int a[4];
};
queue<ac>que;
ac s, t;
bool w[31][31][31][31];
void Input()
{
	char ch[100];
	int i;
	for (i = 0; i < 4; i++)
	{
		s.a[i] = 0;
		t.a[i] = 0;
	}
	scanf(" %s", &ch);
	for (i = 0; ch[i] != 0; i++)
	{
		if (ch[i] == '*')
		{
			s.a[i%4]++;
		}
	}
	scanf(" %s", &ch);
	for (i = 0; ch[i] != 0; i++)
	{
		if (ch[i] == '*')
		{
			t.a[i%4]++;
		}
	}
}
void Solve()
{
	memset(w, 0, sizeof(w));
	while (!que.empty())
	{
		que.pop();
	}
	que.push(s);
	ac x, y;
	int i;
	while (!que.empty())
	{
		x = que.front();
		que.pop();
		if (t.a[0] == x.a[0] && t.a[1] == x.a[1] && t.a[2] == x.a[2] && t.a[3] == x.a[3])
		{
			printf("YES\n");
			return;
		}
		for (i = 0; i < 4; i++)
		{
			if (x.a[i] && x.a[(i+2)%4])
			{
				y = x;
				y.a[i]--;
				y.a[(i+2)%4]--;
				y.a[(i+1)%4]++;
				y.a[(i+3)%4]++;
				if (!w[y.a[0]][y.a[1]][y.a[2]][y.a[3]])
				{
					w[y.a[0]][y.a[1]][y.a[2]][y.a[3]] = 1;
					que.push(y);
				}
			}
			if (x.a[i] && x.a[(i+1)%4])
			{
				y = x;
				y.a[i]--;
				y.a[(i+1)%4]--;
				y.a[(i+2)%4]++;
				if (!w[y.a[0]][y.a[1]][y.a[2]][y.a[3]])
				{
					w[y.a[0]][y.a[1]][y.a[2]][y.a[3]] = 1;
					que.push(y);
				}
			}
		}
	}
	printf("NO\n");
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		Input();
		Solve();
	}
	return 0;
}