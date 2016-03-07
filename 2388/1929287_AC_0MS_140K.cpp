
#include <iostream>
//#include <stdlib.h> //随机数函数在里面
//#include <time.h> //随机数种子----时间
using namespace std;
int Qsort( int t[], int start, int end )
{
	int i;
	t[0] = t[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && t[up] >= t[0] )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[up] < t[0] )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[down] <= t[0] )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[down] > t[0] )
		{
			t[up] = t[down];
			i = 0;
			up--;
		}
	}
	t[down] = t[0];
	return down;
}
void qs ( int t[], int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(t,start,end);
		qs ( t,start,mid-1);
		qs ( t,mid+1,end);
	}
}


int main ()
{
	int n;
	scanf("%d",&n);
	int *a = new int[n+3];
	int i;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	qs(a,1,n);
	printf("%d\n",a[(n+1)/2]);
	return 1;
}
/*
void main ()
{
	int i;
	int j = 1;
	int k = 0;
	int N;
	int N_a;
	int N_b;
	int a[10000];
	while (	cin>>N>>N_a>>N_b && N!= 0 )
	{
		srand((unsigned)time(NULL)); 
		for ( i = 1; i < N+1; i++ )
			a[i] = rand()%(N_b-N_a+1)+N_a;
	//	for ( i = 1; i < N+1; i++ )
	//		cout<<a[i]<<" ";
		cout<<"finish making"<<endl;
		cout<<endl;
		cout<<" sorting ......... "<<endl;

		for ( i = 1; i < N; i++ )			//普通排序
		{
			for ( j = i+1; j < N+1; j++ )
			{
				if ( a[i] > a[j] )
				{
					k = a[i];
					a[i] = a[j];
					a[j] = k;
				}
			}
		}

		qs ( a,1,N);
	//	for ( i = 1; i < N+1; i++ )
	//		cout<<a[i]<<" ";
		cout<<endl;
		cout<<" finished sorting " <<endl;
	}
}
*/