/*
#include <iostream>
#include <math.h>
using namespace std;
void SmallHeapInsert ( int a[], int MaxSize, int& CurrentSize, int x )
{
	if ( x > 2000000000 )
		return;
//	if ( CurrentSize == MaxSize )
	{
//		printf("No memory\n");
//		return;
	}
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2] > x )
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else
			break;
	}
	a[i] = x;
	CurrentSize++;
}

void SmallDel ( int sort[], int a[], int& CurrentSize, int& Len )
{
	CurrentSize--;
	sort[Len++] = a[1];
	int item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i] > a[i+1] )
			i++;
		if ( item <= a[i] )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
}

int main ()
{
	int key;
	int a[60000],sort[60000];
	int list[5] = { 2,3,5,7,0 };
	int v[5] = { 1, 0 ,0,0,0 };
	int i,j;
	double x;
	int CurrentSize = 1,Len = 1;
	while ( list[4] == 0 )
	{
		x = pow(list[0],v[0])*pow(list[1],v[1])*pow(list[2],v[2])*pow(list[3],v[3]);
		SmallHeapInsert(a,60000,CurrentSize,x);
		v[0]++;
		i = 1;
		while ( x > 2000000000 )
		{
			v[i]++;
			j = i-1;
			while ( j>=0 )
				v[j--] = 0;
			i++;
			x = pow(list[0],v[0])*pow(list[1],v[1])*pow(list[2],v[2])*pow(list[3],v[3]);
		}		
	}
	SmallDel(sort,a,CurrentSize,Len);
	while ( scanf("%d",&key) && key != 0 )
	{
		printf("%d number is%d\n",key,sort[key]);
	}
	return 1;
}
*/
#include<iostream>
#define N 260
using namespace std;

int main()
{
	int re[N];
	int i,j,carry;
	int n,d;
	while((cin>>n>>d)&&((n!=0)||(d!=0)))
	{
		if(d==0)
			cout<<1<<endl;
		else if ( n == 0 )
			cout<<0<<endl;
		else{
		re[0]=1;
		for(i=1;i<N;i++)
			re[i]=0;
		for(i=0;i<d;i++)
		{
			for(j=0;j<N;j++)
				re[j]=re[j]*n;
			for(j=0;j<N;j++)
				if(re[j]>=10)
				{
					carry=re[j]/10;
					re[j+1]=re[j+1]+carry;
					re[j]=re[j]-carry*10;
				}
		}
		for(i=N-1;i>=0;i--)
			if(re[i]!=0)
				break;
		for(j=i;j>=0;j--)
			cout<<re[j];
		cout<<endl;
		}
	}
	return 0;
} 