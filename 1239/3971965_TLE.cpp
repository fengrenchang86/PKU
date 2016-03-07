#include<iostream>
#include<string>
using namespace std;
char str[100];
char ans[100][100];
char stack[100][100];
int num;

int cmp(char *cha, char *chb)
{
	int i = 0, j = 0, x, y;
	while(cha[i] == '0')
		i++;
	x = i;
	while(chb[j] == '0')
		j++;
	y = j;
	while(cha[i] != NULL && chb[j] != NULL)
	{
		i++;
		j++;
	}
	if(cha[i] != NULL && chb[j] == NULL)
		return 1;
	else if(cha[i] == NULL && chb[j] != NULL)
		return -1;
	i = x;
	j = y;
	while(cha[i] != NULL)
	{
		if(cha[i] > chb[j])
			return 1;
		else if(cha[i] < chb[j])
			return -1;
		i++;
		j++;
	}
	return 0;
}
bool cmp()
{
	int i;
	for(i = 0; i < num; i++)
	{
		if(cmp(ans[i], stack[i]) == -1)
			return true;
	}
	return false;
}
void dfs(int lay, int pos)
{
	int i;
	if(str[pos] == NULL)
	{
		if(num == -1 || cmp(ans[num-1], stack[lay-1]) == 1)
		{
			num = lay;
			for(i = 0; i < num; i++)
				strcpy(ans[i], stack[i]);
		}
		else if(cmp(ans[num-1], stack[lay-1]) == 0 && cmp())
		{
			num = lay;
			for(i = 0; i < num; i++)
				strcpy(ans[i], stack[i]);
		}
		return;
	}
	int j = 0;
	for(i = pos; str[i] != NULL; i++)
	{
		stack[lay][j++] = str[i];
		stack[lay][j] = NULL;
		if(lay == 0 || cmp(stack[lay], stack[lay-1]) == 1)
			dfs(lay+1, i+1);
	}
}

int main ()
{
	int i;
	while(scanf(" %s", &str)!=EOF)
	{
		if(str[0] == '0' && str[1] == NULL)
			break;
		num = -1;
		dfs(0, 0);
		for(i = 0; i < num-1; i++)
			printf("%s,", ans[i]);
		printf("%s\n", ans[i]);
	}
	return 0;
}