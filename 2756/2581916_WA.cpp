#include <iostream>
using namespace std;
const int max = 800000;
int main ()
{
	char a[max],b[max],c[max];
	int i,j,k,tcase;
	int len1,len2;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%s%s",&a,&b);
		len1 = strlen(a);
		len2 = strlen(b);
		i = len1-1;
		j = len2-1;
		k = 0;
		c[0] = '0';
		while ( i >= 0 && j >= 0 )
		{
			c[k+1] = (a[i]+b[j]-'0'-'0')/10+'0';
			c[k] += (a[i]+b[j]-'0'-'0')%10;
			i--;
			j--;
			k++;
		}
		while ( i >= 0 )
			c[k++] = a[i--];
		while ( j >= 0 )
			c[k++] = b[j--];
		k--;
		while ( k >= 0 )
		{
			printf("%c",c[k]);
			k--;
		}
		printf("\n");
	}
	return 0;
}