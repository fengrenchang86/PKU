#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
char *ch;
vector<int>vec;
unsigned int RSHash(char *pch)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	int i = 0;
	while(i < n)
	{
		hash = hash * a + (*pch++);
		a *= b;
		i++;
	}
	return (hash & 0x7FFFFFFF);
}
int main()
{
	ch = new char[100000];
	int i, j;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		vec.clear();
		scanf(" %s", ch);
		while(*ch)
		{
			vec.push_back(RSHash(ch));
			*ch ++;
		}
		sort(vec.begin(), vec.end());
		j = 1;
		for(i = 1; i < vec.size(); i++)
		{
			if(vec[i] != vec[i-1])
				j++;
		}
		printf("%d\n", j-(n-1));
	}
	return 0;
}