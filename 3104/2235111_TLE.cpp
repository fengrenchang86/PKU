#include<iostream>
#include<fstream>
using namespace std;

int main()
{
//	fstream cin("in.txt");
	int n,i,a[100100];
	int dry;
	int count;
	_int64 begin,end,mid,max;
	cin>>n;
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
		end = max;
		mid = (begin+end)/2;
		while ( begin != end )
		{
			count = 0;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
					count += (a[i]-mid+dry)/dry;
			}
			if ( count < mid )
				end = mid-1;
			else if ( count > mid )
				begin = mid+1;
			else
				break;
			mid = (begin+end)/2;
		}
		printf("%I64d\n",mid);
	}
	return 0;
}
