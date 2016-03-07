#include <iostream.h>
void main ( )
{

	int f ( int );
	int t ( int );
	int i = 0;
	int in;
	int j;
	int k;
	int num;
	int sum;
	cin>>num;
	for ( j = 0; j < num; j++ )
	{
		sum = 0;
		cin>>in;
		for ( i = 1; ; i++ )
		{
			sum += t ( i );
			if ( sum >= in )
				break;
		}
		if ( sum == in )
		{
			cout<< i - i/10*10<<endl;
		}
		else
		{
			sum -= t ( i );
			for ( j = 1; ;j++ )
			{
				sum += f ( j );
				if ( sum >= in )
					break;
			}
			if ( sum == in )
				cout<< j - j/10*10<<endl;
			else
			{
				if ( sum - in == 1 )	// 10
				{
					k = j - j / 100 * 100;
					k = k / 10;
					cout<<k<<endl;
				}
				else if ( sum - in == 2 )
				{
					k = j - j / 1000 * 1000;
					k = k / 100;
					cout<<k<<endl;
				}
				else if ( sum - in == 3 )
				{
					k = j - j / 10000 * 10000;
					k = k / 1000;
					cout<<k<<endl;
				}
				else if ( sum - in == 4 )
				{
					k = j - j / 100000 * 100000;
					k = k / 10000;
					cout<<k<<endl;
				}
				else if ( sum - in == 4 )
				{
					k = j - j / 1000000 * 1000000;
					k = k / 100000;
					cout<<k<<endl;
				}
				else if ( sum - in == 5 )
				{
					k = j - j / 10000000 * 10000000;
					k = k / 1000000;
					cout<<k<<endl;
				}
				else if ( sum - in == 5 )
				{
					k = j - j / 100000000 * 100000000;
					k = k / 10000000;
					cout<<k<<endl;
				}
				else
				{
					k = j - j / 1000000000 * 1000000000;
					k = k / 100000000;
					cout<<k<<endl;
				}
			}
		}

	}

}

int f ( int i )			//整型数字i的位数
{
	int c = 1;
	int j = i;
	j = j / 10;
	while ( j != 0 )
	{
		c++;
		j = j / 10;
	}
	return c;
}

int t ( int i )				//第i行字符数
{
	int sum = i;
	int c = 0;
	if ( i < 10 )
		return sum;
	if ( i >= 10 && i < 100 )
	{
		c = i - 9;
		return sum + c;
	}
	else if ( i >= 100 && i < 1000 )
	{
		sum += 90;
		c = i - 99;
		return sum + c;
	}
	else if ( i >= 1000 && i < 10000 )
	{
		sum += 990;
		c = i - 999;
		return sum + c;
	}
	else if ( i >= 10000 && i < 100000 )
	{
		sum += 9990;
		c = i - 9999;
		return sum + c;
	}
	else if ( i >= 100000 && i < 1000000 )
	{
		sum += 99990;
		c = i - 99999;
		return sum + c;
	}
	else if ( i >= 1000000 && i < 10000000 )
	{
		sum += 999990;
		c = i - 999999;
		return sum + c;
	}
	else if ( i >= 10000000 && i < 100000000 )
	{
		sum += 9999990;
		c = i - 9999999;
		return sum + c;
	}
	else if ( i >= 100000000 && i < 1000000000 )
	{
		sum += 99999990;
		c = i - 99999999;
		return sum + c;
	}
	else
	{
		sum += 999999990;
		c = i - 999999999;
		return sum + c;
	}
}