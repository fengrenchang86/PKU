#include <iostream>
using namespace std;
struct ac
{
	int car;
	int time;
	bool left,ok;
}car[10010];
int main ()
{
	int tcase,n,t,m,i,j,load;
	char ch[100];
	scanf("%d",&tcase);
	bool Carleft = true;
	int time;
	while ( tcase-- )
	{
		Carleft = true;
		time = 0;
		load = 0;
		scanf("%d%d%d",&n,&t,&m);
		for ( i = 0; i < m; i++ )
		{
			scanf("%d",&car[i].car);
			car[i].ok = false;
			scanf("%s",&ch);
			if (ch[0] == 'l' )
				car[i].left = true;
			else
				car[i].left = false;
			if ( i == 0 )
			{
				if ( Carleft == car[0].left )
					time = car[0].car;
				else
				{
					time = car[0].car+t;
					Carleft = car[0].left;
				}
			}
			if ( Carleft == car[i].left )
			{
				if ( load < n && time >= car[i].car )
				{
					load++;
				}
				else
				{
					time += t;
					j = i-1;
					while ( j >= 0 && car[j].ok == false )
					{
						car[j].time = time;
						car[j].ok = true;
						j--;
					}
					time += t;
					load = 1;
				}
			}
			else
			{
				time += t;
				j = i-1;
				while ( j >= 0 && car[j].ok == false )
				{
					car[j].time = time;
					car[j].ok = true;
					j--;
				}
				if ( Carleft == true )
					Carleft = false;
				else
					Carleft = true;
				load = 1;
			}
		}
		time += t;
		j = i-1;
		while ( j >= 0 && car[j].ok == false )
		{
			car[j].time = time;
			car[j].ok = true;
			j--;
		}
		for ( i = 0; i < m; i++ )
			cout<<car[i].time<<endl;
		if ( tcase != 0 )
			cout<<endl;
	}
	return 0;
}