#include <iostream>
#include <iomanip>
using namespace std;
struct msg
{
	int number;
	int co;
	msg(){co=0;number= 0;}
}a[100020],b[100020];
void Merge(int low, int mid, int high)
{
	int h = low, i = low, j = mid+1,k;
	while ( h <= mid && j <= high )
	{
		if ( a[h].number <= a[j].number )
			b[i] = a[h++];
		else
			b[i] = a[j++];
		i++;
	}
	if ( h > mid )
		for ( k = j; k <= high; k++ )
			b[i++] = a[k];
	else 
		for ( k = h; k <= mid; k++ )
			b[i++] = a[k];
	for ( k = low; k <= high; k++ )
		a[k] = b[k];
}
void MergeSort ( int low, int high )
{
	if ( low < high )
	{
		int mid = (low+high)/2;
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		Merge(low,mid,high);
	}
}

//typedef int msg;
/*
int Qsort( msg t[], int start, int end,msg b[])
{
	int key;
	t[0]= t[start];
	b[0] = b[start];
	key = t[start];
	while ( start < end )
	{
		while ( start < end && t[end]>=key )
			end--;
		t[start] = t[end];
		b[start] = t[end];
		while ( start < end && t[start] <= key )
			start++;
		t[end] = t[start];
		b[end] = b[start];
	}
	t[start] = t[0];
	b[start] = b[0];
	return start;
//	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
//	int up = end;
//	int down = start;
*/
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
	return down;
}/*
void qs ( msg t[], int start, int end,msg b[] )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(t,start,end,b);
		qs ( t,start,mid-1,b);
		qs ( t,mid+1,end,b);
	}
}
*/

int list[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int pow[7]={1000000,100000,10000,1000,100,10,1};
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
//	msg *a = new msg[n+2];
//	msg *b = new msg[n+2];
//	msg *g = new msg[n+2];
	for ( i = 0; i < n+2; i++ )
		a[i].co = 0;
	for ( i = 0; i < n; i++ )
	{
		
		scanf("%s",put);
		m = 0;
		t = 0;
		for ( j = 0; put[j] != NULL; j++ )
		{
			if ( put[j] >= 'A' && put[j] < 'Z' )
				m += pow[t++]*list[put[j]-'A'];
			else if ( put[j] >= '0' && put[j] <= '9' )
				m += pow[t++]*(put[j]-'0');
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
	int h = 1;
	for ( i = 1; i <= n; i++ )
		if ( a[i].co > 1 )
			b[h++] = a[i];
	for ( i = 1; i < h; i++ )
		a[i] = b[i];
	h--;
	MergeSort(1,h);
	i = 1;
	m = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i].co > 1 )
		{
			printf("%03d-%04d %d\n",a[i].number/10000,a[i].number%10000,a[i].co);
			m++;
//		if ( a[i].co <= 1 )
//			continue;
//		cout<<setw(3)<<setfill('0')<<a[i].number/10000<<'-'<<setw(4)<<setfill('0')<<a[i].number%10000<<" "<<a[i].co<<endl;
		}
	}
	if ( m == 0 )
		cout<<"No duplicates."<<endl;
}
