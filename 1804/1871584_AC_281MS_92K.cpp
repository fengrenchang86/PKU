#include <iostream>
using namespace std;

int main ()
{
	int testcase;
	int c = 0;
	int i;
	int j;
	int k;
	int num;
	int n[1000];
	cin>>testcase;
	for ( i = 0; i < testcase; i++ )
	{
		cin>>num;
		c = 0;
		for ( j = 0; j < num; j++ )
			cin>>n[j];
		for ( j = 1; j < num; j++ )
		{
			for ( k = 0; k < j; k++ )
				if ( n[k] > n[j] )
					c++;
		}
		cout<<"Scenario #"<<i+1<<":"<<endl;
		cout<<c<<endl;
		cout<<endl;
	}
	return 1;
}