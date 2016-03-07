#include <iostream>
using namespace std;
int c[40][40];
int pow[40];
int v[40];
void dp ()
{
	int i,j;
	for ( i = 1; i <= 32; i++ )
		c[i][0] = c[i][i] = 1;
	for ( i = 2; i <= 32; i++ )
	{
		for ( j = 1; j < i; j++ )
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	pow[0] = 1;
	for ( i = 1; i <= 32; i++ )
		pow[i] = pow[i-1]*2;
}
int find ()
{
	int i = 32;
	int pos1,pos2, sum = 0, count0 = 0,count1 = 0;
	while ( v[i] == 0 )
		i--;
	pos1 = i;
	i = 0;
	while ( v[i] == 0 )
		i++;
	pos2 = i;
	while ( i <= pos1 )
	{
		if ( v[i] == 0 )
			count0++;
		else
			count1++;
		i++;
	}
//	if ( count0+pos2 >= count1 )
//		sum = 1;
	if ( pos1 == pos2 )
	{
		if ( pos1 == 0 )
			return 1;
		v[pos1] = 0;
		sum = 0;
		for ( i = 0; i < pos1; i++ )
			v[i] = 1;
		sum += find();
		return sum;
	}
	v[pos2] = 0;
	count1--;
	count0++;
	for ( i = 0; i <= pos2; i++ )
	{
		if ( count1+i > count0+pos2-i )
			break;
		sum += c[pos2][i];
	}
	if ( pos2 == 0 && count1 <= count0 )
		sum++;
	sum += find();
	return sum;
}
void make ( int n )
{
	int i;
	for ( i = 0; i <= 31; i++ )
		v[i] = 0;
	i = 31;
	while ( i >= 0 )
	{
		v[i] = n/pow[i];
		n %= pow[i];
		i--;
		if ( n == 0 )
			break;
	}
}
int isround ()
{
	int i = 31;
	while ( v[i] == 0 )
		i--;
	int r1 = 0,r0 = 0;
	while ( i >= 0 )
	{
		if ( v[i] == 0 )
			r0++;
		else
			r1++;
		i--;
	}
	if( r0>=r1 )
		return 1;
	else
		return 0;
}
int test ()
{
	int i = 31;
	while ( v[i] == 0 && i >= 0 )
		i--;
	if ( i < 0 )
		return 1;
	int a = 0 , b = 0;
	while ( i >= 0 )
	{
		if ( v[i] == 0 )
			a++;
		else
			b++;
		i--;
	}
	if ( a >= b )
		return 1;
	else
		return 0;
}
int main ()
{
	int i,j;
	int a,b,c;
	int x,y;
	dp();
	scanf("%d%d",&a,&b);
	make(a);
	j = isround();
	x = j+find();
	make(b);
	j = isround();
	y = j+find();
	cout<<y-x+j<<endl;
	return 0;
}