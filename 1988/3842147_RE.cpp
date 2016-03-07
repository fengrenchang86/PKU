#include<iostream>
using namespace std;
int father[31100];
int huihui[31100];
int chang[31100];
int n;
void init()
{
	int i;
	for(i = 0; i <= n; i++)
	{
		father[i] = i;
		huihui[i] = 0;
		chang[i] = 1;
	}
}
void FindHH(int x, int &cc)
{
	if(father[x] == x)
		cc = x;
	else
	{
		FindHH(father[x], cc);
		huihui[x] += huihui[father[x]];
		father[x] = cc;
	}
}
void LoveHH()
{
	int i;
	int x, y, fx, fy;
	char ch;
	for(i = 0; i < n; i++)
	{
		scanf(" %c", &ch);
		if(ch == 'M')
		{
			scanf("%d%d",&x, &y);
			FindHH(x, fx);
			FindHH(y, fy);
			chang[fy] += chang[fx];
			father[fx] = fy;
			huihui[fx] += chang[fx];
			chang[fx] = 0;
		}
		else
		{
			scanf("%d",&x);
			FindHH(x, fx);
			printf("%d\n",huihui[x]);
		}
	}
}
int main ()
{
//	while(scanf("%d",&n) != EOF)
	scanf("%d",&n);
	{
		init();
		LoveHH();
	}
	return 0;
}