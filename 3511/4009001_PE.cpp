#include<iostream>
#include<math.h>
using namespace std;
bool prime[1000200];
bool accept[1000200];
int a[1002110];
int m;//number of prime
void MakePrime()
{
	int i, j;
	memset(prime, true, sizeof(prime));
	for(i = 2; i < 500000; i++)
	{
		if(prime[i] == false)
			continue;
		for(j = 2; i*j < 1001000; j++)
			prime[i*j] = false;
	}
	j = 0;
	for(i = 2; i < 1000200; i++)
	{
		if(prime[i])
			a[j++] = i;
	}
	m = j;
	memset(accept, false, sizeof(accept));
	for(i = 1; i <= 1000; i++)
	{
		for(j = 1; j <= 1000; j++)
		{
			if(i*i + j*j < 1000200)
				accept[i*i+j*j] = true;
		}
	}
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
int main()
{
	int x, y;
	int nx, ny;
	int i, j;
	MakePrime();
	while(scanf(" %d %d", &x, &y) != EOF)
	{
		if(x == -1 && y == -1)
			break;
		printf("%d %d ", x, y);
		if(x < 0)
			x = 1;
		if(y < 0)
			y = 1;
		nx = GetPos(x);
		ny = GetPos(y);
		printf("%d ", ny - GetPos(x-1));

		if(a[nx-1] == x)
			nx--;
		ny--;
		j = 0;
		for(i = nx; i <= ny; i++)
		{
			if(accept[a[i]])
				j++;
		}
		printf(" %d\n", j);
	}
	return 0;
}