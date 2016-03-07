#include <iostream>
using namespace std;
int main ()
{
	int tcase;
	int l,m;
	char ch[20];
	int rest,d,dir,i,time;
	cin>>tcase;
	while ( tcase )
	{
		cin>>l>>m;
		l*=100;
		dir = 0;
		rest = l;
		time = 1;
		for ( i = 0; i < m; i++ )
		{
			cin>>d>>ch;
			if ( ch[0] == 'l' && dir == 0 || ch[0] == 'r' && dir == 1 )
			{
				if ( rest - d >= 0 )
					rest-=d;
				else
				{
					time+=2;
					rest = l-d;
				}
			}
			else
			{
				time++;
				rest = l-d;
			}
			if ( ch[0] == 'l' )
				dir = 0;
			else
				dir = 1;
		}
		cout<<time<<endl;
		tcase--;
	}
	return 0;
}