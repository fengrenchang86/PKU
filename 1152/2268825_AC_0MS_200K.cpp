#include <iostream>
using namespace std;
int v[70];
int max;
int f ( char a )
{
	if ( a <= '9' )
		return a-'0';
	else if ( a <= 'Z' )
		return a-'A'+10;
	else
		return a-'a'+36 ;
}
int main ()
{
	char ch[80000];
	int i,j,k;
	int len;
	int c;
	int t;
	while ( cin>>ch )
	{
		len = strlen(ch);
		max = int('0');
		for ( i = 0; i < len; i++ )
		{
			if ( ch[i] > max )
				max = ch[i];
		}
		if ( max <= '9' )
			max -= '0';
		else if ( max <= 'Z' )
			max -= ('A'-10);
		else
			max -= ('a'-36);
		t = max+1;
		while ( t <= 62 )
		{
			max = t-1;
			c = 0;
			for ( i = len-1; i >=0; i-- )
			{
				c += f(ch[i]);
			}
			c %= max;
			if ( c  == 0 )
				break;
			t++;
		}
		if ( t <= 62 )
			cout<<t<<endl;
		else
			cout<<"such number is impossible!"<<endl;
	}
	return 0;
}