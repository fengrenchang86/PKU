#include<iostream>
using namespace std;
unsigned int i,x,y,n,k;
unsigned int gcd(unsigned int a,unsigned int b)
{
	if(a%b==0)
		return b;
	else{
		return gcd(b,a%b);
	}
}
void funtion1(unsigned int &a,unsigned int &b)
{
	unsigned int g=gcd(a,b);
	a/=g,b/=g;
}
unsigned int funtion2(unsigned int n,unsigned int k)
{
	unsigned int M,D;
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
unsigned int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==k&&n==0)
			break;
		unsigned int s=funtion2(n,k);
		printf("%d\n",s);
	}
	return 0;
} 