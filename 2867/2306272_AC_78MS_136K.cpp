#include <iostream>
#include <fstream>
using namespace std;
int a[1010][2];
int main ()
{
	int n,r,i,t,j,key;
	int tc = 1;
//	fstream cin("in.txt");
	while ( cin>>n && n!=0 )
	{
		cin>>r;
		for ( i = 0; i < r; i++ )
			cin>>a[i][0]>>a[i][1];
		cout<<"Genome "<<tc<<endl;
		tc++;
		cin>>t;
		for ( i = 0; i < t; i++ )
		{
			cin>>key;
			for ( j = 0; j < r; j++ )
			{
				if( key >= a[j][0] && key <= a[j][1] )
					key = a[j][0]+a[j][1]-key;
			}
			cout<<key<<endl;
		}
	}
	return 0;
}