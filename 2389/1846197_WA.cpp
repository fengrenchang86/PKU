#include <iostream.h>
void main ()
{
	int a[12];
	int b[12];
	int c[30];
	int i;
	int k;
	int sizea;
	int sizeb;
	int ia;
	int ib;
	char cha[50];
	char chb[50];
	int power ( int, int );
	while ( cin>>cha>>chb )
	{
		ia = 0;
		ib = 0;
		for ( i = 0; i < 12; i++ )
		{
			a[i] = 0;
			b[i] = 0;
		}
		for ( i = 0; i < 30; i++ )
			c[i] = 0;
		while ( cha[ia] != NULL )
			ia++;
		while ( chb[ib] != NULL )
			ib++;
		sizea = ia;
		sizeb= ib;
		i = 0;
		k = 0;
		for ( ia = sizea-1; ia >= 0; ia-- )
		{
			if ( k == 4 )
			{
				i++;
				k = 0;
			}
			a[i] += ((cha[ia]-'0')*power(10,k));
			k++;
		}
		sizea = i;
		i = 0;
		k = 0;
		for ( ib = sizeb-1; ib >= 0; ib-- )
		{
			if ( k == 4 )
			{
				i++;
				k = 0;
			}
			b[i] += ((chb[ib]-'0')*power(10,k));
			k++;
		}
		sizeb = i;
//		for ( i = sizea; i >=0 ; i-- )
//			cout<<a[i];
//		cout<<endl;
//		for ( i = sizeb; i >= 0; i-- )
//			cout<<b[i];
//		cout<<endl;
		for ( i = 0; i <= sizea; i++ )
		{
			for ( k = 0; k <= sizeb; k++ )
			{
				c[i+k+1] += a[i]*b[k] / 10000;
				c[i+k] += a[i]*b[k] % 10000;
			}
		}
		for ( ia = 0; ia <= sizea+sizeb; ia++ )
		{
			if ( c[ia] >= 10000 )
			{
				c[ia+1] += c[ia]/10000;
				c[ia] %= 10000;
			}
		}
		ia = sizea+sizeb+1;
		while ( c[ia] == 0 )
			ia--;
		for ( ; ia >= 0; ia-- )
			cout<<c[ia];
		cout<<endl;
	}
	
}

int power ( int a, int b )
{
	if ( b == 0 )
		return 1;
	int sum = 1;
	int i;
	for ( i = 0; i < b; i++ )
		sum*=a;
	return sum;
}