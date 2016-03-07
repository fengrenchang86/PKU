#include <iostream>
using namespace std;
int main ()
{
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if ( a <= 168 )
cout<<"CRASH "<<a<<endl;
else if ( b <= 168 )
cout<<"CRASH "<<b<<endl;
else if ( c <= 168 )
cout<<"CRASH "<<c<<endl;
else
cout<<"NO CRASH"<<endl;
return 0;
}