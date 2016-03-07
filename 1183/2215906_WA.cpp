#include <iostream>
using namespace std;
int main ()
{
	unsigned int a,i=1;
	cin>>a;
	while ( (a*a+1)%i!=0)
		i++;
	printf("%I64d\n",i+2*a+(a*a+1)/i);
	return 0;
}