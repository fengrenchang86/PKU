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
			scanf("%d",&a[i]);
			if ( max < a[i] )
				max = a[i];
		}
		cin>>dry;
		if ( dry == 1 )
		{
			printf("%d\n",max);
			return 0;
		}
		begin = 1;
		end = max;
		mid = (begin+end)/2;
		while ( begin < end )
		{
			count = 0;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
					count += (a[i]-mid+dry-1)/(dry);
			}
			if ( count < mid )
				end = mid;
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