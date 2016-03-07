#include <iostream>
#include <map>
using namespace std;
map<long long, int>acm;
int a[100000];
int nStart, nEnd, T;
void Calue()
{
	int lay = 3;
	long long x, y, z;
	x = 1;
	y = 2;
	z = x * 100000 + y;
	acm[z] = 3;
	a[1] = 1;
	a[2] = 2;
	while (1)
	{
		z = (3 * y - x + 100000) % 100000;
		a[lay] = (int)z;
		x = (y + 100000) % 100000;
		y = z;
		lay ++;
		z = (x * 100000 + y);
		if (acm[z] == 0)
		{
			acm[z] = lay;
		}
		else
		{
			nStart = acm[z];
			nEnd = lay;
			break;
		}
	}
	a[0] = (3 * y - x + 100000) % 100000;
	T = nEnd - nStart;
}
int main()
{
//	Calue();
//	cout << T << endl;
	int i;
	T = 75000;
	a[1] = 1;
	a[2] = 2;
	for (i = 3; i <= T; i++)
	{
		a[i] = (3 * a[i-1] - a[i-2] + 100000) % 100000;
	}
	a[0] = a[T];
	int tc, k;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &k);
		printf("%d\n", a[k%T]);
	}
	return 0;
}