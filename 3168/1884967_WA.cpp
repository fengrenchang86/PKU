#include <iostream>
using namespace std;

struct msg 
{
	int x[2];
	int y[2];
};
int how ( msg a, msg b)
{
	if ( a.x[0] == b.x[0] || a.x[1] == b.x[0] )
	{
		if ( a.y[0]>=b.y[0]&&a.y[0]<=b.y[1] || a.y[1]>=b.y[0]&&a.y[1]<=b.y[1] )
			return 1;
	}
	if ( a.y[0] == b.y[1] || a.y[1] == b.y[0] )
		if ( a.x[0]>=b.x[0]&&a.x[0]<=b.x[1] || a.x[1] >=b.x[0]&&a.x[1]<=b.x[1] )
			return 1;
	return 0;
}
int main ()
{
	int n;
	int i;
	int j;
	scanf("%d",&n);
	int *a = new int[n];
	for ( i = 0; i < n; i++ )
		a[i] = 0;
	msg *t = new msg[n];
	for ( i = 0; i < n; i++)
		cin>>t[i].x[0]>>t[i].y[0]>>t[i].x[1]>>t[i].y[1];
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			if ( a[i] == a[j] == 1 )
				continue;
			if ( how ( t[i],t[j]) == 1 )
			{
				a[i] = 1;
				a[j] = 1;
			}
		}
	}
	j = 0;
	for ( i = 0; i < n; i++ )
		j+=a[i];
	cout<<n-j<<endl;
	return 1;
}