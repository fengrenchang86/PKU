
#include<iostream>
#include <algorithm>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > queA;
priority_queue<int, vector<int>, greater<int> > queB;
int n, x, y;

void MissHH()
{
	while(!queA.empty())
		queA.pop();
	while(!queB.empty())
		queB.pop();
}

void LoveHH()
{
	int i, k;
	__int64 sum = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &k);
		queA.push(k);
		queB.push(k);
		sum += __int64(k);
	}
	for(i = 0; i < x; i++)
	{
		sum -= queA.top();
		queA.pop();
	}
	for(i = 0; i < y; i++)
	{
		sum -= queB.top();
		queB.pop();
	}
	double HH = double(sum) / double(n - x - y);
	printf("%.6lf\n", HH);
}
int main ()
{
	while(scanf("%d%d%d", &x, &y, &n) != EOF)
	{
		if(n == x && x == y && y == 0)
			break;
		MissHH();
		LoveHH();
	}
	return 0;
}