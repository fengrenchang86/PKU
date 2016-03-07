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
		while ( i > 0 )
		{
			n += rexp(i,p) - rexp(m+1-i,p);
			if ( n == 0 )
				count ++;
			count %= 10000;
			i --;
		}
		cout<<"Case "<<caset<<": ";
		cout<<setw(4)<<setfill('0')<<count<<endl;
		caset++;
	}
		
	
}


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

