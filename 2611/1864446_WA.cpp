#include <iostream.h>
char put[50];
int suc;

void sort ( int begin, int end )
{
	
	int po;
	int i;
	int j;
	int max = 0;
	for ( i = begin; i <= end; i++ )
	{
		if ( put[i] == '.' )
			continue;
		if ( put[i]-'0' > max )
		{
			max = put[i] - '0';
			po = i;
		}
	}
	if ( po == 0 )
		suc = 0;
	else 
		suc = 1;
	max = put[begin];
	put[begin] = put[po];
	put[po] = max;
	for ( i = begin+1; i <= end; i++ )
	{
		if (put[i] == '5' )
			put[i] = '2';
		else if (put[i] == '9' )
			put[i] = '6';
	}
	for ( i = begin+1; i < end; i++ )
	{
		if ( put[i] == '.' )
			continue;
		for ( j = i+1; j <= end; j++ )
		{
			if ( put[j] == '.' )
				continue;
			if ( put[i] > put[j] )
			{
				max = put[i];
				put[i] = put[j];
				put[j] = max;
			}
		}
	}
}

void main ()
{
	int i;
	int e;
	int t;
	int exit = 0;
	while ( exit == 0 )
	{
		cin>>put;
		suc = 0;
		if ( put[0] == '.' )
		{
			exit = 1;
			break;
		}
		for ( i = 0; put[i]!= NULL; )
			i++;
		e = i-1;
		if ( put[e] == '2' )
		{
			put[e] = '5';
			suc = 1;
		}
		else if ( put[e] == '6' )
		{
			put[e] = '9';
			suc = 1;
		}
		if ( suc != 1 )
		{
			for ( i = e - 1; i >= 0; i-- )
			{
				if ( put[i] == '.' )
					continue;
				if ( put[i+1] == '.' )
					t = 1;
				else
					t = 0;
				if ( put[i] < put[t+i+1] )
					break;
				if ( put[i] == '2' )
				{
					put[i] = '5' ;
					suc = 1;
				}
				else if ( put[i] == '6' )
				{
					put[i] = '9';
					suc = 1;
				}
			}
			if ( suc == 0 )
				sort(i,e);
		}// end if ( suc != 1 )
		if ( put[0] == '0' )
			suc = 0;
		if ( suc == 0 )
			cout<<"The price cannot be raised."<<endl;
		else
		{
			for ( i = 0; i <= e; i++ )
				cout<<put[i];
			cout<<endl;
		}
	}
}