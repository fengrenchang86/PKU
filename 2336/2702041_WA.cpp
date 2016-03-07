#include <iostream>
using namespace std;
struct ac
{
	int finish,come,time;
}d[2000];
int max(int a, int b )
{
	return a>b?a:b;
}
int main ()
{
	int tcase,i,k,n,t,m,j,min;
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		scanf("%d%d%d",&n,&t,&m);
		for ( i = 1; i <= m; i++ )
			scanf("%d",&d[i].come);
		d[0].time = 0;
		d[0].finish = 0;
		for ( i = 1; i <= m; i++ )
		{
			k = max(i-n,0);
			min = 2000000000;
			d[i].time = 20000000;
			d[i].finish = 200000000;
			while ( k < i )
			{
				j = max(d[k].finish+2*t,d[i].come+2*t);
				if ( d[k].time+1 < d[i].time )
				{
					d[i].time = d[k].time+1;
					d[i].finish = j;
				}
				else if ( j < d[i].finish && d[k].time+1 == d[i].time )
					d[i].finish = j;
				k++;
			}
		}
		cout<<d[m].finish-10<<" "<<d[m].time<<endl;
	}
	return 0;
}
