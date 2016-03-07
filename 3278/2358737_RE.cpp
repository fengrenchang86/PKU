#include <iostream>
using namespace std;
int w[100500];
int stack[200100];
int bfs ( int x, int y )
{
	if ( x == y )
		return 0;
	int i,begin,end;
	for ( i = 0; i <= 100100; i++ )
		w[i] = 1000000;
	end = 1;
	begin = 0;
	stack[0] = x;
	w[x] = 0;
	while ( begin < end )
	{
		i = stack[begin%200000];
		begin++;
		if ( i*2 == y || i+1 == y || i-1 == y )
			return w[i]+1;
		if ( w[i]+1 < w[i*2] )
		{
			w[i*2] = w[i]+1;
			stack[end%200000] = i*2;
			end++;
		}
		if ( w[i]+1 < w[i+1] )
		{
			w[i+1] = w[i]+1;
			stack[end%200000] = i+1;
			end++;
		}
		if ( w[i]+1 < w[i-1] )
		{
			w[i-1] = w[i]+1;
			stack[end%200000] = i-1;
			end++;
		}
	}
	return 0;
}
int main ()
{
	int a,b;
	cin>>a>>b;
		cout<<bfs(a,b)<<endl;
	return 0;
}