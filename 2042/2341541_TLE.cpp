#include <iostream>
#include <math.h>
using namespace std;
int count;
int a[10];
void dfs ( int lay, int key, int pre )
{
	int i = sqrt(key);
	if ( lay == 5 )
		return;
	else if ( lay == 4 )
	{
		if ( i*i == key && i >= pre )
			count++;
		return;
	}
	if ( key < pre*pre*(4-lay) )
		return;
	for ( i = pre; i <= 182; i++ )
	{
		if ( i*i < key )
		{
			a[lay] = i;
			dfs(lay+1,key-i*i,i);
		}
		else if ( i*i == key )
		{
			count++;
			break;
		}
		else 
			break;
	}
}
int main ()
{
	int n;
	while ( cin>>n && n!=0 )
	{
		count = 0;
		dfs(1,n,1);
		cout<<count<<endl;
	}
	return 0;
}