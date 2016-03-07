#include <iostream>
using namespace std;
double pow[40];
double a[40];
double b[40];
int v[40] = {0};
int flag = 0;
double sum;
void dfs(  int position)
{
	if ( sum == 0 )
	{
		flag = 1;
		return;
	}
	if ( position == -1 )
		return;
	v[position] = 1;
	if ( position < 5 )
	{
		sum -= pow[position];
		dfs(position-1);
		sum += pow[position];
	}
	else if ( sum-pow[position] >= 0 && sum-pow[position] <= a[position]
		|| sum-pow[position] <= 0 && sum-pow[position] >= b[position] )
	{
		sum -= pow[position];
		dfs(position-1);
		sum += pow[position];
	}
	if ( flag == 1 )
		return;
	v[position] = 0;
	if ( position < 5 )
		dfs(position-1);
	else if ( sum >= 0 && sum <= a[position] ||
		sum <= 0 && sum >= b[position] )
		dfs(position-1);
}
int main ()
{
	int i;
	pow[0] = 1;
	for ( i = 1; i <= 35; i++ )
		pow[i] = pow[i-1]*(-2);
	a[1] = a[0] = pow[0];
	b[0] = 0;
	b[1] = -2;
	for ( i = 2; i <= 35; i++ )
	{
		if ( i % 2 == 0 )
		{
			a[i] = a[i-2] + pow[i];
			b[i] = b[i-1];
		}
		else
		{
			a[i] = a[i-1];
			b[i] = b[i-2] + pow[i];
		}
	}
	cin>>sum;
	dfs(35);
	i = 35;
	while ( v[i] == 0 && i >= 0)
		i--;
	if ( i < 0 )
		cout<<0<<endl;
	else
	{
		while ( i >= 0 )
		{
			cout<<v[i];
			i--;
		}
		cout<<endl;
	}
	return 0;
}