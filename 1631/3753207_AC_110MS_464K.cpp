#include<iostream>
using namespace std;
int a[41000];
int b[41000];
int acFind(int begin, int end, int nX)
{
	int mid;
	while(begin < end)
	{
		mid = (begin + end)/2;
		if(b[mid] == nX)
			return mid;
		else if(b[mid] < nX)
			begin = mid + 1;
		else
			end = mid;
	}
	return begin;
}
int main ()
{
	int i,j,k,n;
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		for(i = 0; i < n; i++)
			scanf("%d",&a[i]);
		b[0] = a[0];
		j = 1;
		for(i = 1; i < n; i++)
		{
			if(a[i] < b[0])
				b[0] = a[i];
			else if(a[i] > b[j-1])
				b[j++] = a[i];
			else
			{
				k = acFind(0, j-1, a[i]);
				b[k] = a[i];
			}
		}
		printf("%d\n",j);
	}
	return 0;
}