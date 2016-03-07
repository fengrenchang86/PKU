#include <iostream>
using namespace std;
bool visit[1200000];
int main ()
{
	int it,tc,i,j,k,max,min;
	int w[4];
	scanf("%d",&tc);
	for ( it = 0; it < tc; it++ )
	{
		min = 2000000000;
		for ( j = 0; j < 4; j++ )
		{
			scanf("%d",&w[j]);
			if ( w[j] < min )
				min = w[j];
		}
		memset(visit,false,sizeof(visit));
		visit[0] = true;
		k = 0;
		max = -1;
		for ( i = 0; i <= 1000000; i++ )
		{
			for ( j = 0; j < 4; j++ )
			{
				if ( i-w[j] >= 0 && visit[i-w[j]] == true )
				{
					k++;
					visit[i] = true;
					max = i;
					break;
				}
			}
		}
		cout<<1000000-k<<endl;
		for ( i = 1000000; i >= 0; i-- )
			if ( visit[i] == false )
				break;
		k = 0;
		for ( i = 1; i <= 1000000 && k < min; i++ )
		{
			if ( visit[i] == true )
				k++;
			else
				k = 1;
		}
		if ( k == min )
			cout<<i<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}