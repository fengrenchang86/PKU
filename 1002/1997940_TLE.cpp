#include <iostream>
#include <iomanip>
using namespace std;
struct msg
{
	int number;
	int co;
	msg(){co=0;number= 0;}
};
int Qsort( msg t[], int start, int end )
{
	int i;
	t[0]= t[start];

	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
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
	return down;
}
void qs ( msg t[], int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(t,start,end);
		qs ( t,start,mid-1);
		qs ( t,mid+1,end);
	}
}


int list[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};
void main ()
{
	int n;
	char put[100];
	int i;
	int j;
	int t;
	int m;
	int c = 1;
	cin>>n;
	msg *a = new msg[n+1];
	for ( i = 0; i < n; i++ )
	{
		scanf("%s",put);
		m = 0;
		for ( j = 0; put[j] != NULL; j++ )
		{
			if ( put[j] >= '0' && put[j] <= '9' )
				m = m*10 + put[j] - '0';
			else if ( put[j] >= 'A' && put[j] <= 'Z' && put[j] != 'Q' )
				m = m*10 + list[put[j]-'A'];
			else 
				continue;
		}
		for ( j = 1; j < c; j++ )
		{
			if ( m == a[j].number )
			{
				a[j].co++;
				break;
			}
		}
		if ( j == c )
		{
			a[c].number = m;
			a[c].co++;
			c++;
		}
	}
	qs(a,1,c);
	i = 1;
	for ( i = 1; i <= c; i++ )
	{
		if ( a[i].co <= 1 )
			continue;
		cout<<setw(3)<<setfill('0')<<a[i].number/10000<<'-'<<setw(4)<<setfill('0')<<a[i].number%10000<<" "<<a[i].co<<endl;
		m++;
	}
	if ( i == 1 )
		cout<<"No duplicates. "<<endl;
}