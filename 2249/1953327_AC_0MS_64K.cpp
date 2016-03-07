#include<iostream>
using namespace std;
_int64 i,x,y,n,k;
_int64 gcd(_int64 a,_int64 b)
{
	if(a%b==0)
		return b;
	else{
		return gcd(b,a%b);
	}
}
void funtion1(_int64 &a,_int64 &b)
{
	_int64 g=gcd(a,b);
	a/=g,b/=g;
}
_int64 funtion2(_int64 n,_int64 k)
{
	_int64 M,D;
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
_int64 main()
{
	char tt[100];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==k&&n==0)
			break;
		_int64 s=funtion2(n,k);
		_i64toa(s,tt,10);
		printf("%s\n",tt);
	}
	return 0;
} 