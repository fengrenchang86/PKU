#include <iostream>
using namespace std;
char a[300],b[300];
int lista[10],listb[10];
bool check ()
{
	int i;
	for ( i = 0; i < 10; i++ )
	{
		if ( lista[i]==0 && listb[i] > 0 )
			return false;
		if ( lista[i] != 0 && listb[i] == 0 )
			return false;
	}
	return true;
}
void solve ( )
{
	int i,n;
	int x,y;
	memset(lista,0,sizeof(lista));
	memset(listb,0,sizeof(listb));
	scanf(" %s %s",a,b);
	for ( i = 0; a[i] != 0; i++ )
		lista[a[i]-'0']++;
	for ( i = 0; b[i] != 0; i++ )
		listb[b[i]-'0']++;
	if ( check() )
	{
		printf("friends\n");
		return;
	}
	n = strlen(a);
	for ( i = 0; i < n-1; i++ )
	{
		x = a[i]-'0';
		y = a[i+1]-'0';
		if ( x-1 >= 0 && y+1 <= 9 && ( i!=0 || x != 1 ))
		{
			lista[x]--;
			lista[y]--;
			lista[x-1]++;
			lista[y+1]++;
			if ( check() )
			{
				printf("almost friends\n");
				return;
			}
			lista[x]++;
			lista[y]++;
			lista[x-1]--;
			lista[y+1]--;
		}
		if ( x+1 <= 9 && y-1 >= 0 )
		{
			lista[x]--;
			lista[y]--;
			lista[x+1]++;
			lista[y-1]++;
			if ( check() )
			{
				printf("almost friends\n");
				return;
			}
			lista[x]++;
			lista[y]++;
			lista[x+1]--;
			lista[y-1]--;
		}
	}
	n = strlen(b);
	for ( i = 0; i < n-1; i++ )
	{
		x = b[i]-'0';
		y = b[i+1]-'0';
		if ( x-1 >= 0 && y+1 <= 9 && (i!=0||x!=1))
		{
			listb[x]--;
			listb[y]--;
			listb[x-1]++;
			listb[y+1]++;
			if ( check() )
			{
				printf("almost friends\n");
				return;
			}
			listb[x]++;
			listb[y]++;
			listb[x-1]--;
			listb[y+1]--;
		}
		if ( x+1 <= 9 && y-1 >= 0 )
		{
			listb[x]--;
			listb[y]--;
			listb[x+1]++;
			listb[y-1]++;
			if ( check() )
			{
				printf("almost friends\n");
				return;
			}
			listb[x]++;
			listb[y]++;
			listb[x+1]--;
			listb[y-1]--;
		}
	}
	printf("nothing\n");
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}