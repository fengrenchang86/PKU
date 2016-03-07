#include <iostream>
using namespace std;
int main ()
{
char a[20][30];
int i,j=1,n;
while ( cin>>n && n!= 0 )
{
  for ( i = 0; i < n; i++ )
    cin>>a[i];
  cout<<"SET "<<j<<endl;
  j++;
  for ( i = 0; i < n; i+=2 )
    printf("%s\n",a[i]);
  if ( n % 2 == 0 )
    i = n-1;
  else
     i = n-2;
while ( i >= 0 )
{
printf("%s\n",a[i]);
i-=2;
}
}
 return 0;
}