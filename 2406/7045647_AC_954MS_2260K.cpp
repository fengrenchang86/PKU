#include <iostream>
#include <stdlib.h>
using namespace std;

int next[1100000];
char t[1200000];
bool v[1100000];
int m;
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int Index_KMP(char* s, char* t, int* next) {
	int i = 0, j = 0;
	int l1 = strlen(s);
	int l2 = strlen(t);
	while (i < l1 && j < l2) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else if (next[j] == -1)
		{
			i++;
		}
		else {
			j = next[j];
		}
	}
	if (j == l2) return i - l2;
	else return -1;
} 
void get_next(char* t, int* next)
{
	int i = 0, j = -1;  // j记录已匹配的个数
	int l2 = strlen(t);
	next[0] = -1;
	int lt = strlen(t);
	while (i < lt) {
		if (j == -1 || t[i] == t[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else j = next[j];
	}
}

int main()
{
	int ok = 0;
	int ans = 1;
	int i, j, k, n, m = 0;
	while(cin>>t)
	{
		if (t[0] == '.')
		{
			break;
		}
		ok = 0;
		memset(v, 0, sizeof(v));
		n = strlen(t);
		m = 0;
		for (i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				next[m++] = i;
				next[m++] = n / i;
				v[i] = 1;
				v[n/i] = 1;
			}
		}
		ans = n;
		qsort(next, m, sizeof(next[0]), cmp);
		for (i = 0; i < m; i++)
		{
			k = next[i];
			if (v[k] == 0)
			{
				continue;
			}
			ok = 1;
			for (j = k; j < n; j++)
			{
				if (t[j%k] != t[j])
				{
					ok = 0;
					break;
				}
			}
			if (ok == 1)
			{
				ans = k;
				break;
			}
		}
		printf("%d\n", n / ans);
	}
	return 0;
}