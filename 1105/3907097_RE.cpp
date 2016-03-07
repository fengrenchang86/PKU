#include<iostream>
using namespace std;
int order[10];
int power[20];
char tree[20];
int n;
void init()
{
	int i;
	power[0] = 1;
	for(i = 1; i <= 30; i++)
		power[i] = power[i-1] * 2;
}
int GetNum(char *str)
{
	int i = 0;
	int k = 0;
	while(str[i] < '0' || str[i] > '9')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += (str[i]-'0');
		i++;
	}
	return k;
}
void MissHH()
{
	int i;
	char str[20];
	for(i = 0; i < n; i++)
	{
		scanf(" %s", &str);
		order[i] = GetNum(str)-1;
	}
	scanf("%s", &tree);
}
void LoveHH()
{
	int i, j, m, k;
	char OtherTree[20];
	char FinalTree[20];
	char ans[20];
	int d = 0;
	scanf("%d", &m);
	for(i = 0; i < m; i++)
	{
		scanf("%s", &OtherTree);
		for(j = 0; j < n; j++)
			FinalTree[j] = OtherTree[order[j]];
		k = 0;
		for(j = 0; j < n; j++)
		{
			k += (FinalTree[j]-'0')*power[n-j-1];
		}
		ans[d++] = tree[k];
	}
	ans[d] = NULL;
	printf("%s\n\n", ans);
}

int main ()
{
	int HH = 1;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
			break;
		MissHH();
		printf("S-Tree #%d:\n", HH++);
		LoveHH();
	}
	return 0;
}