#include <iostream>
using namespace std;
void SmallHeapInsert ( int a[], int& CurrentSize, int x )
{
	if ( x%100>=60)
		x+=40;
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
int SmallDel ( int a[], int& CurrentSize )
{
	CurrentSize--;
	int t = a[1];
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
	return t;
}
int f ( int n )
{
	if ( n%100>=60)
		n+=40;
	return n;
}
int main ()
{
	int a[120];
	int b[120];
	int c[120];
	int A,B,C,i;
	int CurrentA, CurrentB, CurrentC;
	int nextA,nextB,nextC;
	int sum;
	char ch[20];
	int p,time;
	while ( cin>>A>>B>>C )
	{
		if ( A==0&&B==0&&C==0 )
			break;
		CurrentA = CurrentB = CurrentC = 1;
		sum = 0;
		for ( i = 0; i < A; i++ )
			SmallHeapInsert ( a, CurrentA, 800 );
		nextA = SmallDel(a,CurrentA);
		for ( i = 0; i < B; i++ )
			SmallHeapInsert ( b, CurrentB, 800 );
		nextB = SmallDel(b,CurrentB);
		for ( i = 0; i < C; i++ )
			SmallHeapInsert ( c, CurrentC, 800 );
		nextC = SmallDel(c,CurrentC);
		while ( cin>>ch && ch[0] != '#' )
		{
			i = 0;
			time = 0;
			while ( ch[i] != NULL )
			{
				if ( ch[i] >= '0' && ch[i] <= '9' )
				{
					time *= 10;
					time += ch[i]-'0';
				}
				i++;
			}
			if ( time % 100 >= 60 )
				time += 40;
			cin>>p;
			if ( p <= 2 )
			{
				if ( time >= nextA )
				{
					SmallHeapInsert ( a, CurrentA, time+30 );
					nextA = SmallDel(a,CurrentA);
					sum += p;
				}
				else if ( nextA <= f(time+30) )
				{
					SmallHeapInsert ( a, CurrentA, nextA+30);
					nextA = SmallDel(a,CurrentA);
					sum += p;
				}
			}
			else if ( p <= 4 )
			{
				if ( time >= nextB )
				{
					SmallHeapInsert ( b, CurrentB, time+30 );
					nextB = SmallDel(b,CurrentB);
					sum += p;
				}
				else if ( nextB <= f(time+30) )
				{
					SmallHeapInsert ( b, CurrentB, nextB+30);
					nextB = SmallDel(b,CurrentB);
					sum += p;
				}
			}
			else
			{
				if ( time >= nextC )
				{
					SmallHeapInsert ( c, CurrentC, time+30 );
					nextC = SmallDel(c,CurrentC);
					sum += p;
				}
				else if ( nextC <=f(time+ 30) )
				{
					SmallHeapInsert ( c, CurrentC, nextC+30);
					nextC = SmallDel(c,CurrentC);
					sum += p;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}