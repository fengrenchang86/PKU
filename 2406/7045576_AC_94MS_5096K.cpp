#include <iostream>
using namespace std;

int next[1100000];
char t[1200000];
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
	int i, j, k, n;
/*
	while (cin>>s>>t)
	{
		get_next(t, next);
		n = Index_KMP(s, t, next);
		cout << n << endl;
	}*/
	while(cin>>t)
	{
		if (t[0] == '.')
		{
			break;
		}
		n = strlen(t);
//		cout << "len = " << n << endl;
		get_next(t, next);
/*
		for (i = 0; i < n; i++)
		{
			printf("%d ", next[i]);
		}
		printf("\n");*/

		j = n - 1;
		i = next[j];
		k = j - i;
		if (n % k == 0 && t[j] == t[i])
		{
			i = 1;
			while (j >= 0)
			{
				if (j + 1 == k)
				{
					printf("%d\n", i);
					break;
				}
				else if (j - next[j] != k || t[j] != t[next[j]])
				{
					printf("1\n");
					break;
				}
				i++;
				j = next[j];
			}
			if (j == -1)
			{
				printf("%d\n", i);
			}
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}