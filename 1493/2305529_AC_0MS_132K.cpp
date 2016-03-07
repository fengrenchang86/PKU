#include <iostream>
using namespace std;
int main ()
{
	int a[20];
	char ch[30];
	int n,i,j,k;
	int sum;
	while ( cin>>n && n!=0 )
	{
		cin.ignore();
		sum = 0;
		for ( i = 0; i < n; i++ )
		{
			k = 0;
			cin.getline(ch,100,'\n');
			for ( j = 0; ch[j] != NULL; j++ )
			{
				if ( ch[j] == 'X' )
					k++;
			}
			a[i] = k;
			sum += a[i];
		}
		k = 0;
		for ( i = 0; i < n; i++ )
		{
			if ( a[i] > k )
				k = a[i];
		}
		cout<<n*k-sum<<endl;
	}
	return 0;
}