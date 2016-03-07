#include<iostream>
using namespace std;
int main ()
{
int n,x,i,j;
while ( cin>>n )
{
j = 0;
if ( n == 0 )
{cout<<"Yes"<<endl;
continue;
}
for ( i = 0; i < n; i++ )
{
cin>>x;
if ( x == 0 )
while(1);
if ( x != 1 )
j++;
}
if ( j % 2 == 0  )
cout<<"No"<<endl;
else
cout<<"Yes"<<endl;
}
return 0;
}