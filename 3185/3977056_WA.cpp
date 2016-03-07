#include<iostream>
using namespace std;
char a[30], b[30];
int ans = 200;
void change(int x)
{
	if(a[x] == '0')
		a[x] = '1';
	else
		a[x] = '0';
}
void dfs(int lay, int num)
{
	if(lay == 20)
	{
		int i;
		for(i = 0; i < 20; i++)
		{
			if(a[i] == '1')
				break;
		}
		if(i < 20)
			return;
		if(num < ans)
			ans = num;
		return;
	}
	dfs(lay+1, num);
	change(lay);
	if(lay > 0)
		change(lay-1);
	if(lay+1 < 20)
		change(lay+1);
	dfs(lay+1, num+1);
	change(lay);
	if(lay > 0)
		change(lay-1);
	if(lay+1 < 20)
		change(lay+1);
}
int LoveHH()
{
	int i, j = 0;
	for(i = 1; i < 20; i++)
	{
		if(a[i-1] == '0')
			continue;
		change(i);
		change(i-1);
		if(i+1 < 20)
			change(i+1);
		j++;
	}
	if(a[19] == '1')
		return 200;
	return j;
}
int main ()
{
	int i, j, k;
	for(i = 0; i < 20; i++)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	k = LoveHH();
	for(i = 0; i < 20; i++)
		a[i] = b[i];
	change(0);
	change(1);
	j = LoveHH();
	if(j < k)
		k = j;
	printf("%d\n", k);
	for(i = 0; i < 20; i++)
		a[i] = b[i];
//	ans = 200;
//	dfs(0, 0);
//	cout<<ans<<endl;
	return 0;
}