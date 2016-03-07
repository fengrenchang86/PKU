#include<iostream>
#include<string>
using namespace std;
int **c;

int LCS2(string x,string y)
{
	int n=x.length();
	int m=y.length();
	string t;
	int i,j;
	//the length of x must small than y.
	if(n>m)
	{
		//swap x and y
		t=x;
		x=y;
		y=t;
		n=x.length();
		m=y.length();
	}
	c=new int *[2];
	for(i=0;i<2;i++)
		c[i]=new int [n+1];
	c[1][0]=0;
	for(i=0;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[j-1]==y[i-1])
				c[i%2][j]=c[(i+1)%2][j-1]+1;
			else
			{
				if(c[(i+1)%2][j]>c[i%2][j-1])
					c[i%2][j]=c[(i+1)%2][j];
				else
					c[i%2][j]=c[i%2][j-1];
			}
		}
	}
	return c[m%2][n];
}
int main()
{
	string x,y;
	int i;
	while(cin>>x>>y)
	{
		i=LCS2(x,y);
		cout<<i<<endl;
		delete c;
	}
	
	return 0;
}
