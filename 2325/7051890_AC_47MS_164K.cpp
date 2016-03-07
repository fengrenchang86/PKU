#include <iostream>
using namespace std;
char szAns[1009];
int nAns[1009];
int nAnsNum;
int F_Mod(char *pszStr, int k)
{
	int i, j = 0;
	int pos = 0;
	for(i = 0; pszStr[i] != NULL; i++)
	{
		j *= 10;
		j += (pszStr[i] - '0');
		if(pos != 0 || j/k != 0)
			szAns[pos++] = j / k + '0';
		j %= k;
	}
	szAns[pos] = NULL;
	return j;
}
int main()
{
	char szStr[1009];
	int i, k;
	while(scanf("%s", &szStr) != EOF)
	{
		if(strcmp(szStr, "-1") == 0)
			break;
		if(strlen(szStr) == 1)
		{
			printf("1%s\n", szStr);
			continue;
		}
		nAnsNum = 0;
		k = 9;
		while(k >= 2)
		{
			i = F_Mod(szStr, k);
			if(i == 0)
			{
				strcpy(szStr, szAns);
				nAns[nAnsNum++] = k;
			}
			else
				k--;
		}
		if(strcmp(szStr, "1") != 0)
		{
			printf("There is no such number.\n");
			continue;
		}
		for(i = nAnsNum-1; i >= 0; i--)
		{
			printf("%d", nAns[i]);
		}
		printf("\n");
	}
	return 0;
}