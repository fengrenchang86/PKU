#include<iostream>
using namespace std;
char str[200];
char ans[200];
int nN, nLittle, nBig;
bool check()
{
	int i;
	nBig = nLittle = nN = 0;
	for(i = 0; str[i] != NULL; i++)
	{
		if(str[i] >= 'p' && str[i] <= 'q')
			nLittle++;
		else if(str[i] == 'N')
			nN++;
		else 
			nBig++;
	}
	for(i = 0; str[i] != NULL; i++)
	{
		if(str[i] >= 'p' && str[i] <= 't')
			continue;
		if(str[i] != 'K' && str[i] != 'N' && str[i] != 'A' && str[i] != 'C' && str[i] != 'E')
			return false;
	}
	if(nLittle == 0)
		return false;
	return true;
}
void LoveHH()
{
	int i, j, k;
	if(check() == false)
	{
		printf("no WFF possible\n");
		return;
	}
	else if(nLittle == 1)
	{
		j = 0;
		for(i = 0; i < nN; i++)
			ans[j++] = 'N';
		for(i = 0; str[i] != NULL; i++)
		{
			if(str[i] >= 'p' && str[i] <= 't')
			{
				ans[j++] = str[i];
				ans[j] = NULL;
				break;
			}
		}
	}
	else if(nBig == 0)
	{
		j = 0;
		for(i = 0; i < nN; i++)
			ans[j++] = 'N';
		for(i = 0; str[i] != NULL; i++)
		{
			if(str[i] >= 'p' && str[i] <= 't')
			{
				ans[j++] = str[i];
				ans[j] = NULL;
				break;
			}
		}
	}
	else if(nBig < nLittle)
	{
		j = 0;
		k = 0;
		for(i = 0; i < nN; i++)
			ans[j++] = 'N';
		for(i = 0; str[i] != NULL; i++)
		{
			if(!(str[i] >= 'p' && str[i] <= 't') && str[i] != 'N')
			{
				ans[j++] = str[i];
			}
		}
		for(i = 0; str[i] != NULL && k < nBig+1; i++)
		{
			if(str[i] >= 'p' && str[i] <= 't')
			{
				ans[j++] = str[i];
				k++;
			}
		}
		ans[j] = NULL;
	}
	else
	{
		j = 0;
		k = 0;
		for(i = 0; i < nN; i++)
			ans [j++] = 'N';
		for(i = 0; str[i] != NULL && k < nLittle - 1; i++)
		{
			if(!(str[i] >= 'p' && str[i] <= 't') && str[i] != 'N')
			{
				ans[j++] = str[i];
				k++;
			}
		}
		for(i = 0; str[i] != NULL; i++)
		{
			if(str[i] >= 'p' && str[i] <= 't')
			{
				ans[j++] = str[i];
			}
		}
		ans[j] = NULL; 
	}
	printf("%s\n", ans);
}
int main ()
{
	while(scanf("%s", &str) != EOF)
	{
		if(str[0] == '0' && str[1] == NULL)
			break;
		LoveHH();
	}
	return 0;
}