#include<iostream>
using namespace std;
int main()
{
	int p,e,i,d,j;
	int year=1;
	j=0;
	while(cin>>p>>e>>i>>d)
	{
		if(p == -1 && e == -1 && i == -1 && d == -1)
			break;
	    int t;
		t=(p+e+abs(p-e))/2;
		t=(t+i+abs(t-i))/2;
		year=t+1;
		year = 1;
        while(year++ <= 21252)
		{
			 if((year-p)%23==0 && (year-e)%28==0 && (year-i)%33==0)
				 break;
		}
		int y;
		y=year-d;
		if ( y <= 0 )
			y += 21252;
		else if(y>21252)
			y=y-21252;
		cout<<"Case "<<++j<<" the next triple peak occurs in "<<y<<" days."<<endl;
	}
	return 1;
} 
