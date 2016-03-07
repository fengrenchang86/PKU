#include<iostream.h>
#include<stdio.h>
int f(int ar[],int a, int b, int c )
{
	int *arr = new int[b+1];
	int i;
	int j;
	int t;
	for (t = 0, i = a; i <= b; i++,t++)
		arr[t] = ar[i];
	for ( i = 0; i < b-a; i++ )
		for ( j = i+1; j<=b-a; j++ )
		{
			if ( arr[i] > arr[j] )
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	return  arr[c];
}
void main ()
{
	int n;
	int m;
	scanf("%d",&n);
	scanf("%d",&m);
	int i;
	int a;
	int b;
	int c;
	int k;
	int *array = new int[n];
	for ( i = 0; i < n; i++ )
		scanf("%d",&array[i]);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		k = f(array,a-1,b-1,c-1);
		printf("%ld",k);
		cout<<endl;
	}
}