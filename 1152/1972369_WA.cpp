	#include <iostream>
	using namespace std;
	int main ()
	{
		char a[330000];
		int i,min;
		while ( scanf("%s",a)!=EOF )
		{
			min = 2;
			for ( i = 0; a[i] != NULL; i++ )
			{
				if ( a[i] >= '0' && a[i] <= '9' )
				{
					if ( a[i] - '0' + 1 > min )
						min = a[i]-'0'+1;
				}
				else if ( a[i] >= 'A' && a[i] <= 'Z' )
				{
					if ( a[i] - 'A' + 11 > min )
						min = a[i]-'A'+11;
				}
				else 
				{
					if ( a[i] - 'a' + 37 > min )
						min = a[i]-'a'+37;
				}
			}
			if ( min < 2 )
				min = 2;
			printf("%d\n",min);
		}
		return 1;
	}