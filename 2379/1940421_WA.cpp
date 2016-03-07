#include <iostream>
using namespace std;

class acm
{
public:
	int problem[30];
	int time;
	int t[30];
	int solve;
	int num;
	acm()
	{
		for ( int i = 0; i < 30; i++ )
			t[i] = problem[i] = 0;
		time = 0;
		solve = 0;
	}
};

int main ()
{
	acm *team[1200];
	acm *k;
	int c,n;
	int i,j;
	int ci,pi,ti,ri;
	scanf("%d %d",&c,&n);
	for ( i = 0; i <=c; i++ )
		team[i] = new acm;
	for ( i = 1; i <= c; i++ )
		team[i]->num = i;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d %d %d %d",&ci,&pi,&ti,&ri);
		if ( ri == 0 && team[ci]->problem[pi] == 0 )
			team[ci]->t[pi]++;
		else if ( ri == 1 && team[ci]->problem[pi] == 0 )
		{
			team[ci]->time+=ti;
			team[ci]->time+=1200*team[ci]->t[pi];
			team[ci]->problem[pi] = 1;
			team[ci]->solve++;
		}
	}
	for ( i = 1; i < c; i++ )
	{
		for ( j = i+1; j <= c; j++ )
		{
			if ( team[i]->solve < team[j]->solve )
			{
				k = team[i];
				team[i] = team[j];
				team[j] = k;
			}
		}
	}
	for ( i = 1; i < c; i++ )
	{
		for ( j = i+1; j <=c; j++ )
		{
			if ( team[i]->solve == team[j]->solve )
			{
				if ( team[i]->time > team[j]->time )
				{
					k = team[i];
					team[i] = team[j];
					team[j] = k;
				}
				else if ( team[i]->time == team[j]->time )
				{
					if ( team[i]->num > team[j]->num )
					{
						k = team[i];
						team[i] = team[j];
						team[j] = k;
					}
				}
			}
		}
	}
	printf("%d",team[1]->num);
	for ( i = 2; i <= c; i++ )
		printf(" %d",team[i]->num);
	printf("\n");
	return 1;
}
