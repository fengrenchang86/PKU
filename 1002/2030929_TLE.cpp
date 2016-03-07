#include <iostream>
#include <string>
using namespace std;
const int max = 100100;
int v[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
char list[max][10];
int c[max]={0};
int t[max];
int q[max];
char ch[100];
char name[10];
int Qsort( int start, int end)
{
	int key;
	t[0]= t[start];
	key = t[start];
	while ( start < end )
	{
		while ( start < end && q[t[end]] > q[key] )
			end--;
		t[start] = t[end];
		while ( start < end && q[t[start]] < q[key] )
			start++;
		t[end] = t[start];
	}
	t[start] = t[0];
	return start;
//	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
//	int up = end;
//	int down = start;

/*	while ( up != down )
	{
		if ( i == 0 && t[up].number >= t[0].number )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[up].number < t[0].number )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[down].number <= t[0].number )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[down].number > t[0].number )
		{
			t[up] = t[down];
			i = 0;
			up--;
		}
	}
	t[down] = t[0];
	return down;*/
}
void qs ( int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(start,end);
		qs ( start,mid-1);
		qs (mid+1,end);
	}
}


int main ()
{
	int n;
	cin>>n;
	int i,j,k;
	int end = 0;
	for ( i = 0; i < n; i++ )
	{
		scanf("%s",ch);
		k = 0;
		for ( j = 0; ch[j] != NULL; j++ )
		{
			if ( ch[j]>='A' && ch[j] < 'Z' && ch[j] != 'Q' )
				k = k*10+(v[ch[j]-'A']);
			else if ( ch[j] >= '0' && ch[j] <= '9' )
				k = k*10 + (ch[j] - '0');	
	/*		if ( ch[j] >= 'A' && ch[j] < 'Z' && ch[j] != 'Q' )
				name[k++] = v[ch[j]-'A']+'0';
			else if ( ch[j] >= '0' && ch[j] <= '9' )
				name[k++] = ch[j];*/
		}
		for ( j = 0; j < end; j++ )
		{
			if ( q[j] == k )
			{
				c[j]++;
				break;
			}
		}
		if ( j == end )
		{
			q[end] = k;
			end++;
		}
	}
	j = 1;
	for ( i = 0; i < end; i++ )
	{
		if ( c[i] >= 1 )
			t[j++] = i;
	}
	if ( j == 1 )
	{
		printf("No duplicates.\n");
		return 1;
	}
	qs(1,j-1);
	for ( i = 1; i < j; i++ )
	{
//		printf("%d:  ",q[t[i]]);
		printf("%03d-%04d",q[t[i]]/10000,q[t[i]]%10000);
//		printf("%s  %d\n",list[t[i]],c[t[i]]+1);
		printf(" %d\n",c[t[i]]+1);
	}
	return 1;
}