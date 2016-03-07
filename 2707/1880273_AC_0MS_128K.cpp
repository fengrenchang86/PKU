#include <iostream>
using namespace std;
int main ()
{
	int a[4];
	int i;
	int c;
	int A,B,C,D;
	int rate1;
	int rate2;
	while (1 )
	{
		c = 0;
		for ( i = 0; i < 4;i++ )
		{
			cin>>a[i];
			if ( a[i] != 0 )
				c++;
		}
		if ( c==0 )
			break;
		A = a[0]>a[1]?a[0]:a[1];
		B = a[0]<=a[1]?a[0]:a[1];
		C = a[2] > a[3] ? a[2]:a[3];
		D = a[2] <= a[3] ? a[2]:a[3];
		rate1 = 100*C/A;
		rate2 = 100*D/B;
		if( rate1 < rate2 )
		{
			if ( rate1>100 )
				cout<<"100%"<<endl;
			else
				cout<<rate1<<"%"<<endl;
		}
		else
		{
			if ( rate2 > 100 )
				cout<<"100%"<<endl;
			else
				cout<<rate2<<"%"<<endl;
		}
	}
	return 1;
}