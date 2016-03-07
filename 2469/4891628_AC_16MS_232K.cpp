#include <iostream>
using namespace std;
int *a, *b, *c;
int	shuffle[102][53];
int n;
void Input()
{
	int i, j;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= 52; j++)
		{
			scanf("%d", &shuffle[i][j]);
		}
	}
	a = new int[53];
	b = new int[53];
	c = NULL;
	for(i = 1; i <= 52; i++)
		a[i] = i;
}

void Print(int data)
{
	int nType = 1;
	while(data > 13)
	{
		data -= 13;
		nType ++;
	}
	if(data <= 9)
		printf("%d of ", data + 1);
	else if(data == 10)
		printf("Jack of ");
	else if(data == 11)
		printf("Queen of ");
	else if(data == 12)
		printf("King of ");
	else if(data == 13)
		printf("Ace of ");
	if(nType == 1)
		printf("Clubs\n");
	else if(nType == 2)
		printf("Diamonds\n");
	else if(nType == 3)
		printf("Hearts\n");
	else
		printf("Spades\n");
}

void Solve(int k)
{
	int i;
	for(i = 1; i <= 52; i++)
	{
		b[i] = a[shuffle[k][i]];
	}
	c = a;
	a = b;
	b = c;
	for(i = 1; i <= 52; i++)
	{
		Print(a[i]);
	}
	printf("\n");
}

int main()
{
	int k;
	scanf("%d", &n);
	Input();
	while(scanf("%d", &k) != EOF)
	{
		Solve(k);
	}
	return 0;
}