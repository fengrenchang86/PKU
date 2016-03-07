	#include <iostream>
#include <string>
#include <stdlib.h>
	using namespace std;
	int acmDig[10];
	char tch[20];
	bool f ( int k )
	{
		int i;
		for ( i = 0; i < 10; i++ )
			acmDig[i] = 0;
		while ( k )
		{
			acmDig[k%10]++;
			k/=10;
		}
		for ( i = 0; i < 10; i++ )
			if ( acmDig[i] > 1 )
				return false;
		return true;
	}
	int acmChange( int k )
	{
		int m,i,j;
		memset(acmDig,0,sizeof(acmDig));
		itoa(k,tch,10);
		for ( i = 0; tch[i] != 0; i++ )
		{
			acmDig[tch[i]-'0']++;
			if ( acmDig[tch[i]-'0'] >= 2 )
				break;
		}
		if ( tch[i] == 0 )
			return k;
		if ( tch[i] == '0' )
		{
			if ( tch[i-1] == '0' )
			{
				acmDig[tch[i-2]-'0']--;
				tch[i-2]--;
				acmDig[tch[i-2]-'0']++;
				acmDig[tch[i-1]-'0']--;
				tch[i-1] = '9';
				acmDig[9]++;
			}
			else
			{
				acmDig[tch[i-1]-'0']--;
				tch[i-1]--;
				acmDig[tch[i-1]-'0']++;
			}
			while ( tch[i] != 0 )
			{
				for ( j = 9; j > 0; j-- )
				{
					if ( acmDig[j] == 0 )
						break;
				}
				tch[i] = j+'0';
				acmDig[j] = 1;
				i++;
			}
			m = atoi(tch);
			return acmChange(m);
		}
		for ( j = tch[i]-'0'; j > 0; j-- )
		{
			if ( acmDig[j] == 0 )
				break;
		}
		tch[i] = j+'0';
		acmDig[j] = 1;
		for ( i++; tch[i] != 0; i++ )
		{
			for ( j = 9; j >= 0; j-- )
			{
				if ( acmDig[j] == 0 )
					break;
			}
			tch[i] = j+'0';
			acmDig[j] = 1;
		}
		m = atoi(tch);
		return acmChange(m);
	}
	int acm( int n)
	{
		int ans = 0,i,j,k,p;
		memset(acmDig,0,sizeof(acmDig));
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
		acmDig[tch[0]-'0'] = 1;
		for ( i = 1; tch[i] != 0; i++ )
		{
			acmDig[tch[i]-'0'] = 1;
			k = 0;
			for ( j = tch[i]-'1'; j >= 0; j-- )
			{
				if ( acmDig[j] == 0 )
					k++;
			}
			p = 9 - i;
			for ( j = i+1; tch[j] != 0; j++,p-- )
				k *= p;
			ans += k;
		}
		return ans+1;
	}
	int erfen ( int Tbegin, int Tend, int m )
	{
		if ( Tbegin == Tend )
			return Tbegin;
		int mid = (Tbegin+Tend)/2;
		int k = acm(acmChange(mid));
		if ( k == m )
			return mid;
		if ( k < m )
			return erfen(mid+1,Tend,m);
		else
			return erfen(Tbegin,mid-1,m);
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