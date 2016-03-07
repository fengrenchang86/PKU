#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int val;
	int id;
}a[3200], b[3200];
int nSchoolNum, nSchoolId, nBookNum;
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->val - d->val;
}
int cmp2(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->id - d->id;
}
void Input()
{
	for (int i = 0; i < nBookNum; i++)
	{
		scanf("%d", &a[i].val);
		a[i].id = i;
	}
}
void Solve()
{
	qsort(a, nBookNum, sizeof(a[0]), cmp);
	int x = nBookNum - nBookNum / nSchoolNum * nSchoolNum;
	int nId;
	int i;
	if (nSchoolId + 1 <= x)
	{
		nId = nSchoolId * (1 + nBookNum / nSchoolNum);
		for (i = 0; i < nBookNum / nSchoolNum + 1; i++)
		{
			b[i] = a[i+nId];
		}
		qsort(b, nBookNum / nSchoolNum + 1, sizeof(b[0]), cmp2);
	}
	else
	{
		nId = x * (1 + nBookNum / nSchoolNum) + (nBookNum / nSchoolNum) * (nSchoolId - x);
		for (i = 0; i < nBookNum / nSchoolNum; i++)
		{
			b[i] = a[i+nId];
		}
		qsort(b, nBookNum / nSchoolNum, sizeof(b[0]), cmp2);
	}
	printf("%d\n", b[0].val);
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