#include <iostream.h>
#include <math.h>
void main ()
{
  int n;
  cin>>n;
  int *a = new int[n];
  int i;
  int c;
  int k;
  int t1,t2;
  for ( i = 0; i < n; i++ )
  {
     cin>>a[i];
     c = 0;     
     for ( k = 1; k <= a[i]/2; k++ )
     {
   	t1 = (1-2*k+sqrt((2*k-1)*(2*k-1)+8*a[i]))/2;
   	t2 = (1-2*k-sqrt((2*k-1)*(2*k-1)+8*a[i]))/2;
        if ( (2*k+t1-1)*t1 == 2*a[i] )
           c++;
        if ( (2*k+t2-1)*t2 == 2*a[i] )
           c++;
     }
     cout<<i+1<<" "<<c<<endl;
         
  }
}
  