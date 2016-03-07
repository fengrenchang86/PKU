#include <iostream>
using namespace std;
int a[200];
int x,y;
int n;
int sum,dig;
int v[6][6];
void p()
{
	int i,j;
	for ( i = 1; i <= 5; i++ )
	{
		for ( j = 1; j <= 5; j++ )
			printf("%d",v[i][j]);
		printf("\n");
	}
	printf("\n");
}
int digSum ( int n )
{
	int sum = 0;
	while ( n > 0 )
	{
		sum += n%10;
		n/=10;
	}
	return sum;
}
int zero( int n )
{
	while ( n > 0 )
	{
		if ( n%10 == 0 )
			return 0;
		n/=10;
	}
	return 1;
}
int Make( )
{
	int i,j,k;
	i = 0;
	for ( k = 10001; k < 99999; k+=2 )
	{
		for ( j = 3; j*j <= k; j+=2 )
		{
			if ( k%j==0)
				break;
		}
		if ( k%j != 0 && digSum(k) == sum )
		{
			a[i++] = k;
		}
	}
	return i;
}
int isprime ( int k )
{
	int mid;
	int begin = 0;
	int end = n-1;
	while ( begin < end )
	{
		mid = (begin+end)/2;
		if ( a[mid] < k )
			begin = mid+1;
		else if ( a[mid] > k )
			end = mid-1;
		else
			return 1;
	}
	if ( a[begin] == k )
		return 1;
	else
		return 0;
}
void dfs ( int c )
{
	int i,j,k;
	if ( c == 1 )
	{
		for ( i = 0; i < n; i++ )
		{
			if ( a[i]/10000 == dig && zero(a[i])==1)
			{
				j = 5;
				k = a[i];
				while ( j > 0 )
				{
					v[1][j] = k%10;
					k/=10;
					j--;
				}
				dfs(2);
			}
			else if ( a[i] / 10000 > dig )
				break;
		}
	}
	else if ( c == 2 )
	{
		for ( i = 0; i < n; i++ )
		{
			if ( a[i]/10000 == dig && zero(a[i])==1 )
			{
				j = 5;
				k = a[i];
				while ( j > 0 )
				{
					v[j][1] = k%10;
					k /= 10;
					j--;
				}
				dfs(3);
			}
			else if ( a[i]/10000 > dig )
				break;
		}
	}
	else if ( c == 3 )
	{/////////////////////////////////c==3
		for ( i = 0; i < n; i++ )
		{
			if ( a[i]/10000 == v[2][1] )
			{
				j = 5;
				k = a[i];
				while ( j > 1 )
				{
					v[2][j] = k%10;
					k/=10;
					j--;
				}
					dfs(4);
			}
			else if ( a[i]/10000 > v[2][1] )
				break;
		}
	}/////////////////////////////////c==3
	else if ( c == 4 )
	{/////////////////////////////////c==4
		for ( i = 0; i < n; i++ )
		{
			k=v[1][2]*10+v[2][2];
			if ( k == a[i]/1000 )
			{
				j = 5;
				k = a[i];
				while ( j > 2 )
				{
					v[j][2] = k%10;
					k/=10;
					j--;
				}
					dfs(5);
			}
			else if ( a[i]/1000 > k )
				break;
		}
	}/////////////////////////////////c==4
	else if ( c == 5 )
	{/////////////////////////////////c==5
		k = v[5][1]*10000+v[4][2]*1000+v[2][4]*10+v[1][5];
		i = sum-v[5][1]-v[4][2]-v[2][4]-v[1][5];
		{
			if ( isprime(k+100*i) == 1 )
			{
				v[3][3] = i;
				x = v[3][1]*100+v[3][2]*10+v[3][3];
				for ( j = 0; j < n; j++ )
				{
					if ( a[j]/100 == x )
					{
						v[3][5] = a[j]%10;
						v[3][4] = (a[j]/10)%10;
						dfs(6);
					}
					else if ( a[j]/100 > x )
						break;
				}
			}
		}
	}/////////////////////////////////c==5
	else if ( c == 6 )
	{/////////////////////////////////c==6
		x = v[1][3]+v[2][3]+v[3][3];
		y = v[1][3]*10000+v[2][3]*1000+v[3][3]*100;
		for ( i = 1; i <= 9; i+=2 )
		{
			if ( isprime(y+i+(sum-x-i)*10) == 1 )
			{
				v[5][3] = i;
				v[4][3] = sum-i-x;
				dfs(7);
			}
		}
	}/////////////////////////////////c==6
	else if ( c == 7 )
	{/////////////////////////////////c==7
		for ( i = 1; i <= 9; i+=2 )
		{
			v[5][5] = i;
			v[4][4] = sum-v[1][1]-v[2][2]-v[3][3]-v[5][5];
			v[4][5] = sum-v[1][5]-v[2][5]-v[3][5]-v[5][5];
			v[5][4] = sum-v[1][4]-v[2][4]-v[3][4]-v[4][4];
			if ( isprime(10000*v[1][1]+1000*v[2][2]+100*v[3][3]+10*v[4][4]+v[5][5]) == 0 )
				continue;
			if ( isprime(10000*v[1][5]+1000*v[2][5]+100*v[3][5]+10*v[4][5]+v[5][5]) == 0 )
				continue;
			if ( isprime(10000*v[1][4]+1000*v[2][4]+100*v[3][4]+10*v[4][4]+v[5][4]) == 0 )
				continue;
			if ( isprime(10000*v[4][1]+1000*v[4][2]+100*v[4][3]+10*v[4][4]+v[4][5]) == 0 )
				continue;
			if ( isprime(10000*v[5][1]+1000*v[5][2]+100*v[5][3]+10*v[5][4]+v[5][5]) == 0 )
				continue;
			p();
		}
	}/////////////////////////////////c==7
}
int main ()
{
	int i = 0;
	scanf("%d%d",&sum,&dig);
	n = Make();
	dfs(1);
	return 0;
}