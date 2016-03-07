#include<iostream>
using namespace std;
int i,x,y,n,k;
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else{
		return gcd(b,a%b);
	}
}
void funtion1(int &a,int &b)
{
	int g=gcd(a,b);
	a/=g,b/=g;
}
int funtion2(int n,int k)
{
	int M,D;
	x=1,y=1;
	if(2*k>n)
		k=n-k;
	for(i=1;i<=k;i++)
	{
		M=n-k+i,D=i;
		funtion1(M,D);
		funtion1(M,y);
		funtion1(x,D);
		x*=M,y*=D;
	}
	return x/y;
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==k&&n==0)
			break;
		int s=funtion2(n,k);
		printf("%d\n",s);
	}
	return 0;
} 