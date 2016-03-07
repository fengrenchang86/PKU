#include<iostream>
#define N 260
using namespace std;

int main()
{
	int re[N];
	int i,j,carry;
	int n,d;
	while((cin>>n>>d)&&((n!=0)||(d!=0)))
	{
		if(d==0)
			cout<<1<<endl;
		else{
		re[0]=1;
		for(i=1;i<N;i++)
			re[i]=0;
		for(i=0;i<d;i++)
		{
			for(j=0;j<N;j++)
				re[j]=re[j]*n;
			for(j=0;j<N;j++)
				if(re[i]>=10)
				{
					carry=re[i]/10;
					re[i+1]=re[i+1]+carry;
					re[i]=re[i]-carry*10;
				}
		}
		for(i=N-1;i>=0;i--)
			if(re[i]!=0)
				break;
		for(j=i;j>=0;j--)
			cout<<re[j];
		cout<<endl;
		}
	}
	return 0;
} 