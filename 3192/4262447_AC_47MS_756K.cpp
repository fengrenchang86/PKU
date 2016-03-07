#include<iostream>
using namespace std;
int n,ans;
bool visit[10];
char a[10][10];
bool acmCompare(char *a, char *b, int npos)
{
	int i = npos, j = 0;
	while(a[i] != 0 && b[j]!=0)
	{
		if(a[i] != b[j])
			return false;
		i++;
		j++;
	}
	if(b[j] == 0 && a[i] != 0)
		return false;
	while(b[j] != 0)
		a[i++] = b[j++];
	a[i] = NULL;
	return true;
}
void dfs(int lay, char *ch)
{
	int i,j;
	char tch[60];
	if(lay == n)
	{
		int len = strlen(ch);
		if(len < ans)
			ans = len;
		return;
	}
	for(i = 0; i < n; i++)
	{
		if(visit[i])
			continue;
		strcpy(tch,ch);
		for(j = 0; tch[j]!=0; j++)
		{
			if(acmCompare(tch, a[i], j))
				break;
		}
		if(tch[j] == 0)
			acmCompare(tch,a[i],j);
		visit[i] = true;
		dfs(lay+1,tch);
		visit[i] = false;
	}
}
int main ()
{
	int i;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf(" %s",a[i]);
	memset(visit,false,sizeof(visit));
	ans = 2000000000;
	for(i = 0; i < n; i++)
	{
		visit[i] = true;
		dfs(1,a[i]);
		visit[i] = false;
	}
	printf("%d\n",ans);
	return 0;
}
