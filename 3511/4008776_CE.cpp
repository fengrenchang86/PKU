#include<iostream>
#include<math.h>
using namespace std;
bool prime[1000100];
int a[100010];
int m;//number of prime
void MakePrime()
{
	int i, j;
	memset(prime, true, sizeof(prime));
	for(i = 2; i < 500000; i++)
	{
		if(prime[i] == false)
			continue;
		for(j = 2; i*j < 1000000; j++)
			prime[i*j] = false;
	}
	j = 0;
	for(i = 2; i < 1000000; i++)
	{
		if(prime[i])
			a[j++] = i;
	}
	m = j;
}
int GetPos(int x)
{
	int begin = 0, end = m-1, mid = (begin+end)/2;
	while(begin < end)
	{
		mid = (begin + end) / 2;
		if(x >= a[mid])
			begin = mid+1;
		else
			end = mid;
	}
	return begin;
}
bool Accepte(int x)
{
	if((x-1)%4==0)
		return true;
	else
		return false;
	int i, j, k;
	for(i = 1; i*i < x; i++)
	{
		j = x - i*i;
		k = sqrt(j);
		if(k*k == j)
			return true;
	}
	return false;
}
int main()
{
	int x, y;
	int nx, ny;
	int i, j;
	MakePrime();
	while(scanf("%d%d", &x, &y) != EOF)
	{
		if(x == -1 && y == -1)
			break;
		nx = GetPos(x);
		ny = GetPos(y);
		printf("%d %d %d", x, y, ny-GetPos(x-1));
		ny--;
		j = 0;
		for(i = nx; i <= ny; i++)
		{
			if(Accepte(a[i]))
				j++;
		}
		printf(" %d\n", j);
	}
	return 0;
}