#include <iostream>
#include <fstream>
using namespace std;
const int max = 100100;
int a[max];
int y;
void BigHeapInsert (int& CurrentSize, int x )
{
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2] < x )
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
void BigDel ( int& CurrentSize )
{
	CurrentSize--;
	int x = a[1];
	int item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i] < a[i+1] )
			i++;
		if ( item >= a[i] )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
	BigHeapInsert(CurrentSize,x-y);
}
int main ()
{
	int CurrentSize = 1;
	int day = 0;
//	fstream fin("file.in");	
	int n,i;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		cin>>y;
		BigHeapInsert(CurrentSize,y);
	}
	cin>>y;
	while ( a[1]-day > 0 )
	{
		BigDel(CurrentSize);
		day++;
	}
	cout<<day<<endl;
	return 0;
}