#include<iostream>
using namespace std;


int main()
{
	int i,n,b[12],j;

	unsigned int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
	unsigned int value[1025]={0};

	for(i=0;i<10;i++)
		b[i]=0;

	//compute the value
	for(i=0;i<1025;i++)
	{
		value[i]=0;
	}
	b[0] = 1;
	for(i=0;b[9] < 2;i++)	//for(i=0;i<1024;i++)
	{
		for(j=0;j<10;j++)
		{
			if ( b[j] == 1 )
			value[i]=value[i]+a[j];	//value[i]=value[i]+b[j]*a[j];
		}
		b[0]++;
		for(j=0;j<10;j++)
			if(b[j]==2)
			{
				b[j]=0;
				b[j+1]=b[j+1]+1;
			}
			else break;
	}
	while((cin>>n)&&(n>=0))
	{
		for(i=0;i<j;i++)
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