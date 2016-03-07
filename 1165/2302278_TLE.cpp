#include <iostream>
using namespace std;
int a[10000];
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
				if ( v[1][2]+v[2][2]<=sum&&v[1][2]+v[2][2]>=sum-27 &&
					v[1][3]+v[2][3]<=sum&&v[1][3]+v[2][3]>=sum-27 &&
					v[1][4]+v[2][4]<=sum&&v[1][4]+v[2][4]>=sum-27 &&
					v[1][5]+v[2][5]<=sum&&v[1][5]+v[2][5]>=sum-27)
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
			k = a[i]-a[i]/10000*10000;
			if ( a[i]/10000 == v[1][2] && k/1000 == v[2][2] )
			{
				j = 5;
				k = a[i];
				while ( j > 2 )
				{
					v[j][2] = k%10;
					k/=10;
					j--;
				}
				if ( v[3][1]+v[3][2]<=sum && v[3][1]+v[3][2]>=sum-27 &&
					v[4][1]+v[4][2]<=sum && v[4][1]+v[4][2]>=sum-27 &&
					v[5][1]+v[5][2]<=sum && v[5][1]+v[5][2]>=sum-27 )
					dfs(5);
			}
			else if ( a[i]/10000 > v[1][2] )
				break;
		}
	}/////////////////////////////////c==4
	else if ( c == 5 )
	{/////////////////////////////////c==5
		for ( i = 0; i < n; i++ )
		{
			k = a[i]-a[i]/10000*10000;
			if ( a[i]/10000 == v[3][1] && k/1000 == v[3][2] )
			{
				j = 5;
				k = a[i];
				while ( j > 2 )
				{
					v[3][j] = k%10;
					k/=10;
					j--;
				}
				k = 0;
				for ( j = 5; j >= 1; j-- )
				{
					k *= 10;
					k += v[j][6-j];
				}
				if ( digSum(k) == sum )
					if (v[1][3]+v[2][3]+v[3][3]<=sum&&v[1][3]+v[2][3]+v[3][3]>=sum-18 &&
						v[1][4]+v[2][4]+v[3][4]<=sum&&v[1][4]+v[2][4]+v[3][4]>=sum-18 &&
						v[1][5]+v[2][5]+v[3][5]<=sum&&v[1][5]+v[2][5]+v[3][5]>=sum-18 )
							if ( isprime(k) == 1 )
								dfs(6);
			}
			else if ( a[i]/10000 > v[3][1] )
				break;
		}
	}/////////////////////////////////c==5
	else if ( c == 6 )
	{/////////////////////////////////c==6
		for ( i = 0; i < n; i++ )
		{
			k = v[1][3]*100+v[2][3]*10+v[3][3];
			if ( a[i]/100 == k )
			{
				k = a[i];
				j = 5;
				while ( j > 3 )
				{
					v[j][3] = k%10;
					k/=10;
					j--;
				}
				if ( v[4][1]+v[4][2]+v[4][2]<=sum && v[4][1]+v[4][2]+v[4][3] >= sum-18 &&
					v[5][1]+v[5][2]+v[5][2]<=sum && v[5][1]+v[5][2]+v[5][3] >= sum-18 )
					dfs(7);
			}
			else if ( a[i]/100 > k )
				break;
		}
	}/////////////////////////////////c==6
	else if ( c == 7 )
	{/////////////////////////////////c==7
		for ( i = 0; i < n; i++ )
		{
			k = v[4][1]*100+v[4][2]*10+v[4][3];
			if ( a[i] / 100 == k )
			{
				k = a[i];
				j = 5;
				while ( j > 3 )
				{
					v[4][j] = k%10;
					k/=10;
					j--;
				}
				k = v[1][4]+v[2][4]+v[3][4]+v[4][4];
				j = v[1][5]+v[2][5]+v[3][5]+v[4][5];
				if ( k<=sum && k>=sum-9 && j<=sum && j>= sum-9 )
					dfs(8);
			}
			else if ( a[i]/100 > k )
				break;
		}
	}/////////////////////////////////c==7
	else if ( c == 8 )
	{
		for ( i = 0; i <= 9; i++ )
		{
			if ( i != 0 && i%2==0 )
				continue;
			k = 10000*v[1][4]+1000*v[2][4]+100*v[3][4]+10*v[4][4];
	//		if ( v[5][1]+v[5][2]+v[5][3]+v[5][4] <= sum &&
	//			v[5][1]+v[5][2]+v[5][3]+v[5][4] >= sum-9 )
			if ( isprime(k+i) == 1 && digSum(k+i) == sum )
			{
				v[5][4] = i;
				dfs(9);
			}
		}
	}
	else
	{
		k = 10000*v[1][5]+1000*v[2][5]+100*v[3][5]+10*v[4][5];
		j = 10000*v[5][1]+1000*v[5][2]+100*v[5][3]+10*v[5][4];
		c = 10000*v[1][1]+1000*v[2][2]+100*v[3][3]+10*v[4][4];
		for ( i = 1; i <= 9; i+=2 )
		{
			if ( isprime (k+i) == 1 && isprime(j+i)==1 && isprime(c+i) == 1 && digSum(k+i)==sum)
			{
				v[5][5] = i;
				p();
			}
		}
	}
}

void f ( int count )
{
	int i,j,k,t;
	if ( count == 6 )
	{
		for ( j = 1; j <= 5; j++ )
		{
			if ( v[5][j] % 2== 0 )
				return;
			k = 0;
			t = 0;
			for ( i = 1; i <= 5; i++ )
			{
				k+=v[i][j];
				t *= 10;
				t += v[i][j];
			}
			if ( k != sum )
				return;
			else if ( isprime(t) == 0 )
				return;
		}
		k = 0;
		t = 0;
		for ( j = 1; j <= 5; j++ )
		{
			t *= 10;
			t+= v[j][j];
			k+=v[j][j];
		}
		if ( k != sum )
			return ;
		else if ( isprime(t) == 0 )
			return ;
		k = 0;
		t = 0;
		for(  j =1; j <= 5; j++ )
		{
			k += v[6-j][j];
			t *= 10;
			t += v[6-j][j];
		}
		if ( k != sum )
			return;
		else if ( isprime(t) == 0 )
			return;
		p();
	}
	if ( count == 1 )
	{
		for ( i = 0; i < n; i++ )
		{
			if ( zero(a[i]) == 1 )
			{
				k = a[i];
				j = 5;
				while ( k > 0 )
				{
					v[1][j] = k%10;
					k/=10;
					j--;
				}
				f(2);
			}
		}
	}
	else
	{
		for ( i = 0; i < n; i++ )
		{
			k = a[i];
			j = 5;
			while ( k > 0 )
			{
				v[count][j] = k%10;
				k/=10;
				j--;
			}
			f(count+1);
		}
	}
}
int main ()
{
	int i = 0;
	scanf("%d%d",&sum,&dig);
	n = Make();
	dfs(1);
//	f(1);
	return 0;
}