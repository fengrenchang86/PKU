#include <iostream>
using namespace std;
char t[10000];
int pos;
double realnumber ()
{
	int x=0;
	int sign=1;
	double ans = 0.0,d;
	while ( t[pos] == ' ' )
		pos++;
	if ( t[pos] == '-' )
	{
		sign = -1;
		pos++;
	}
	if ( t[pos] == '.' )
	{
		pos++;
		d = 0.1;
		while ( t[pos] >= '0' && t[pos] <= '9' )
		{
			ans += d*(t[pos]-'0');
			d /= 10.0;
			pos++;
		}
	}
	else
	{
		while ( t[pos] >= '0' && t[pos] <= '9' )
		{
			x *= 10;
			x += (t[pos]-'0');
			pos++;
		}
		if ( t[pos] == '.' )
		{
			pos++;
			d = 0.1;
			while ( t[pos] >= '0' && t[pos] <= '9' )
			{
				ans += d*(t[pos]-'0');
				d /= 10.0;
				pos++;
			}
		}
		ans += x;
	}
	return sign*ans;
}
double f ()
{
	pos++;
	double p,e1,e2;
	p = realnumber();
	while ( t[pos] == ' ' )
		pos++;
	if ( t[pos] == '(' )
		e1 = f();
	else
		e1 = realnumber();
	while ( t[pos] == ' ' )
		pos++;
	if ( t[pos] == '(' )
		e2 = f();
	else
		e2 = realnumber();
	while ( t[pos] == ' ' )
		pos++;
	if ( t[pos] == ')' )
		pos++;
	return p*(e1+e2)+(1-p)*(e1-e2);
}
void solve()
{
	pos = 0;
	printf("%lf\n",f());
}
int main ()
{
	while ( cin.getline(t,1000,'\n') )
	{
		if ( t[0] == '(' && t[1] == ')' )
			break;
		solve();
	}
	return 0;
}