#include <iostream.h>
void main ()
{
	int h;
	int hh;
	int n;
	int i;
	char a[10];
	char b[10];
	char c[10];
	int list[20];
	cin>>n;
	for ( h = 0; h < n; h++ )
	{
		for ( i = 0; i < 12; i++ )
			list[i] = 0;
		for ( hh = 0; hh < 3; hh++ )
		{
			cin>>a>>b>>c;
			if ( c[0] == 'e' )
			{
				for ( i = 0; a[i] != NULL; i++ )
				{
					list[a[i]-'A'] = 1;
					list[b[i]-'A'] = 1;
				}
			}
			else if (c[0] == 'u' )
			{
				for ( i = 0; a[i] != NULL; i++ )
				{
					if ( list[a[i]-'A'] != 1 )
						list[a[i]-'A'] = -1;
					if ( list[b[i]-'A'] != 1 )
						list[b[i]-'A'] = 2;
				}

			}
			else
			{
				for ( i = 0; a[i] != NULL; i++ )
				{
					if ( list[a[i]-'A'] != 1 )
						list[a[i]-'A'] = 2;
					if ( list[b[i]-'A'] != 1 )
						list[b[i]-'A'] = -1;
				}
			}
		}
		for ( i = 0; ; i++ )
		{
			if ( list[i] == -1 )
			{
				cout<<char(i+'A')<<" is the counterfeit coin and it is heavy."<<endl;
				break;
			}
			if ( list[i] == 2 )
			{
				cout<<char(i+'A')<<" is the counterfeit coin and it is light."<<endl;
				break;
			}
		}
			
	}
}