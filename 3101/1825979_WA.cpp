#include <iostream.h>
void main ( )
{
	int N;
	cin>>N;
	int *T = new int[N];
	int *t = new int[N];
	int i;
	int max = 0;
	int fengmu = 0;
	int pos = 0;
	bool ok;
	for ( i = 0; i < N; i++ )
	{
		cin>>T[i];
		if ( T[i] > max )
			max = T[i];
	}
	for ( i = max; ; i+= max )
	{
		ok = true;
		for ( int j = 1; j < N; j++ )
		{
			if ( i % j != 0 )
			{
				ok = false;
				break;
			}
		}
		if ( ok == true )
			break;
	}
	fengmu = i;
	max = 0;
	for ( i = 0; i < N; i++ )
	{
		t[i] = fengmu / T[i];
		if ( t[i] > max )
		{
			max = t[i];
			pos = i;
		}
	}
	t[pos] = t[0];
	t[0] = max;
	int min = max;
	if ( fengmu % 2 == 0 )
	{
		fengmu = fengmu / 2;
		for ( i = 1; i < N; i++ )
		{
			t[i] = t[0] - t[i];
			if ( t[i] < min )
				min = t[i];
		}
	}
	else
	{
		for ( i = 1; i < N; i++ )
		{
			t[i] = t[0] - t[i];
			t[i] *= 2;
			if ( t[i] < min )
				min = t[i];
		}
	}
	while ( min > 0 )
	{
		for ( i = 1; i < N; i++ )
		{
			ok = true;
			if ( t[i] % min != 0 )
			{
				ok = false;
				break;
			}
		}
		if ( ok == true ) 
			break;
		min--;
	}
	cout<<fengmu<<" "<<min<<endl;
				
}