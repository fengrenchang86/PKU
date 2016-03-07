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
//			cin>>a[i];
			scanf("%d",&a[i]);
			if ( max < a[i] )
				max = a[i];
		}
		cin>>dry;
		if ( dry == 1 )
		{
			printf("%I64d\n",max);
			return 0;
		}
		begin = 1;
		end = max;
		mid = (begin+end)/2;
		while ( begin+1 <= end )
		{
			count = 0;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
				{
					count += (a[i]-mid)/(dry-1);
					if ( (a[i]-mid)%(dry-1) != 0 )
						count++;
				}
				if ( count > mid )
					break;
			}
			if ( count <= mid )
				end = mid;
			else if ( count > mid )
				begin = mid+1;
			mid = (begin+end)/2;
		}
		printf("%I64d\n",end);
	}
	return 0;
}