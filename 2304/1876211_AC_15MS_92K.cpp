#include <iostream>
using namespace std;
int main ()
{
	int a,b,c,d;
	int sum;
	while ( cin>>a>>b>>c>>d && !(a==0&&b==0&&c==0&&d==0) )
	{
		sum = 1080;
		sum += ((a+40-b)%40+(c+40-b)%40+(c+40-d)%40)*9;
		cout<<sum<<endl;
	}
	return 1;
}