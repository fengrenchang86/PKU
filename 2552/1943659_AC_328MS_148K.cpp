#include <iostream>
using namespace std;
int main ()
{
	int k;
	int i;
	bool a[40000] = {false};
	int c = 1;
	int j = 0;
	int l[3001];
	int p;
	l[0] = 2;
	while ( c <= 3000 )
	{
		j = l[c-1];
		while ( a[j] == true )
			j++;
		l[c++] = j;
		a[j] = true;
		p = 0;
		while ( j <= 40000 )
		{
			if ( a[j] == false )
				p++;
	//		j++;
			if ( p == l[c-1] )
			{
				p = 0;
				a[j] = true;
			}
			j++;
		}
	}
	int n;
	while ( scanf("%d",&n) && n!= 0 )
	{
		printf("%d\n",l[n]);
	}
	return 1;
}