#include <iostream>
using namespace std;
char a[3000];
char b[3000];
int n;
int main ()
{
	bool co;
	int i,j,x,y,k;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf(" %c",&a[i]);
	i = 0;
	j = n-1;
	k = 0;
	while ( i <= j )
	{
		if ( a[i] < a[j] )
		{
			b[k++] = a[i];
			i++;
		}
		else if ( a[i] > a[j] )
		{
			b[k++] = a[j];
			j--;
		}
		else if ( j-i==1 )
		{
			b[k++] = a[j];
			b[k++] = a[i];
			break;
		}
		else
		{
			x = i;
			y = j;
			co = true;
			while ( y-x>=1 )
			{
				if ( a[x] == a[y] )
				{
					x++;
					y--;
				}
				else if ( a[x] < a[y] )
				{
					break;
				}
				else
				{
					co = false;
					break;
				}
			}
			if ( co == true )
			{
				b[k++] = a[i];
				i++;
			}
			else
			{
				b[k++] = a[j];
				j--;
			}
		}
	}
	b[k] = NULL;
	printf("%s",b);
	return 0;
}