#include<iostream>
using namespace std;
int main ()
{
int n,x,i,j;
while ( cin>>n )
{
j = 0;
for ( i = 0; i < n; i++ )
{
cin>>x;
if ( x == 0 )
j++;
}
if ( (n+j) % 2 == 0 )
cout<<"No"<<endl;
else
cout<<"Yes"<<endl;
}
return 0;
}