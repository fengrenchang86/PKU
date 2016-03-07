#include <iostream.h>
char list[256][8];
int str ( char *a, int b, int k)
{
	int i;
	for ( i = 0; i < 8; i++,k++ )
		if(a[k] != list[b][i])
			return -1;
	return 1;
}
void makelist ( )
{
	int i;
	int j;
	int k;
	for ( i = 0; i < 256; i++ )
	{
		for ( j = 0; j < 8; j++ )
			list[i][j] = '0';
		for ( j = 0; j < i; j++ )
		{
			list[i][7]++;
			k = 7;
			while ( list[i][k] > '1' )
			{
				k--;
				list[i][k]++;
				list[i][k+1] = '0';
				if ( k == 0 )
					break;
			}
		}
	}
}

void main ()
{
	int n;
	char input[32];
	int n1;
	int n2;
	int n3;
	int n4;
	int a1;
	int a2;
	int a3;
	int a4;
	int i;
	int N;
	int j = 0;
	makelist();
//	for ( i = 0; i < 256; i++ )
//	{
//		for ( j = 0; j < 8; j++ )
//			cout<<list[i][j];
//		cout<<endl;
//	}
//		cout<<endl;
	cin>>n;
	N = n;
	for ( i = 0; i < n; i++ )
	{
		n1=0;
		n2 = 0;
		n3 = 0;
		n4 = 0;
		cin>>input;
		for ( j = 0; j < 256; j++ )
		{
			n1 = str ( input,j,0);
			if ( n1 == 1 )
				a1 = j;
			n2 = str ( input, j, 8 );
			if ( n2 == 1 )
				a2 = j;
			n3 = str ( input, j, 16 );
			if ( n3 == 1 )
				a3 = j;
			n4 = str ( input ,j ,24 );
			if ( n4 == 1 )
				a4 = j;
		}
		cout<<a1<<'.'<<a2<<'.'<<a3<<'.'<<a4<<endl;
		n = N;
	}
}
