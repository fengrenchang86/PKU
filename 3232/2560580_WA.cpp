#include <iostream>
using namespace std;
int main ()
{
	int a[100200];
	int tcase,n,m,k,i,v;
	int begin,end,mid;
	_int64 t;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		scanf("%d%d",&m,&k);
		if ( k == 1 )
		{
			k = 0;
			for ( i = 1; i < n; i++ )
				if ( a[i] > a[k] )
					k = i;
			cout<<a[k]<<endl;
			continue;
		}
		k--;
		begin = 0;
		end = 100000000;
		while ( begin+1 <= end )
		{
			mid = (begin+end)/2;
			t = mid*m;
			for ( i = 0; i < n; i++ )
			{
				if ( a[i] > mid )
				{
					if ( (a[i]-mid)%k == 0 )
						v = (a[i]-mid)/k;
					else
						v = (a[i]-mid)/k+1;
					if ( v > mid )
						t = -1;
					else
						t -= v;
					if ( t < 0 )
						break;
				}
			}
			if ( t < 0 )
				begin = mid+1;
			else 
				end = mid;
			
		}
		printf("%d\n",end);
	}
	return 0;
}