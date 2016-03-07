#include <iostream>
#include <vector>
using namespace std;
char ch[100];
int n;
struct ac
{
	int nRow, nCol;
};
vector<ac>vec[30];
void Input()
{
	int i;
	for (i = 0; i < 26; i++)
	{
		vec[i].clear();
	}
	scanf(" %s", &ch);
}
int GetDist(ac p1, ac p2)
{
	int x1 = (1-p1.nRow + 2 * p1.nCol - 2);
	int x2 = (1-p2.nRow + 2 * p2.nCol - 2);
	int y1 = p1.nRow;
	int y2 = p2.nRow;
	return (x1-x2)*(x1-x2) + 3*(y1-y2)*(y1-y2);
}
void Solve()
{
	int i,j, k = 0;
	int d1, d2, d3;
	ac p;
	for (i = 1; i <= n; i++)
	{
		p.nRow = i;
		for (j = 0; j < i; j++)
		{
			p.nCol = j + 1;
			vec[ch[k]-'a'].push_back(p);
			k++;
		}
	}
	k = 0;
	for (i = 0; i < 26; i++)
	{
		if (vec[i].size() != 3)
		{
			continue;
		}
		d1 = GetDist(vec[i][0], vec[i][1]);
		d2 = GetDist(vec[i][1], vec[i][2]);
		d3 = GetDist(vec[i][2], vec[i][0]);
		if (d1 == d2 && d2 == d3)
		{
			printf("%c",(char)(i+'a'));
			k++;
		}
	}
	if (k == 0)
	{
		printf("LOOOOOOOOSER!");
	}
	printf("\n");
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	return 0;
}