#include <iostream>
#include <iomanip>
using namespace std;
void main ( )
{
	int f ( int, int );
	int rexp ( int, int );
	int i;
	int m;
	int p;
	int d;
	int n;
	int count;
	int caset = 1;
	while ( cin>>p>>m && p!= 0 && m!=0 )
	{
		n = 0;
		i = m;
		d = p - m - 1 + i;
		count = 1;
		while ( i > m/2+1 )
		{
			n += rexp(i,p) - rexp(m+1-i,p);
			if ( n == 0 )
				count ++;
			i --;
		}
		count*=2;
		if ( m%2==0)
		{
			n += rexp(i,p) - rexp(m+1-i,p);
			if ( n == 0 )
				count ++;
		}
		count %= 10000;
		cout<<"Case "<<caset<<": ";
		cout<<setw(4)<<setfill('0')<<count<<endl;
		caset++;
	}
		
	
}
/*
int f ( int n, int k )	//返回小于等于n的数中，最大的一个能够被k整除的数
{
	return n / k * k;
}*/

int rexp ( int n, int k )	//返回n模k的次数，如果n不是k的倍数，返回－1
{
	int c = 0;
	int h = n;
	while ( h % k == 0 )
	{
		h /= k;
		c++;
	}
	return c;
}

