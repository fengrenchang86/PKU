#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int up,down;
	double ans;
}v,a[6600000],b[6600000];
int cmp ( const void*a, const void*b )
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	return c->ans<d->ans?1:-1;
}
void Merge(int low, int mid, int high )
{
	int h = low, i = low, j = mid+1,k;
	while ( h <= mid && j <= high )
	{
		if ( a[h].ans <= a[j].ans )
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
void MergeSort ( int low, int high)
{
	if ( low < high )
	{
		int mid = (low+high)/2;
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		Merge(low,mid,high);
	}
}
int gcd(int m,int n)
{
	int p;
	while(n)
	{
		p=m%n;
		m=n;
		n=p;
	}
	return m;
}
int main ()
{
	int n,c,i,j,CurrentSize = 0;
	int t;
	scanf("%d%d",&n,&c);
	v.up = 0;
	v.down = 1;
	v.ans = 0.0;
	a[CurrentSize++] = v;
	v.up = 1;
	v.down = 1;
	v.ans = 1.0;
	a[CurrentSize++] = v;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j < i; j++ )
		{
			v.up = j;
			v.down = i;
			v.ans = double(j)/double(i);
			if ( gcd(i,j) == 1 )
				a[CurrentSize++] = v;
		}
	}
	MergeSort(0,CurrentSize-1);
	t = CurrentSize;
	for ( i = 0; i < c; i++ )
	{
 		scanf("%d",&j);
		if ( j > t )
		{
			cout<<"No Solution"<<endl;
			continue;
		}
		printf("%d/%d\n",b[j-1].up,b[j-1].down);
	}
	return 0;
}