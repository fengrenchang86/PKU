#include<iostream>
using namespace std;
const double pi = 3.1415927;
int main ()
{
	float d;
	int round,second;
	int c = 1;
	float ans;
	int a;
	while( scanf("%f %d %d",&d,&round,&second) && round != 0 )
	{
		printf("Trip #",c++);
		printf(": ");
		ans = pi*d/5280.0*round/12.0;
		a = ans * 1000;
		if ( a%10 >= 5 )
			a = a/10+1;
		else
			a = a/10;
		cout<<a/100<<'.'<<a%100<<" ";
		ans = ans/second*3600.0;
		a = ans * 1000;
		if ( a%10 >= 5 )
			a = a/10+1;
		else
			a = a/10;
		cout<<a/100<<'.'<<a%100<<endl;
	}
	return 1;
}
