#include <iostream>
using namespace std;
struct acm
{
	int num;
	int solve;
	int problem[30];
	int actime[30];
	int t[30];
	int usetime;
	acm()
	{
		solve = usetime = 0;
		for ( int i = 0; i < 30; i++ )
		{
			t[i] = problem[i] = 0;
			actime[i] = 50000000;
		}
	}
};
struct r
{
	int ci,pi,ti,ri;
}run[1200];
int main ()
{
	int c,n,ci,pi,ti,ri;
	acm *team[1500];
	acm *temp;
	int i,j;
	scanf("%d %d",&c,&n);
	for ( i = 0; i <= c+1; i++ )
		team[i] = new acm;
	for ( i = 0; i <= c+1; i++ )
		team[i]->num = i;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d %d %d %d",&run[i].ci,&run[i].pi,&run[i].ti,&run[i].ri);
		ci = run[i].ci;
		pi = run[i].pi;
		ti = run[i].ti;
		ri = run[i].ri;
		if ( team[ci]->actime[pi] > ti && ri == 1 && ti <= 36000 )
		{
			team[ci]->actime[pi] = ti;
			if ( team[ci]->problem[pi] == 0 )
				team[ci]->solve++;
			team[ci]->problem[pi] = 1;
		}
	}
	for ( i = 0; i < n; i++ )
	{
		if ( team[run[i].ci]->problem[run[i].pi] == 0 )
			continue;
		if ( team[run[i].ci]->actime[run[i].pi] > run[i].ti )
		{
			if ( run[i].ri == 0)
				team[run[i].ci]->usetime += 1200;
		}
		else if ( team[run[i].ci]->actime[run[i].pi] == run[i].ti && run[i].ri == 1 &&
			team[run[i].ci]->t[run[i].pi] == 0)
		{
			team[run[i].ci]->usetime += team[run[i].ci]->actime[run[i].pi];
			team[run[i].ci]->t[run[i].pi] = 1;
		}
	}
	for ( i = 1; i < c; i++ )
	{
		for ( j = i+1; j <= c; j++ )
		{
			if ( team[i]->solve < team[j]->solve )
			{
				temp = team[i];
				team[i] = team[j];
				team[j] = temp;
			}
		}
	}
	for ( i = 1; i < c; i++ )
	{
		for ( j = i+1; j <= c; j++ )
		{
			if ( team[i]->solve == team[j]->solve )
			{
				if ( team[i]->usetime > team[j]->usetime )
				{
					temp = team[i];
					team[i] = team[j];
					team[j] = temp;
				}
			}
		}
	}
	for ( i = 1; i < c; i++ )
	{
		for ( j = i+1; j <= c; j++ )
		{
			if ( team[i]->solve==team[j]->solve&&team[i]->usetime==team[j]->usetime)
				if ( team[i]->num > team[j]->num )
				{
					temp = team[i];
					team[i] = team[j];
					team[j] = temp;
				}
		}
	}
	printf("%d",team[1]->num);
	for ( i = 2; i <= c; i++ )
		printf(" %d",team[i]->num);
	printf("\n");
	return 1;
}
