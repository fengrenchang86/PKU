#include<iostream>
using namespace std;


int main()
{
	int i,n,b[10],j;

	int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
	int value[1024];

	for(i=0;i<11;i++)
		b[i]=0;

	//compute the value
	for(i=0;i<1024;i++)
	{
		value[i]=0;
	}
	for(i=0;i<1024;i++)
	{
		for(j=0;j<11;j++)
			value[i]=value[i]+b[j]*a[j];
		b[0]++;
		for(j=0;j<11;j++)
			if(b[j]==2)
			{
				b[j]=0;
				b[j+1]=b[j+1]+1;
			}
	}
	while((cin>>n)&&(n>=0))
	{
		for(i=0;i<1024;i++)
		{
			if(value[i]>=n)
				break;
		}
		if(value[i]==n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
} 