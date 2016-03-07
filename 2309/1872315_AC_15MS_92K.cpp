#include <iostream>
using namespace std;
void make ( unsigned int t[] )
{
	int i;
	t[0] = 1;
	for ( i = 1; i <= 31; i++ )
		t[i] = t[i-1]*2;
}

int main () 
{
	unsigned int list[32];
	int i;
	make ( list );
	int n;
	cin>>n;
	int k;
	int pk;
	int j;
	int left;
	int right;
	int count;
	for ( i = 0; i < n; i++ )
	{
		cin>>k;
		for ( j = 0; k > list[j]; j++ );
		if ( k == list[j] )
		{
			left = 1;
			right = 2*k - left;
		}
		else
		{
			j--;
			pk = list[j];
			count = j-1;
			while ( pk != k )
			{
				if ( pk > k )
					pk = pk-list[count--];
				else if ( pk < k )
					pk = pk+list[count--];
			}
			while ( count >= 0 )
				pk = pk-list[count--];
			left = pk;
			right = 2*k-pk;
		}
		cout<<left<<" "<<right<<endl;
	}
	return 1;
}