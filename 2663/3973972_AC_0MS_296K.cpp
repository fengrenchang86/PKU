#include<iostream>
using namespace std;
__int64 ans = 0;
void dfs(int lay, int num)
{
	int i;
	if(num == 0)
	{
		ans += lay;
		return;
	}
	dfs(lay*3, num-2);
	for(i = 4; i <= num; i+=2)
	{
		dfs(lay*2, num-i);
	}
}
int main ()
{
	int n;
	while(cin>>n)
	{
		if(n == -1)
			break;
		else if(n % 2 == 1)
		{
			cout<<0<<endl;
			continue;
		}
		ans = 0;
		dfs(1, n);
		printf("%I64d\n", ans);
	}
	return 0;
}
