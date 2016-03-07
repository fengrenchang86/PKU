#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
int it,tcase,a,b;
cin>>tcase;
for (it=1; it<=tcase;it++)
{
cin>>a>>b;
printf("Scenario #%d:\n",it);
if ( a*b % 2 == 0 )
printf("%.2lf\n\n",a*b);
else
printf("%.2lf\n\n",a*b-1+sqrt(2));
}
return 0;
}