#include <iostream.h>
struct stru_a
{
	int usetime;
	int problemsolve;
	int id;
	int t[50];
	int problem[50];
	int pt[50];
	stru_a(){
		usetime= 0;
		problemsolve = 0;
		for ( int i = 0; i < 50; i++ )
		{
			t[i] = 0;
			problem[i] = 0;
			pt[i] = 0;
		}
	}
}team[2000];
void swap ( stru_a &a, stru_a &b )
{
	int t;
	t = a.id;
	a.id = b.id;
	b.id = t;
	t = a.problemsolve;
	a.problemsolve = b.problemsolve;
	b.problemsolve = t;
	t = a.usetime;
	a.usetime = b.usetime;
	b.usetime = t;
}
void main ()
{
	int c;
	int n;
	int ci,ti,pi,ri;
	cin>>c>>n;
	int i;
	int j;
	for ( i = 0; i <= c; i++ )
		team[i].id = i;
	for ( i = 0; i < n; i++ )
	{
		cin>>ci>>pi>>ti>>ri;
		if ( ri == 0 && team[ci].problem[pi] == 0 )
			team[ci].t[pi] ++;
		if ( ri == 1 && team[ci].problem[pi] == 0 )
		{
			team[ci].problem[pi] = 1;
			team[ci].problemsolve++;
			team[ci].usetime += 1200*team[ci].t[pi];
			team[ci].pt[i] = ti;
		}
		else if ( ri == 1 && team[ci].problem[pi] == 1 )
		{
			if ( team[ci].pt[i] < ti )
			{
				team[ci].usetime -= team[ci].pt[i];
				team[ci].pt[i] = ti;
				team[ci].usetime += team[ci].pt[i];
			}
		}
//		if ( ri == 1 && team[ci].problem[pi] == 1 )
//		{

	}
	for ( i = 1; i <= c-1; i++ )
	{
		for ( j = i+1; j <= c; j++ )
		{
			if ( team[i].problemsolve < team[j].problemsolve )
				swap(team[i],team[j]);
		}
	}
	for ( i = 1; i <= c-1; i++ )
	{
		for ( j = i+1; j <= c; j++ )
		{
			if ( team[i].problemsolve == team[j].problemsolve )
				if ( team[i].usetime > team[j].usetime )
					swap(team[i],team[j]);
		}
	}
	for ( i = 1; i <= c-1; i++ )
		cout<<team[i].id<<" ";
	cout<<team[i].id<<endl;

}


/*
void main ()
{
	int ci,pi,ti,ri;
	int c,n;
	int i;
	int j =0;
	int k;
	cin>>c>>n;
	int count[5000][2];
	int a[5000][30];
	int *time = new int[c+5];
	for ( i = 0; i < c; i++ )
	{
		count[i][0] = 0;
		count[i][1] = i;
		time[i] = 0;
	}
	for ( i = 0; i < c; i++ )
		for ( j = 0; j < 30; j++ )
			a[i][j] = 0;
	for( i = 0; i < n; i++ )
	{
		cin>>ci>>pi>>ti>>ri;
		ci--;
		pi--;
		if ( a[ci][pi] <= 0 )
			a[ci][pi] -= 1200;
		if ( ri == 1 && a[ci][pi]<0 )
		{
			a[ci][pi]+=1200;
			a[ci][pi] *= -1;
			a[ci][pi] += ti;
			count[ci][0]++;
			time[ci] += a[ci][pi];
		}
	}
	
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( count[i][0] < count[j][0] )
			{
				k = count[i][0];
				count[i][0] = count[j][0];
				count[j][0] = k;
				k = count[i][1];
				count[i][1] = count[j][1];
				count[j][1] = k;
				k = time[i];
				time[i] = time[j];
				time[j] = k;
			}
		}
	}
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( count[i][0] == count[j][0] )
			{
				if ( time[i] > time[j] )
				{
					k = count[i][0];
					count[i][0] = count[j][0];
					count[j][0] = k;
					k = count[i][1];
					count[i][1] = count[j][1];
					count[j][1] = k;
					k = time[i];
					time[i] = time[j];
					time[j] = k;
				}
			}
		}
	}
	i = 0;
	if ( c != 1 )
	for ( i = 0; i < c-1; i++ )
		cout<<count[i][1]+1<<' ';
	cout<<count[i][1]+1;
	cout<<endl;
}
*/