#include <iostream>
using namespace std;
int v[5],a[5];
int t[30];
int Type,Number,Max;
int price,n;
bool unique;
bool yes;
void dfs ( int lay, int sum, int pos, int type )
{
	if ( sum > price || lay > 4 )
		return;
	int i;
	if ( sum == price )
	{
		if ( type > Type )
		{
			for ( i = 0; i < lay; i++ )
				v[i] = a[i];
			Type = type;
			Number = lay;
			Max = t[pos];
			yes = true;
			unique = true;
		}
		else if ( type == Type && lay < Number )
		{
			for ( i = 0; i < lay; i++ )
				v[i] = a[i];
			Type = type;
			Number = lay;
			Max = t[pos];
			unique = true;
			yes = true;
		}
		else if ( type == Type && lay == Number && t[pos] > Max )
		{
			for ( i = 0; i < lay; i++ )
				v[i] = a[i];
			Type = type;
			Number = lay;
			Max = t[pos];
			yes = true;
			unique = true;
		}
		else if ( type == Type && lay == Number && t[pos] == Max )
			unique = false;
		return ;
	}
	if ( lay == 4 )
		return;
	a[lay] = t[pos];
	if ( sum + t[pos] > price )
		return;
	dfs ( lay+1, sum+t[pos],pos,type);
	for ( i = pos+1; i < n; i++ )
	{
		a[lay] = t[i];
		if( sum + t[i] > price )
			break;
		dfs(lay+1,sum+t[i],i,type+1);
	}
}
int main ()
{
	int i,j,d;
	n = 0;
	while ( scanf("%d",&d) != EOF )
	{
		t[n++] = d;
		while ( scanf("%d",&d) && d!=0 )
			t[n++] = d;
		for ( i = 0; i < n-1; i++ )
		{
			for ( j = i+1; j < n; j++ )
			{
				if( t[i] > t[j] )
				{
					d = t[i];
					t[i] = t[j];
					t[j] = d;
				}
			}
		}
		while ( scanf("%d",&price) && price != 0 )
		{
			yes = false;
			unique = false;
			Type = 0;
			Number = 0;
			Max = 0;
			for ( i = 0; i < n; i++ )
			{
				a[0] = t[i];
				dfs(1,a[0],i,1);
			}
			if ( yes == false )
				printf("%d ---- none\n",price);
			else if ( unique == true )
			{
				printf("%d (%d):",price,Type);
				for ( i = 0; i < Number; i++ )
					printf(" %d",v[i]);
				printf("\n");
			}
			else
				printf("%d (%d): tie\n",price,Type);
		}
		n = 0;
	}
	return 0;
}