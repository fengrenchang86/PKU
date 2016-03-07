#include <iostream>
using namespace std;
int main ()
{
	int tcase;
	int l,m;
	char ch[20];
	int restl,restr,d,dir,i,time;
	int left,right;
	cin>>tcase;
	while ( tcase )
	{
		cin>>l>>m;
		l*=100;
		dir = 0;
		restl = restr = l;
		time = 1;
		left = right = 0;
		for ( i = 0; i < m; i++ )
		{
			cin>>d>>ch;
			if ( ch[0] == 'l')
			{
				if ( restl - d >= 0 )
					restl-=d;
				else
				{
					left++;
					restl = l-d;
				}
			}
			else
			{
				if ( restr - d >= 0 )
					restr-=d;
				else
				{
					right++;
					restr = l-d;
				}
			}
		}
		if ( left == 0 && right ==0 )
			cout<<0<<endl;
		else if ( left == 0 )
			cout<<(right+1)*2<<endl;
		else if ( right == 0 )
			cout<<(left+1)*2-1<<endl;
		else
		{
			left++;
			right++;
		if ( left > right )
			cout<<left*2-1<<endl;
		else if ( left == right )
			cout<<left*2<<endl;
		else
			cout<<2*right<<endl;
		}
		tcase--;
	}
	return 0;
}