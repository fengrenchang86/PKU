#include <iostream>
using namespace std;
int father[30100];
int HuiHui[30100];
int misshh[30100];
int n;
void init()
{
	int i;
	for(i = 0; i <= n; i++)
	{
		father[i] = i;
		HuiHui[i] = 0;
		misshh[i] = 1;
	}
}
void FindHH(int x, int &cc)
{
	if(father[x] == x)
		cc = x;
	else
	{
		FindHH(father[x], cc);
		HuiHui[x] += HuiHui[father[x]];
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
			HuiHui[fx] = misshh[fy];
//			printf("HuiHui[%d]=%d\n",fx,HuiHui[fx]);
			misshh[fy] += misshh[fx];
			father[fx] = fy;
			misshh[fx] = 0;
		}
		else
		{
			scanf("%d",&x);
			FindHH(x, fx);
			printf("%d\n",HuiHui[x]);
		}
	}
}
int main ()
{
	while(scanf("%d",&n) != EOF)
//	scanf("%d",&n);
	{
		init();
		LoveHH();
	}
	return 0;
}