#include <iostream.h>
void main ()
{
	int a[22] = {4,5,8,10,21,32,51,170,292,512,910,1638,2978,5567,10922,20164,37449,69905,131072,246723,466033};
	int n;
	while ( cin>>n && n != 0 )
	{
		cout<<a[(n-1960)/10]<<endl;
	}
}