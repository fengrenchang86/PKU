#include <iostream>
using namespace std;
const int max = 80000;
_int64 a[max*2];
_int64 sort[max];
void SmallHeapInsert ( int& CurrentSize, _int64 x )
{
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
_int64 SmallDel ( int& CurrentSize, int& Len )
{
	CurrentSize--;
	_int64 t = a[1];
	sort[Len++] = a[1];
	_int64 item = a[CurrentSize];
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
	return t;
}
int main ()
{
	int CurrentSize = 1, Len = 1;
	int i;
	_int64 t,p=0;
	for ( i = 1; i <= 10; i++ )
		SmallHeapInsert ( CurrentSize, i );
	while ( CurrentSize >= 1 )
	{
		t = SmallDel(CurrentSize, Len );
		while ( t == p )
		{
			Len--;
			t = SmallDel(CurrentSize, Len );
		}
		for ( i = 2; i <= 9 ; i++ )
		{
			if ( t*i > 1000000000000000000 )
				break;
			SmallHeapInsert(CurrentSize, i*t);
		}
		p = t;
	}
//	for ( i = 1; i <= Len; i++ )
//		printf("%I64d\n",sort[i]);
	scanf("%d",&Len);
	while ( Len )
	{
		scanf("%d",&i);
		printf("%I64d\n",sort[i]);
		Len--;
	}
	return 0;
}