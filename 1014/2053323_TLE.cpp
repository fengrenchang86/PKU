#include <iostream>
using namespace std;
const int MAX = 130010;
int a[MAX];
int h[7];
bool l[MAX]={0};
int flag = 0;
void dfs ( int t, int sum, int position, int num )
{
	if ( t == sum )
	{
		flag = 1;
		return;
	}
	while ( t+a[position] > sum || l[position] == 1 )
	{
		if ( position > num )
			break;
		position++;
	}
	if ( position > num )
		return;
	if ( t + a[position] == sum )
	{
		flag = 1;
		return;
	}
	t += a[position];
	if ( a[position] != a[position-1] )
	{
		if ( t -a[position] + h[a[position]] == sum )
		{
			flag = 1;
			return;
		}
		else if ( t - a[position] + h[a[position]] > sum )
		{
			l[position] = 1;
			dfs(t,sum,position+1,num);
			l[position] = 0;
		}
	}
	else if ( l[position-1] == 1 )
	{
		l[position] = 1;
		dfs(t,sum,position+1,num);
		l[position] = 0;
	}
	if ( flag == 1 )
		return;
	t -= a[position];
	if ( t + h[a[position]] > sum )
		dfs(t,sum,position+1,num);
}
int main ()
{
	int v[6];
	int i,j,sum,num;
	int tcase = 1;
	while ( scanf("%d %d %d %d %d %d",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5]) )
	{
		l [0] = 1;
		a[0] = 0;
		num = v[0] + v[1] + v[2] + v[3] + v[4] + v[5];
		if ( num == 0 )
			break;
		printf("Collection #%d:\n",tcase);
		tcase++;
		sum = v[0]+2*v[1]+3*v[2]+4*v[3]+5*v[4]+6*v[5];
		if ( sum %2==1 )
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum /= 2;
		j = 1;
		for ( i = 0; i < v[5]; i++ )
			a[j++] = 6;
		for ( i = 0; i < v[4]; i++ )
			a[j++] = 5;
		for ( i = 0; i < v[3]; i++ )
			a[j++] = 4;
		for ( i = 0; i < v[2]; i++ )
			a[j++] = 3;
		for ( i = 0; i < v[1]; i++ )
			a[j++] = 2;
		for ( i = 0; i < v[0]; i++ )
			a[j++] = 1;
		for ( i = 1; i <= sum; i++ )
			l[i] = 0;
		h[1] = v[0];
		for ( i = 2; i <= 6; i++ )
			h[i] = h[i-1] + (i)*v[i];
		dfs(0,sum,1,num);
		if ( flag == 1 )
			printf("Can be divided.\n");
		else
			printf("Can't be divided.\n");
		
		flag = 0;
		printf("\n");
	}
	return 0;
}