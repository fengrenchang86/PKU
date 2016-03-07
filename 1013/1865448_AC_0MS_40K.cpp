#include <iostream.h>
void main ()
{
	int max;
	int min;
	int h;
	int hh;
	int n;
	int i;
	char a[20];
	char b[20];
	char c[20];
	int list[20];
	int po1;
	int po2;
	cin>>n;
	for ( h = 0; h < n; h++ )
	{
		for ( i = 0; i < 20; i++ )
			list[i] = 0;
		for ( hh = 0; hh < 3; hh++ )
		{
			cin>>a>>b>>c;
			if ( c[0] == 'e' )
			{
				for ( i = 0; a[i] != NULL; i++ )
				{
					list[a[i]-'A'] = 100;
					list[b[i]-'A'] = 100;
				}
			}
			else if (c[0] == 'u' )
			{
				for ( i = 0; a[i] != NULL; i++ )
				{
					if ( list[a[i]-'A'] != 100 )
						list[a[i]-'A'] --;
					if ( list[b[i]-'A'] != 100 )
						list[b[i]-'A'] ++;
				}

			}
			else
			{
				for ( i = 0; a[i] != NULL; i++ )
				{
					if ( list[a[i]-'A'] != 100 )
						list[a[i]-'A'] ++;
					if ( list[b[i]-'A'] != 100 )
						list[b[i]-'A'] --;
				}
			}
		}
		max = 0;
		min = 0;
		po1 = 0;
		po2 = 0;
		for ( i = 0; i < 20 ; i++ )
		{
			if ( list[i] > max && list[i] != 100 )
			{
				max = list[i];
				po1 = i;
			}
			if ( list[i] < min )
			{
				min = list[i];
				po2 = i;
			}
		}
		min *= -1;
		if ( max > min )
			cout<<char(po1+'A')<<" is the counterfeit coin and it is light."<<endl;
		else
			cout<<char(po2+'A')<<" is the counterfeit coin and it is heavy."<<endl;
/*
		for ( i = 0; i< 12; i++ )
		{
			if ( list[i] < 0 )
			{
				if ( list[i] < list[po1] || list[po1] == 10 )
					po1 = i;
			}
			if ( list[i] > 0 &&list[i] != 10 )
			{
				if ( list[i] > list[po2] || list[po2] == 10 )
					po2 = i;
			}
		}
		if ( po1*(-1) > po2 )
			cout<<char(po1+'A')<<" is the counterfeit coin and it is heavy."<<endl;
		else if ( po1*(-1) < po2 )
			cout<<char(po2+'A')<<" is the counterfeit coin and it is light."<<endl;
*/		
	}
}