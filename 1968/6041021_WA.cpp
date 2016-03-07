#include <iostream>
#include <stdlib.h>
using namespace std;
int a[3200];
int nSchoolNum, nSchoolId, nBookNum;
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void Input()
{
	for (int i = 0; i < nBookNum; i++)
	{
		scanf("%d", &a[i]);
	}
}
void Solve()
{
	qsort(a, nBookNum, sizeof(a[0]), cmp);
	int x = nBookNum - nBookNum / nSchoolNum * nSchoolNum;
	int nId;
	if (nSchoolId + 1 <= x)
	{
		nId = nSchoolId * (1 + nBookNum / nSchoolNum);
	}
	else
	{
		nId = x * (1 + nBookNum / nSchoolNum) + (nBookNum / nSchoolNum) * (nSchoolId - x);
	}
	printf("%d\n", a[nId]);
}
int main()
{
	while (scanf("%d %d %d", &nSchoolNum, &nSchoolId, &nBookNum) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}