#include <iostream>
using namespace std;
const int MAX = 130010;
int a[MAX];
int h[7];
int v[7];
bool l[MAX]={0};
int flag = 0;
void div ( int left, int right, int sum, int k, int count )
{
	if ( left == sum || right == sum )
	{
		flag = 1;
		return;
	}
	if ( k == 0 )
	{
		flag = -1;
		return;
	}
	int i;
	for ( i = 0; i <= count; i++ )
	{
		if ( left+i*k+h[k-1] > right+(count-i)*k && left+i*k < right+(count-i)*k+h[k-1] )
			div(left+i*k,right+(count-i)*k,sum,k-1,v[k-1]);
		else if ( left+i*k+h[k-1] == right+(count-i)*k || left+i*k == right+(count-i)*k+h[k-1] )
		{
			flag = 1;
			return;
		}
		if ( flag != 0 )
			return;
	}
/*	while ( count >= 2 )
	{
		if ( right + h[k-1] > left+count*k && left+count*k+h[k-1] > right)
			div(left+count*k,right,sum,k-1,v[k-1]);
		else if ( right + h[k-1] == left+count*k )
		{
			flag = 1;
			return;
		}
		if ( flag != 0 )
			return;
		if ( left + h[k-1] > right+count*k && right+count*k+h[k-1] > left)
			div(left,right+count*k,sum,k-1,v[k-1]);
		else if ( left + h[k-1] == right+count*k )
		{
			flag = 1;
			return;
		}
		if ( flag != 0 )
			return;
		div(left+k,right+k,sum,k,count-2);
		if ( flag != 0 )
			return;
	}
	if ( count == 1 )
	{
		if ( right + v[k-1] > left+k && left+k+v[k-1] > right )
			div(left+k,right,sum,k-1,v[k-1]);
		else if (right + v[k-1] == left+k)
		{
			flag = 1;
			return;
		}
		if ( flag != 0 )
			return;
		if ( left + v[k-1] > right + k && right+k+v[k-1] > left )
			div(left,right+k,sum,k-1,v[k-1]);
		else if (left + v[k-1] == right + k )
		{
			flag = 1;
			return;
		}
		if ( flag != 0 )
			return;
	}*/
}
int main ()
{
	int i,j,sum,num;
	int tcase = 1;
	while ( scanf("%d %d %d %d %d %d",&v[1],&v[2],&v[3],&v[4],&v[5],&v[6]) )
	{
		l [0] = 1;
		a[0] = 0;
		v[0] = 0;
		num = v[1] + v[2] + v[3] + v[4] + v[5]+v[6];
		if ( num == 0 )
			break;
		printf("Collection #%d:\n",tcase);
		tcase++;
		sum = v[1]+2*v[2]+3*v[3]+4*v[4]+5*v[5]+6*v[6];
		if ( sum %2==1 )
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		sum /= 2;
		j = 1;
		for ( i = 0; i < v[6]; i++ )
			a[j++] = 6;
		for ( i = 0; i < v[5]; i++ )
			a[j++] = 5;
		for ( i = 0; i < v[4]; i++ )
			a[j++] = 4;
		for ( i = 0; i < v[3]; i++ )
			a[j++] = 3;
		for ( i = 0; i < v[2]; i++ )
			a[j++] = 2;
		for ( i = 0; i < v[1]; i++ )
			a[j++] = 1;
		for ( i = 1; i <= sum; i++ )
			l[i] = 0;
		h[1] = v[1];
		for ( i = 2; i <= 6; i++ )
			h[i] = h[i-1] + (i)*v[i];
		div(0,0,sum,6,v[6]);
		if ( flag == 1 )
			printf("Can be divided.\n");
		else
			printf("Can't be divided.\n");
		
		flag = 0;
		printf("\n");
	}
	return 0;
}

/*

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
*/