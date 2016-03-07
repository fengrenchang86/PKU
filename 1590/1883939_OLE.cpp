#include <iostream>
using namespace std;
int main ()
{
	char a[30];
	short LIST[100] = {0};
	LIST['A'] = 'A';
	LIST['E'] = '3';
	LIST['I'] = 'I';
	LIST['H'] = 'H';
	LIST['J'] = 'L';
	LIST['L'] = 'J';
	LIST['M'] = 'M';
	LIST['O'] = '0';
	LIST['S'] = '2';
	LIST['T'] = 'T';
	LIST['U'] = 'U';
	LIST['V'] = 'V';
	LIST['W'] = 'W';
	LIST['X'] = 'X';
	LIST['Y'] = 'Y';
	LIST['Z'] = '5';
	LIST['1'] = '1';
	LIST['2'] = 'S';
	LIST['3'] = 'E';
	LIST['5'] = 'Z';
	LIST['8'] = '8';
	int c;
	int k;
	int i;
	int len;
	bool mirr;
	bool str;
	short t[30][30] = {0};
	while ( scanf("%s",a) )
	{
		len = strlen(a);
		c = 0;
		k = 0;
		mirr = 0;
		str = 0;
		for ( i = 0; i < len/2+1; i++ )
		{
			if ( a[i] != a[len-1-i] )
			{
				k+=2;
				mirr = 1;
				if ( LIST[a[i]] != int(a[len-1-i]) )
				{
					c=1;
					break;
				}
				else
				{
					str = 1;
				}
			}
			else
			{
				if ( LIST[a[i]] != 0 )
					k+=2;
			}
		}
		for ( i = 0; i < len; i++ )
			cout<<a[i];
		cout<<" -- ";
		if ( c == 1 )
			cout<<"is not a palindrome." <<endl;
		else
		{
			if ( mirr == 0 && k < len-1 )
				cout<<"is a regular palindrome."<<endl;
			else if ( mirr == 1 )
				cout<<"is a mirrored string."<<endl;
			else 
				cout<<"is a mirrored palindrome."<<endl;
		}
	}
	return 1;
}