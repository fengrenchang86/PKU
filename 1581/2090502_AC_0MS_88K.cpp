#include <iostream>
using namespace std;
/*
int main ()
{
	_int64 a[101][101]={0};
	_int64 b[101][101]={0};
	_int64 c[101][101]={0};
	int x,ix;
	int m,n,p;
	int tcase,it;
	int i,j,k;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%d",&x);
		scanf("%d%d",&m,&n);
		for ( i = 0; i < m; i++ )
			for ( j = 0; j < n;j++ )
				scanf("%I64d",&a[i][j]);
		for ( ix = 1; ix < x; ix++ )
		{
			scanf("%d%d",&n,&p);
			for ( i = 0; i < n; i++ )
				for ( j = 0; j < p;j++ )
					scanf("%I64d",&b[i][j]);
			for ( i = 0; i < m; i++ )
			{
				for ( j = 0;j < p; j++ )
				{
					for ( k = 0; k < n; k++ )
						c[i][j] += a[i][k]*b[k][j];
				}
			}
			for ( i = 0; i < m; i++ )
				for ( j = 0; j < p; j++ )
					a[i][j] = c[i][j];
			memset(c,0,sizeof(c));		
		}
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j < p-1; j++ )
				printf("%I64d ",a[i][j]);
			printf("%I64d\n",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/
struct ac
{
	char name[50];
	int sub[4];
	int time[4];
	int sov;
	int usetime;
	ac(){sov = 0; usetime = 0;}
};
int main ()
{
	int n,i,j;
	scanf("%d",&n);
	ac *team = new ac[n+2];
	for ( i = 1; i <= n; i++ )
	{
		scanf("%s",team[i].name);
		for ( j = 0; j < 4; j++ )
		{
			scanf("%d%d",&team[i].sub[j],&team[i].time[j]);
			if ( team[i].time[j] != 0 )
			{
				team[i].usetime += (team[i].sub[j]*20 + team[i].time[j] - 20);
				team[i].sov++;
			}
		}
	}
	for ( i = 1; i <= n-1; i++ )
	{
		for ( j = i+1; j <= n; j++ )
		{
			if ( team[i].sov < team[j].sov )
			{
				team[0] = team[i];
				team[i] = team[j];
				team[j] = team[0];
			}
		}
	}
	for ( i = 1; i <= n-1; i++ )
	{
		for ( j = i+1; j <= n; j++ )
		{
			if ( team[i].sov == team[j].sov && team[i].usetime > team[j].usetime)
			{
				team[0] = team[i];
				team[i] = team[j];
				team[j] = team[0];
			}
		}
	}
	printf("%s %d %d\n",team[1].name,team[1].sov,team[1].usetime);
	return 0;
}