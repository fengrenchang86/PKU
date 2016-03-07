#include <iostream>
using namespace std;
int sum ( int a[],  int x, int y )
{
	int i,z=0;
	for ( i = x; i <= y; i++ )
		z += a[i];
	return z;
}

void main ()
{
	int a[50],b[50],c[50],d[50];
	int i;
	for ( i = 0; i <= 9; i++ )
		a[i] = i+1;
	while ( i <= 18 )
	{
		a[i] = 19-i;
		i++;
	}

	for ( i = 0; i <= 9; i++ )
		b[i] = sum(a,0,i);
	while ( i <= 18 )
	{
		b[i] = sum(a,i-9,i);
		i++;
	}
	while ( i <= 27 )
	{
		b[i] = sum ( a, i-9,18 );
		i++;
	}

	for ( i = 0; i <= 9; i++ )
		c[i] = sum(b,0,i);
	while ( i <= 27 )
	{
		c[i] = sum ( b, i-9, i );
		i++;
	}
	while ( i <= 36 )
	{
		c[i] = sum ( b, i-9, 27 );
		i++;
	}

	for ( i = 0; i <= 9; i++ )
		d[i] = sum ( c, 0, i );
	while ( i <= 36 )
	{
		d[i] = sum ( c,i-9,36 );
		i++;
	}
	while ( i <= 45 )
	{
		d[i] = sum ( c, i-9, 36 );
		i++;
	}
	_int64 t[4] = {0,0,0,0};
	for ( i = 0; i <= 18; i++ )
		t[0] += a[i]*a[i];
	for ( i = 0; i <= 27; i++ )
		t[1] += b[i]*b[i];
	for ( i = 0; i <= 36; i++ )
		t[2] += c[i]*c[i];
	for ( i = 0; i <= 45; i++ )
		t[3] += d[i]*d[i];
	//printf("%I64d\n%I64d\n%I64d\n%I64d\n",t[0],t[1],t[2],t[3]);
	int n;
	while ( scanf("%d",&n) != EOF )
	{
		switch (n )
		{
		case 1:
		case 2:
			printf("10\n");
			break;
		case 3:
		case 4:
			printf("%I64d\n",t[0]);
			break;
		case 5:
		case 6:
			printf("%I64d\n",t[1]);
			break;
		case 7:
		case 8:
			printf("%I64d\n",t[2]);
			break;
		case 9:
		case 10:
			printf("%I64d\n",t[3]);
			break;
		};
	}
}