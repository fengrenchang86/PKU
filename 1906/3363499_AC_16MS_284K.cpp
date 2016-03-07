#include <iostream>
using namespace std;
const int SIZE = 50;
struct BigNum
{
	int dig[SIZE];
	int size;
};
struct ac
{
	BigNum b1;
	BigNum b2;
	BigNum b3;
	bool use;
	ac(){use=false;}
}a[101];
void initBigNum ( BigNum &m )
{
	m.size = 0;
	memset(m.dig,0,sizeof(m.dig));
}
void updateSize ( BigNum &m )
{
	int i;
	for ( i = m.size; i > 0; i-- )
	{
		if ( m.dig[i] != 0 )
			break;
	}
	m.size = i+1;
}
void printBigNum ( BigNum m )
{
	int i;
	printf("%d",m.dig[m.size-1]);
	for ( i = m.size - 2; i >= 0; i-- )
		printf("%04d",m.dig[i]);
}
void ctoBigNum ( char *t, BigNum &m )
{
	initBigNum(m);
	int i,j,k;
	k = 0;
	j = 1;
	for ( i = strlen(t)-1; i >= 0; i-- )
	{
		k += j*(t[i]-'0');
		j *= 10;
		if ( j == 10000 )
		{
			m.dig[m.size++] = k;
			j = 1;
			k = 0;
		}
	}
	if ( k != 0 )
		m.dig[m.size++] = k;
}
void acplus ( BigNum x, BigNum y, BigNum &z )
{
	initBigNum(z);
	int i,carry=0;
	z.size = ( x.size > y.size ? x.size : y.size )+1;
	for ( i =0; i < z.size; i++ )
	{
		z.dig[i] = (x.dig[i] + y.dig[i]+ carry )%10000;
		carry = (x.dig[i]+y.dig[i]+carry)/10000;
	}
	updateSize(z);
}
void acplus ( BigNum &x, int k )
{
	int i;
	x.dig[0] += k;
	for ( i = 0; i < x.size; i++ )
	{
		x.dig[i+1] += x.dig[i]/10000;
		x.dig[i] %= 10000;
	}
	x.size++;
	updateSize(x);
}
void minue ( BigNum x, BigNum y, BigNum &z )
{
	initBigNum(z);
	int i,carry=0;
	z.size = ( x.size > y.size ? x.size : y.size )+1;
	for ( i = 0; i < z.size; i++ )
	{
		if ( x.dig[i]-carry-y.dig[i] < 0 )
		{
			z.dig[i] = x.dig[i]-carry-y.dig[i]+10000;
			carry = 1;
		}
		else
		{
			z.dig[i] = x.dig[i]-y.dig[i]-carry;
			carry = 0;
		}
	}
	updateSize(z);
}
void cheng ( BigNum x, int k, BigNum &y )//y = x*k;
{
	int i;
	y.size = x.size;
	for ( i = 0; i < y.size; i++ )
		y.dig[i] = x.dig[i] * k;
	for ( i = 0; i < y.size; i++ )
	{
		y.dig[i+1] += y.dig[i]/10000;
		y.dig[i] %= 10000;
	}
	y.size++;
	updateSize(y);
}
bool compare ( BigNum x, BigNum y )//x>=y return true;
{
	if ( x.size != y.size )
		return x.size > y.size;
	int i = x.size-1;
	while ( i >= 0 )
	{
		if ( x.dig[i] != y.dig[i] )
			return x.dig[i]>y.dig[i];
		i--;
	}
	return true;
}
void init ()
{
	int i;
	for ( i = 0; i <= 100; i++ )
	{
		initBigNum(a[i].b1);
		initBigNum(a[i].b2);
		initBigNum(a[i].b3);
	}
	a[0].b1.dig[0] = 1;
	a[0].b1.size = 1;
	a[0].b2.dig[0] = 1;
	a[0].b2.size = 1;
	a[0].b3.dig[0] = 0;
	a[0].b3.size = 1;
	a[1].b1.dig[0] = 2;
	a[1].b1.size = 1;
	a[1].b2.dig[0] = 1;
	a[1].b2.size = 1;
	a[1].b3.dig[0] = 1;
	a[1].b3.size = 1;
	for ( i = 2; i <= 100; i++ )
	{
		cheng(a[i-1].b3,3,a[i].b3);
		cheng(a[i-1].b2,2,a[i].b2);
		a[i].b1 = a[i].b2;
		acplus(a[i].b1,1);
	}
}
void solve ( char *t )
{
	BigNum input,z;
	int i;
	for ( i = 0; i <= 100; i++ )
		a[i].use = false;
	ctoBigNum(t,input);
	for ( i = 100; i >= 0; i-- )
	{
		if ( compare(input,a[i].b1) )
		{
			minue(input,a[i].b2,z);
			input = z;
			a[i].use = true;
		}
	}
	printf("{ ");
	for ( i = 1; i <= 100; i++ )
	{
		if ( a[i].use == true )
		{
			printBigNum(a[i].b3);
			break;
		}
	}
	i++;
	while ( i <= 100 )
	{
		if ( a[i].use == true )
		{
			printf(", ");
			printBigNum(a[i].b3);
		}
		i++;
	}
	printf(" }\n");
}
int main ()
{
	char t[100];
	init();
	while ( cin>>t )
	{
		if ( t[0] == '0' && t[1] == NULL )
			break;
		solve(t);
	}
	return 0;
}