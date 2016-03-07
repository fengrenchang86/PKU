#include <iostream>
using namespace std; 
int main ()
{
	int n,hour,f[30],d[30],t[30],fish[30],go[30],ans[30],remain[30];
	int i,j,time,number,max;
	int k;//how many times can John fish? the answer is k times;
	while ( scanf("%d",&n) && n!=0 )
	{
		go[0] = 0;
		scanf("%d",&hour);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&remain[i]);
			f[i] = remain[i];
			fish[i] = 0;
			ans[i] = -1;
		}
		for ( i = 0; i < n; i++ )
			scanf("%d",&d[i]);
		for ( i = 0; i < n-1; i++ )
		{
			scanf("%d",&t[i]);
			t[i] *= 5;
			go[i+1] = go[i] + t[i];
		}
		number = 0;
		k = hour*12;
		while ( k > 0 )
		{
			if ( f[0] > 0 )
				number += f[0];
			else
				break;
			f[0] -= d[0];
			k--;
			fish[0]++;
		}
		fish[0] += k;
		max = number;
		ans[0] = fish[0];
		ans[1] = -1;
		fish[0] = 0;
		for ( i = 1; i < n; i++ )//assume John go to one,two,....n lakes to fish
		{
			time = hour*60-go[i];//how many time(min) remain
			k = time/5;
			number = 0;
			for ( j = 0; j <= i; j++ )
				f[j] = remain[j];
			while ( k > 0 )
			{
				time = 0;
				for ( j = 0; j <= i; j++ )
				{
					if ( f[j] > f[time] )
						time = j;
				}
				if ( f[time]<= 0 )
					break;
				number += f[time];
				f[time] -= d[time];
				fish[time]++;
				k--;
			}
			j = 0;
			while ( fish[j] == 0 && j < i)
				j++;
			fish[j] += k;
			if ( number > max )
			{
				max = number;
				for ( j = 0; j <= i; j++ )
					ans[j] = fish[j];
				ans[j] = -1;
			}
			else if ( number == max )
			{
				j = 0;
				while ( j<=i-1 )
				{
					if ( ans[j] > fish[j] )
					{
						j = -1;
						break;
					}
					else if ( ans[j] < fish[j] )
					{
						j = -2;
						break;
					}
					j++;
				}
				if ( j == -2 )
				{
					for ( j = 0; j <= i; j++ )
						ans[j] = fish[j];
					ans[j] = -1;
				}
			}
			for ( j = 0; j < n; j++ )
				fish[j] = 0;
		}
		for ( i = 0; i < n-1; i++ )
			if ( ans[i] == -1 )
				cout<<0<<", ";
			else
				cout<<ans[i]*5<<", ";
		if ( ans[i] == -1 )
			cout<<0;
		else
			cout<<ans[i]*5;
		cout<<endl;
		printf("Number of fish expected: ");
		cout<<max<<endl;
		printf("\n");
	}
	return 0;
}