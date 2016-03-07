#include<iostream>
#include<string>
using namespace std;

int main()
{
	unsigned int a[102]={0};
	int i,j;
	bool flag=0;
	char ch[102];
			
	while(cin.getline(ch,102)&&strcmp(ch,"0"))
	{
		j=0;
		for(i=0;ch[i]!=NULL;i++)
		{
			if((ch[i]>='0')&&(ch[i]<='9'))
				j++;
		}
		for(i=0;ch[i]!=NULL;i++)
		{
			if(j==0)
				break;
			a[i]=a[i]+ch[j-1]-'0';
			j--;
		}
		for(i=0;i<ch[i]!=NULL;i++)
		{
			if(a[i]>=10)
			{
				a[i]=a[i]-10;
				a[i+1]=a[i+1]+1;
			}
		}
		
	}


	for(i=101;i>=0;i--)
	{
		if(a[i]!=0)
			break;
		
	}
	if(i==-1)
		cout<<"0\n";
	else
	{
		for(int j=i;j>-1;j--)
			cout<<a[j];
		cout<<endl;
	}
	
	return 0;
} 