#include <iostream>
#include <iomanip>
using namespace std;
void main ( )
{
	int pl ( int, int );
	int p = 1;
	int n = 1;
	int i;
	int count = 0;
	int end ;
	int q = 0;
//	int save[100];
	int c = 0;
	int P[100];
	int N[100];
	while ( 1 )
	{
		cin>>P[c]>>N[c];
		if ( P[c] == 0 && N[c] == 0 )
			break;
		c++;
	}
	int a = 0;
	while ( a < c )
	{
		p = P[a];
		n = N[a];
		count = 0;
		a++;
		if ( n % 2 == 0 )
		{
			end = n / 2 - 1;
			for ( i = 0; i <= end; i++ )
			{
				if ( pl ( n, i ) % p != 0 )
					count++;
			}
			count *= 2;
			if ( pl ( n , n/2 ) % p != 0 )
				count++;
		}
		else 
		{
			end = n / 2;
			for ( i = 0; i <= end; i++ )
			{
				if ( pl ( n, i ) % p != 0 )
					count++;
			}
			count *= 2;
		}
		count %= 10000;
	//	save[q++] = count;
		q++;
		cout<<"Case "<<q<<": "<<setw(4)<<setfill('0')<<count<<endl;
	}
//	for ( i = 0; i < q; i++ )
//		cout<<"Case "<<i+1<<": "<<setw(4)<<setfill('0')<<save[i]<<endl;
}

int jc ( int n )
{
	int i ;
	int sum = 1;
	i = n;
	while ( i > 0 )
	{
		sum *= i;
		i--;
	}
	return sum;
}

int pl ( int m, int n )		// m > n
{
	int jc ( int );
	int sum = 1;
	int i = m;
	while ( i > m - n )
	{
		sum *= i;
		i--;
	}
	i = jc ( n );
	return sum / i;
}