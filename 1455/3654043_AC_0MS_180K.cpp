#include<cstdio>
int main()
{
int T,m1,m2,n;
scanf("%d",&T);
while(T--)
{
scanf("%d",&n);
m1=n/2;
m2=n-n/2;
printf("%d\n",m1*(m1-1)/2+m2*(m2-1)/2);
}
return 0;
}