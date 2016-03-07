#include<iostream>
using namespace std;
int main ()
{
int n,x,i;
while ( cin>>n )
{
for ( i = 0; i < n; i++ )
cin>>x;
if ( n % 2 == 0 )
cout<<"No"<<endl;
else
cout<<"Yes"<<endl;
}
return 0;
}