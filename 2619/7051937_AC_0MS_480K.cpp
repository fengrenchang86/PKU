
#include <iostream>
using namespace std;
#define N 32000
__int64 a[50000];
int r1, c1, r2, c2;
int n1, n2;
int Getans()
{
	int k = 0;
	while(r1 != r2)
	{
		if (c1 % 2 == 1)
		{
			c1++;
			r1++;
		}
		else if(c1 + r2 - r1 > c2 && c1 >= 2)
			c1--;
		else
			c1++;
		k++;
	}
	return k + abs(c2 - c1);
}
int main()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		a[i] = i * i;
	}
	cin>>n1>>n2;
	if (n1 > n2)
	{
		i = n1;
		n1 = n2;
		n2 = i;
	}
	for (i = 1; i <= N; i++)
	{
		if (n1 <= a[i])
		{
			r1 = i;
			c1 = n1 - a[i-1];
			break;
		}
	}
	for (i = 1; i <= N; i++)
	{
		if (n2 <= a[i])
		{
			r2 = i;
			c2 = n2 - a[i-1];
			break;
		}
	}
	printf("%d\n", Getans());
	return 0;
}
