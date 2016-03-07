#include <iostream>
using namespace std;
struct ac
{
	bool ok;
	bool port;//left
	int pre;
	ac(){ok=false;}
}a[101][10020];
void output ( int i ,int j )
{
	if ( i >= 0 )
	{
		output(i-1,a[i][j].pre);
		if ( a[i][j].port == true )
			cout<<"port"<<endl;
		else
			cout<<"starboard"<<endl;
	}
}
int main ()
{
	int t[120];
	int sum[120];
	int i=0,j=0,len,n;
	bool flag;
	scanf("%d",&len);
	len*=100;
	while ( scanf("%d",&t[i]) && t[i] != 0 )
	{
		j+=t[i];
		sum[i] = j;
		i++;
	}
	n = i;
	a[0][0].ok = true;
	a[0][0].port = false;
	a[0][t[0]].ok =true;
	a[0][t[0]].port = true;
	for ( i = 1; i < n; i++ )
	{
		for ( j = 0; j <= len; j++ )
		{
			if ( sum[i]-j > len )
				continue;
			if ( a[i-1][j].ok == true && sum[i]-j <= len )
			{
				a[i][j].ok = true;
				a[i][j].pre = j;
				a[i][j].port = false;
			}
			else if ( j >= t[i] && a[i-1][j-t[i]].ok == true )
			{
				a[i][j].ok = true;
				a[i][j].pre = j-t[i];
				a[i][j].port = true;
			}
		}
	}
	flag = false;
	for ( i = n-1; i >= 0; i-- )
	{
		for ( j = 0; j <= len ; j++ )
		{
			if ( sum[i]-j > len )
				continue; 
			if ( a[i][j].ok == true )
			{
				flag = true;
				break;
			}
		}
		if ( flag == true )
			break;
	}
	cout<<i+1<<endl;
	output(i,j);
	return 0;
}