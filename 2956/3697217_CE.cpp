#include <iostream>
using namespace std;
int a[1000100];
int dig[10];
char tch[20];
bool f ( int k )
{
	int i;
	for ( i = 0; i < 10; i++ )
		dig[i] = 0;
	while ( k )
	{
		dig[k%10]++;
		k/=10;
	}
	for ( i = 0; i < 10; i++ )
		if ( dig[i] > 1 )
			return false;
	return true;
}
int fChange( int k )
{
	int m,i,j;
	memset(dig,0,sizeof(dig));
	itoa(k,tch,10);
	for ( i = 0; tch[i] != 0; i++ )
	{
		dig[tch[i]-'0']++;
		if ( dig[tch[i]-'0'] >= 2 )
			break;
	}
	if ( tch[i] == 0 )
		return k;
	if ( tch[i] == '0' )
	{
		if ( tch[i-1] == '0' )
		{
			dig[tch[i-2]-'0']--;
			tch[i-2]--;
			dig[tch[i-2]-'0']++;
			dig[tch[i-1]-'0']--;
			tch[i-1] = '9';
			dig[9]++;
		}
		else
		{
			dig[tch[i-1]-'0']--;
			tch[i-1]--;
			dig[tch[i-1]-'0']++;
		}
		while ( tch[i] != 0 )
		{
			for ( j = 9; j > 0; j-- )
			{
				if ( dig[j] == 0 )
					break;
			}
			tch[i] = j+'0';
			dig[j] = 1;
			i++;
		}
		m = atoi(tch);
		return fChange(m);
	}
	for ( j = tch[i]-'0'; j > 0; j-- )
	{
		if ( dig[j] == 0 )
			break;
	}
	tch[i] = j+'0';
	dig[j] = 1;
	for ( i++; tch[i] != 0; i++ )
	{
		for ( j = 9; j >= 0; j-- )
		{
			if ( dig[j] == 0 )
				break;
		}
		tch[i] = j+'0';
		dig[j] = 1;
	}
	m = atoi(tch);
	return fChange(m);
}
int acm( int n)
{
	int ans = 0,i,j,k,p;
	memset(dig,0,sizeof(dig));
	itoa(n,tch,10);
	for ( i = 1; tch[i] != 0; i++ )
	{
		p = k = 9;
		for ( j = i+1; tch[j] != 0; j++,p-- )
			k *= p;
		ans += k;
	}
	k = tch[0]-'1';
	p = 9;
	for ( i = 1; tch[i] != 0; i++,p--)
		k *= p;
	ans += k;
	dig[tch[0]-'0'] = 1;
	for ( i = 1; tch[i] != 0; i++ )
	{
		dig[tch[i]-'0'] = 1;
		k = 0;
		for ( j = tch[i]-'1'; j >= 0; j-- )
		{
			if ( dig[j] == 0 )
				k++;
		}
		p = 9 - i;
		for ( j = i+1; tch[j] != 0; j++,p-- )
			k *= p;
		ans += k;
	}
	return ans+1;
}
int erfen ( int begin, int end, int m )
{
	if ( begin == end )
		return begin;
	int mid = (begin+end)/2;
	int k = acm(fChange(mid));
	if ( k == m )
		return mid;
	if ( k < m )
		return erfen(mid+1,end,m);
	else
		return erfen(begin,mid-1,m);
}
void test ()
{
	int i,x,k;
	while ( cin>>x )
	{
	/*	x = fChange(x);
		printf("after change: %d\n",x);
		printf("---%d\n",acm(x));
		k = 0;
		for ( i = 1; i <= x; i++ )
		{
			if ( f(i) )
				a[k++] = i;
		}
		printf("---%d\n",k);
	*/	x = erfen(1,2000000000,x);
		printf("%d\n",x);
	}
}

int main ()
{
	int x;
	while ( scanf("%d",&x) != EOF )
	{
		if ( x == 0 )
			break;
		printf("%d\n",erfen(1,2000000000,x));
	}
	return 0;
}