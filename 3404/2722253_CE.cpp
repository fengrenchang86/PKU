#include <iostream>
using namespace std;
int main ()
{
int a[100];
int n,i,sum=0;
int min = 2000000000;
cin>>n;
for ( i = 0; i < n; i++ )
{
cin>>a[i];
if ( a[i] < min )
min = a[i];
sum+=a[i];
]
cout<<sum+(n-2)*min;
return 0;
}