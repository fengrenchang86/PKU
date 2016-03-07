#include<iostream>
using namespace std;
int n, m;
void Input()
{
	char ch;
	int i, k, x, y, z;
	x = y = z = 0;
	for (i = 0; i < n; i++)
	{
		scanf(" %c", &ch);
		if (ch == 'F')
		{
			x++;
		}
		else if (ch == 'C')
		{
			y++;
		}
		else
			z++;
	}
	if (x * y * z != 0)
	{
		printf("%d\n", n);
	}
	else if (x * y != 0)
	{
		printf("%d\n", x);
	}
	else if (y * z != 0)
	{
		printf("%d\n", y);
	}
	else if (z * x != 0)
	{
		printf("%d\n", x);
	}
	else if (x != 0)
	{
		printf("%d\n", x);
	}
	else if (y != 0)
	{
		printf("%d\n", y);
	}
	else
	{
		printf("%d\n", z);
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		Input();
	}
	return 0;
}