#include <iostream>
using namespace std;
void ShowAns(int lay)
{
	if (lay == 0)
	{
		printf("((A0|B0)|(A0|B0))");
	}
	else
	{
		printf("((A%d|B%d)|(", lay, lay);
		ShowAns(lay - 1);
		printf("|((A%d|A%d)|(B%d|B%d))))", lay, lay, lay, lay);
	}
}
int main()
{
	int x;
	while (scanf("%d", &x) != EOF)
	{
		ShowAns(x-1);
		printf("\n");
	}
	return 0;
}