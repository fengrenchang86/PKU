#include <iostream.h>
void main ()
{
  int n;
  cin>>n;
  int *a = new int[n];
  int i;
  int c,k,m,t;
  for ( i = 0; i < n; i++ )
  {
     cin>>a[i];
     c = 0;     
     for ( k = 1; k <= a[i]/2; k++ )
     {
         for ( m = 1; ; m++ )
	 {
 	     t = (2*k+m)*(m+1);
	     if ( a[i]*2 == t )
	     {
		c++;
		break;
	     }
	     else if ( a[i]*2 < t )
		break;
         }
     }
     cout<<i+1<<" "<<c<<endl;
         
  }
}
  