#include<iostream>
using namespace std;
int hui[100100];
int n, m;
void MissHH()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &hui[i]);
}
void LoveHH()
{
	int ans = 0;
	int i = 0, j, k = 0;
	for(j = 0; j < m; j++)
		k += hui[j];
	ans = k;
	while(j < n)
	{
		k = k - hui[i] + hui[j];
		if(k > ans)
			ans = k;
		i ++;
		j ++;
	}
	__int64 chang = 1000 * __int64(ans) / __int64(m);
	printf("%d\n", chang);
}
int main ()
{
	MissHH();
	LoveHH();
	return 0;
}