#include <iostream>
using namespace std;
int main ()
{
	double a[5000];
	int i;
	int n;
	char d[10];
	for ( i = 0; ;i++ )
	{
	//	printf("i = %d\n",i);
		n = (i+1)/2;
	//	printf("n = %d\n",n);
		if ( i%2==0 )
			a[i] = (n*(n+1))+n+1;
		else
			a[i] = n*(n+1);
	//	printf("%d",a[i]);
		cin.getline(d,1,'\n');
		if ( a[i] > 22000000000 )
			break;
	}
	int c,b;
	scanf("%d",&n);
	for ( i = 0; i < n; i ++ )
	{
		scanf("%d %d",&c,&b);
		if ( c - b > 0 )
			c = c - b;
		else
			c = b - c;
		for ( b = 0; a[b] < c; b++ );
		if ( a[b] == c )
			printf("%d\n",b+1);
		else
			printf("%d\n",b+1);
	}
	return 1;
}