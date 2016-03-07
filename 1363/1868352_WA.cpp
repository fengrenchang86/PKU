#include <iostream.h>
int stack[10000];
int a[10000];
int b[10000];
int front;
int point;



void chu ( )
{
	int i;
	for ( i = 0; i < 1000; i++ )
		a[i] = i+1;
}
void push ( int ia, int ib )
{
	int i;
	for ( i = ia; i <= ib; i++ )
	{
		stack[front++] = a[i];
	}
}
int pop ( )
{
	return front--;
}

void main ()
{
	int n;
	int i;
	int su;
	int j=0;
	while ( cin>>n && n!= 0 )
	{
		while ( 1 )
		{
			chu ( );
			su = 1;
			front = -1;
			point = 0;
			j = 0;
			cin>>b[0];
			if ( b[0] == 0 )
				break;
			for ( i = 1; i < n; i++ )
				cin>>b[i];
			for ( i = 0; i < n; i++ )
			{
				if ( b[i] < a[point] && stack[front-1] != b[i] )
				{
					su = 0;
					break;
				}
				else if ( b[i] == a[point] )
				{
					point++;
					continue;
				}
				else if ( front != -1 )
				{
					if ( stack[front-1] == b[i] )
					{
						pop ( );
						continue;
					}
					else
						;
				}
				if ( b[i] > j )
				{
					push ( point,b[i]-2 );
					point = b[i];
					if ( b[i] > j )
						j = b[i];
				}
				else 
				{
					su = 0;
					break;
				}
			}
			if ( su == 0 )
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}cout<<endl;
	}
	
}