#include<iostream>
#include<fstream>
using namespace std;

int main()
{
//	fstream cin("in.txt");
	int n,i,a[100100];
	int begin;
	int end;
	int mid;
	int dry;
	int count;
	int max;
	while ( cin>>n )
	{
		max = 0;
		for ( i = 0; i < n; i++ )
		{
			cin>>a[i];
			if ( max < a[i] )
				max = a[i];
		}
		cin>>dry;
		begin = 1;
		end = max/dry+max%dry;
		mid = (begin+end)/2;
		while ( begin != mid )
		{
			count = 0;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
					count += (a[i]-mid+dry)/dry;
			}
			if ( count < mid )
				end = mid;
			else
				begin = mid;
			mid = (begin+end)/2;
		}
		cout<<mid+1<<endl;
	}
	return 0;
}