#include <iostream.h>
#include <iomanip.h>
int list[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};
void main ()
{
	int n;
	char put[1000];
	int i;
	int j;
	int t;
	int m;
	int c = 0;
	int a[100000][2];
	cin>>n;
	for ( i = 0; i <= n; i++ )
	{
		a[i][0] = 0;
		a[i][1] = 0;
	}
	for ( i = 0; i < n; i++ )
	{
		cin>>put;
		m = 0;
		for ( j = 0; put[j] != NULL; j++ )
		{
			if ( put[j] >= '0' && put[j] <= '9' )
				t = put[j] - '0';
			else if ( put[j] >= 'A' && put[j] < 'z' && put[j] != 'Q' )
				t = list[put[j]-'A'];
			else 
				continue;
			m = m*10 + t;
		}
		for ( j = 0; j < c; j++ )
		{
			if ( m == a[j][0] )
			{
				a[j][1]++;
				break;
			}
		}
		if ( j == c )
		{
			a[c][0] = m;
			a[c][1]++;
			c++;
		}
	}
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( a[i][0] > a[j][0] )
			{
				m = a[i][0];
				a[i][0] = a[j][0];
				a[j][0] = m;
				m = a[i][1];
				a[i][1] = a[j][1];
				a[j][1] = m;
			}
		}
	}
	t = 0;
	for ( i = 0; i < c; i++ )
	{
		if ( a[i][1] > 1 )
		{
			cout<<setw(3)<<setfill('0')<<a[i][0]/10000<<'-'<<setw(4)<<setfill('0')<<a[i][0] - a[i][0]/10000*10000;
			cout<<" "<<a[i][1]<<endl;
			t++;
		}
	}
	if ( t == 0 )
		cout<<"No duplicates."<<endl;
}