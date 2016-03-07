#include <iostream>
#include <iomanip>
using namespace std;
int compare ( char *a, char *b )
{
	int i;
	for ( i = 0; a[i] != NULL; i++ )
		if ( a[i] != b[i] )
			return 0;
	if ( b[i] != NULL )
		return 0;
	return 1;
}
int com ( char *a, char *b )
{
	int i = 0;
	while ( a[i] == b[i] )
		i++;
	if ( b[i] == NULL )
		return 1;
	if ( a[i] == NULL )
		return 0;
	if ( a[i] > b[i] )
		return 1;
	else
		return 0;
}
struct chang
{
	char name[10];
	int solve;
	int time[15];
	int problem[15];
	int usetime;
	int rank;
	int t;
	chang(){
		solve = 0; usetime = 0;
		t = 0;
		int i;
		for ( i = 0; i < 15; i++ )
			time[i] = problem[i] = 0;
	}
};
void swap ( char *a, char *b )
{
	int i;
	char c[20];
	for ( i = 0; a[i] != NULL; i++ )
		c[i] = a[i];
	c[i] = NULL;
	for ( i = 0; b[i] != NULL; i++ )
		a[i] = b[i];
	a[i] = NULL;
	for ( i = 0; c[i] != NULL; i++ )
		b[i] = c[i];
	b[i] = NULL; 
}
void swap ( int &a, int &b )
{
	int c;
	c = a;
	a = b;
	b = c;
}
void swap ( chang &a, chang &b )
{
	swap(a.name,b.name);
	swap(a.solve,b.solve);
	swap(a.usetime,b.usetime);
}
int main ()
{
	int tcase;
	int ic;
	int teamnum;
	int i;
	int j;
	int sub;
	int pro;
	int np;
	int nt;
	char na[5];
	char nb[10];
	cin>>tcase;
	for ( ic = 0; ic < tcase; ic++ )
	{
		cin>>teamnum;
		chang *team= new chang[teamnum+1];
		for ( i = 0; i < teamnum; i++ )
		{
			cin>>team[i].name;
		}
		cin>>pro>>sub;
		for ( i = 0; i < sub; i++ )
		{
			cin>>np>>nt>>na>>nb;
			for ( j = 0; j < teamnum; j++ )
				if ( compare(nb,team[j].name) == 1 )
					break;
			if ( nt > 300 )
				continue;
			if ( na[0] == 'N' && team[j].problem[np] == 0 )
				team[j].time[np]++;
			else if ( na[0] == 'Y' && team[j].problem[np] == 0 )
			{
				team[j].solve++;
				team[j].problem[np] = 1;
				team[j].usetime += ( 20*team[j].time[np] + nt );
				team[j].t += team[j].time[np];
			}
		}
		for ( i = 0; i < teamnum-1; i++ )
		{
			for ( j = i+1; j < teamnum; j++ )
			{
				if ( team[i].solve < team[j].solve )
					swap(team[i],team[j]);
			}
		}
		for ( i = 0; i < teamnum-1; i++ )
		{
			for ( j = i+1; j<teamnum; j++ )
			{
				if ( team[i].solve == team[j].solve && team[i].usetime > team[j].usetime )
					swap(team[i],team[j]);
			}
		}
		for ( i = 0; i < teamnum-1; i++ )
		{
			for ( j = i+1; j<teamnum; j++ )
			{
				if ( team[i].solve == team[j].solve && team[i].usetime == team[j].usetime )
					if ( com(team[i].name, team[j].name) == 1 )
						swap(team[i],team[j]);
			}
		}
		for ( i = 0; i < teamnum; i++ )
		{
			for ( j = 0; team[i].name[j] != NULL; j++ );
			while ( j < 8 )
				team[i].name[j++] = ' ';
			team[i].name[8] = NULL;
		}
		
		team[0].rank = 1;
		cout<<" 1. ";
		printf("%s ",team[0].name);
		cout<<team[0].solve<<" "<<setw(4)<<team[0].usetime<<endl;
		for ( i = 1; i < teamnum; i++ )
		{
			team[i].rank = i+1;
			if ( team[i].solve == team[i-1].solve && team[i].usetime == team[i-1].usetime )
				team[i-1].rank;
			cout<<setw(2)<<team[i].rank<<". ";
			printf("%s ",team[i].name);
			cout<<team[i].solve<<' ';
			cout<<setw(4)<<team[i].usetime<<endl;
		}
	//	if ( ic != tcase-1 )
		printf("\n");
	}
	return 1;
}