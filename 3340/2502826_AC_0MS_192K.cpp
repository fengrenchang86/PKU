#include <iostream>
using namespace std;
int comp ( char *a, char *b, int i )
{
	int j,k,flag=0;
	while ( a[i] != NULL )
	{
		if ( a[i] == '?' )
			break;
		if ( a[i] > b[i] )
		{
			flag = 1;
			break;
		}
		else if ( a[i] < b[i] )
		{
			flag = -1;
			break;
		}
		i++;
	}
	if ( a[i] == NULL )
		return 0;
	if ( flag == 1 )
	{
		j = 1;
		while ( a[i] != NULL )
		{
			if ( a[i] == '?' )
				j*=10;
			i++;
		}
	}
	else if ( flag == -1 )
		j = 0;
	else
	{
		j = 9-b[i]+'0';
		i++;
		k = i;
		while ( a[i] != NULL )
		{
			if ( a[i] == '?' )
				j*=10;
			i++;
		}
		if ( a[k] != NULL )
			j += comp(a,b,k);
	}
	return j;
}
int main ()
{
	char a[1010],b[1010];
	while ( cin>>a )
	{
		if ( a[0] == '#' )
			break;
		cin>>b;
		cout<<comp(a,b,0)<<endl;
	}
	return 0;
}
