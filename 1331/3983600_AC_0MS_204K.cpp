#include<iostream>
using namespace std;
int x, y, z;
int minBase;
int GetNumber(int x, int base)
{
	int j = 1;
	int k = 0;
	while(x)
	{
		k += (x%10)*j;
		j *= base;
		x /= 10;
	}
	return k;
}
void GetMinBase(int n)
{
	while(n)
	{
		if(n%10 > minBase)
			minBase = n%10;
		n /= 10;
	}
}
void MissHH()
{
	scanf("%d %d %d", &x, &y, &z);
	minBase = 1;
	GetMinBase(x);
	GetMinBase(y);
	GetMinBase(z);
	minBase++;
}
void LoveHH()
{
	int i;
	for(i = minBase; i <= 16; i++)
	{
		if(GetNumber(x, i) * GetNumber(y, i) == GetNumber(z, i))
			break;
	}
	if(i <= 16)
		printf("%d\n", i);
	else
		printf("0\n");
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}
