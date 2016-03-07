#include <iostream>
using namespace std;
int main ()
{
	char a[100],b[100],v[100];
	int i;
	int n;
	int c;
	int j;
	int lena,lenb;
	int k;
	scanf("%d",&n);
	for ( c = 1; c <= n; c++ )
	{
		scanf("%s %s",a,b);
		lena = strlen(a);
		lenb = strlen(b);
		k = 0;
		for ( i = lena-1, j = lenb-1; i >= 0 && j >= 0; i--,j-- )
		{
			v[k] = a[i]+b[j]-'0';
			k++;
		}
		if ( i == -1 )
		{
			while ( j >= 0 )
				v[k++] = b[j--];
		}
		else 
		{
			while ( i >= 0 )
				v[k++] = a[i--];
		}
		v[k] = '0';
		for ( i = 0; i < k; i++ )
		{
			if ( v[i] >= '2' )
			{
				v[i+1]++;
				v[i] -= 2;
			}
		}
		printf("%d ",c);
		if ( v[i] == '1' )
			printf("1");
		i = k-1;
		while ( i >= 0 )
		{
			printf("%c",v[i]);
			i--;
		}
		printf("\n");
	}
	return 1;
}
