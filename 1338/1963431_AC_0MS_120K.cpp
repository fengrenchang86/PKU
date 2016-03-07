
#include <iostream>
#include <math.h>
using namespace std;
void SmallHeapInsert ( unsigned int a[], int MaxSize, int& CurrentSize, int x )
{
	if ( x < 0 )
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

void SmallDel ( unsigned int sort[], unsigned int a[], int& CurrentSize, int& Len )
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
	unsigned int a[6000],sort[6000];
	int list[5] = { 2,3,5,0,0 };
	int v[5] = { 1, 0 ,0,0,0 };
	int i,j;
	double x;
	int CurrentSize = 1,Len = 2;
	sort[1] = 1;
	while ( v[3] == 0 )
	{
		x = pow(list[0],v[0])*pow(list[1],v[1])*pow(list[2],v[2])*pow(list[3],v[3]);
		SmallHeapInsert(a,6000,CurrentSize,x);
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
	j = CurrentSize;
	for ( i = 0; i <= j; i++ )
		SmallDel(sort,a,CurrentSize,Len);
	while ( scanf("%d",&key) && key != 0 )
	{/*
		if ( key%100 < 20 && key%100 > 10 )
			printf("The %dth humble number is %d.\n",key,sort[key]);
		else
		{
			if ( key % 10 == 1 )
				printf("The %dst humble number is %d.\n",key,sort[key]);
			else if ( key % 10 == 2 )
				printf("The %dnd humble number is %d.\n",key,sort[key]);
			else if ( key % 10 == 3 )
				printf("The %drd humble number is %d.\n",key,sort[key]);
			else
				printf("The %dth humble number is %d.\n",key,sort[key]);
		}*/
		printf("%d\n",sort[key]);
	}
	return 1;
}
