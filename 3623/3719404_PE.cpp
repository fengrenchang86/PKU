#include <iostream>
using namespace std;
char a[31000];
int n;
void f (int x, int y)
{
	int i = x;
	int j = y;
	if (i == j)
	{
		printf("%c",a[x]);
		return;
	}
	if (a[i] < a[j])
	{
		printf("%c",a[i]);
		f(x+1,y);
	}
	else if (a[i] > a[j])
	{
		printf("%c",a[j]);
		f(x,y-1);
	}
	else
	{
		i++;
		j--;
		while ( i < j )
		{
			if (a[i] != a[j])
				break;
			i++;
			j--;
		}
		if ( i == j || a[i] < a[j] )
		{
			printf("%c",a[x]);
			f(x+1,y);
		}
		else
		{
			printf("%c",a[y]);
			f(x,y-1);
		}
	}

}
int main ()
{
	scanf("%d",&n);
	int i;
	for (i = 0; i < n; i++)
		scanf(" %c",&a[i]);
	f(0,n-1);
	printf("\n");
	return 0;
}