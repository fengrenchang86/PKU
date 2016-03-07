#include <iostream>
using namespace std;
char a[31000];
int n;
int count=0;
void f (int x, int y)
{
	int i = x;
	int j = y;
	if (i == j)
	{
		printf("%c",a[x]);
		count++;
		if ( count % 80 == 0 )
			printf("\n");
		return;
	}
	if (a[i] < a[j])
	{
		printf("%c",a[i]);
		count++;
		if ( count % 80 == 0 )
			printf("\n");
		f(x+1,y);
	}
	else if (a[i] > a[j])
	{
		printf("%c",a[j]);
		count++;
		if ( count % 80 == 0 )
			printf("\n");
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
			count++;
			if ( count % 80 == 0 )
				printf("\n");
			f(x+1,y);
		}
		else
		{
			printf("%c",a[y]);
			count++;
			if ( count % 80 == 0 )
				printf("\n");
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