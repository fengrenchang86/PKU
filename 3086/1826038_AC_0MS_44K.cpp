#include <iostream.h>
void main ( )
{
	int t ( int );
	int a[300];
	int k = 1;
	for ( k = 1; k < 300; k++ )
		a[k] = 0;
	int in;
	int i;
	cin>>in;
	a[0] = 3;
	for ( i = 1; i < 300; i++ )
	{
		a[i] = a[i-1] + (i+1)*t(i+2);
	}
	int *save = new int[in];
	for ( i = 0; i < in; i++ )
		cin>>save[i];
	for ( i = 0; i < in; i++ )
		cout<<i+1<<' '<<save[i]<<' '<<a[save[i]-1]<<endl;
		
}

int t ( int n )
{
	return n * (n + 1) / 2;
}