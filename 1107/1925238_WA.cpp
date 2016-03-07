#include <iostream>
using namespace std;
int main ()
{
	char a[100];
	char b[100];
	int k1,k2,k3;
	int i;
	int j;
	int k;
	int t;
	int x,y,z;
	char c1[100];
	char c2[100];
	char c3[100];
	while ( scanf("%d %d %d",&k1,&k2,&k3) && !(k1==0&&k2==0&&k3==0) )
	{
		i = j = k = 0;
		x = y = z = 0;
		scanf("%s",a);
		for ( t = 0; a[t]!=NULL; t++ )
		{
			b[t] = a[t];
			if ( a[t]>='a' && a[t] <= 'i' )
				c1[i++] = a[t];
			else if ( a[t]>='j' && a[t] <= 'r' )
				c2[j++] = a[t];
			else
				c3[k++] = a[t];
		}
		b[t] = NULL;
		for ( t = 0; b[t]!=NULL; t++ )
		{
			if ( b[t] >= 'a' && b[t] <= 'i' )
			{
				a[t] = c1[(x-k1+i)%i];
				x++;
			}
			else if ( b[t] >= 'j' && b[t] <= 'r' )
			{
				a[t] = c2[(y-k2+j)%j];
				y++;
			}
			else
			{
				a[t] = c3[(z-k3+k)%k];
				z++;
			}
		}
		printf("%s\n",a);
	}
	return 1;
}