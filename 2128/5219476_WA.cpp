#include <iostream>
using namespace std;
int a[51000];
int n;
void Input()
{
a[0] = 0;
int i;
for(i = 1; i <= n; i++)
scanf("%d", &a[i]);
}
void Solve()
{
if(n == 2 || n == 3)
{
printf("0\n");
return ;
}
int i,x;
int nMax = 2100000000;
for(i = 2; i <= n-2; i++)
{
if(a[i+1] + a[n]-a[i] < nMax)
{
nMax = a[i+1] + a[n] - a[i];
x = i;
}
}
printf("%d\n", nMax);
printf("%d 1 %d %d\n", x+1, n, x);
}
int main()
{
while(scanf("%d", &n) != EOF)
{
Input();
Solve();
}
return 0;
}