#include <iostream>
using namespace std;
struct ac
{
	int Size,Speed,MaxSpeed;
	bool Downloaded;
	double Rest;
}t[120];
int fenpei ( int n, double &Bandwidth )
{
	int i,c=0;
	double rest = 0.0,add;
	for ( i = 0; i < n; i++ )
		if ( t[i].Downloaded == false && t[i].Speed < t[i].MaxSpeed )
			c++;
	if ( c == 0 )
		return 0;
	add = (double)Bandwidth/(double)c;
	for ( i = 0; i < n; i++ )
	{
		if ( t[i].Downloaded == false && t[i].Speed < t[i].MaxSpeed )
		{
			t[i].Speed += add;
			if( t[i].Speed > t[i].MaxSpeed )
			{
				rest += t[i].MaxSpeed-t[i].Speed;
				t[i].Speed = t[i].MaxSpeed;
			}
		}
	}
	if ( rest != 0 )
		fenpei(n,rest);
	Bandwidth = rest;
	return c;
}
int main ()
{
	int tcase = 1;
	int Next[120];
	int end,finish;
	double min,time;
	int n,i;
	double Bandwidth;
	while ( scanf("%d",&n) && n!=0 )
	{
		scanf("%lf",&Bandwidth);
		time = 0.0;
		min = 1000000000.0;
		end = 0;
		finish = 0;
		Bandwidth = 0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&t[i].Size,&t[i].Speed,&t[i].MaxSpeed);
			t[i].Downloaded = false;
			t[i].Rest = (double)t[i].Size/(double)t[i].Speed;
		}
		printf("Case %d:\n",tcase);
		tcase++;
		while ( finish < n )
		{
			min = 1000000000;
			for ( i = 0; i < n; i++ )
			{
				if ( t[i].Rest < min && t[i].Downloaded == false)
				{
					end = 0;
					min = t[i].Rest;
					Next[end++] = i;
				}
				else if ( t[i].Rest == min && t[i].Downloaded == false)
					Next[end++] = i;
			}
			for ( i = 0; i < end; i++ )
			{
				Bandwidth+=t[Next[i]].Speed;
				t[Next[i]].Downloaded = true;
				finish++;
				printf("NO%d:%.3lfs\n",finish,time+min);
			}
			for ( i = 0; i < n; i++ )
				t[i].Size -= t[i].Speed*min;
			time+=min;
			fenpei(n,Bandwidth);
			for ( i = 0; i < n; i++ )
				if( t[i].Downloaded == false )
					t[i].Rest = (double)t[i].Size / (double)t[i].Speed;
		}
	}
	return 0;
}