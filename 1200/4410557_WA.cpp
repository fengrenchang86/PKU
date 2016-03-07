#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
char *ch;
vector<unsigned int>vec;
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
unsigned int ELFHash(char *pch)
{
	unsigned int hash = 0;
	unsigned int x = 0;
	int i = 0;
	while(i < n)
	{
		hash = (hash << 4) + (*pch ++);
		if((x = hash & 0x0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
		i++;
	}
	return (hash & 0x7FFFFFFF);
}
int main()
{
	ch = new char[1000000];
	int i, j;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		vec.clear();
		scanf(" %s", ch);
		while(*ch)
		{
			vec.push_back(ELFHash(ch));
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