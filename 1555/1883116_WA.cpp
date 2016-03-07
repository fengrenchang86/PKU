#include <iostream>
using namespace std;
int put(int t[])
{
	int i;
	for ( i = 0; i < 9; i++ )
		cin>>t[i];
	return 1;
}
int main ()
{
	int a[10];
	int i;
//	while ( put(a) )
	while ( scanf("%d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8])!=EOF )
	{
//		put(a);
		i = 0;
		while( a[i] == 0 && i < 9)
			i++;
		if ( i == 7 )
		{
			if ( a[i] == 1 )
				cout<<'x';
			else if ( a[i] == -1 )
				cout<<"-x";
			else
				cout<<a[i]<<'x';
		}
		else if ( i == 8 )
			cout<<a[i];
		else if ( i == 9 )
			cout<<0;
		else
		{
			if ( a[i] == 1 )
				cout<<"x^"<<8-i;
			else if ( a[i] == -1 )
				cout<<"-x^"<<8-i;
			else if ( a[i] > 0 )
				cout<<a[i]<<"x^"<<8-i;
			else
				cout<<a[i]<<"x^"<<8-i;
		}
		i++;
		for ( ; i < 7; i++ )
		{
			if ( a[i] == 0 )
				continue;
			if ( a[i] == 1 )
				cout<<" + "<<"x^"<<8-i;
			else if ( a[i] == -1 )
				cout<<" - "<<"x^"<<8-i;
			else if ( a[i] > 0 )
				cout<<" + "<<a[i]<<"x^"<<8-i;
			else
				cout<<" - "<<-1*a[i]<<"x^"<<8-i;
		}
		if ( i > 8 )
		{
			cout<<endl;
		//	continue;
			return 1;
		}
		if ( i == 7 )
		{
			if ( a[i] == 0 )
				;
			else if ( a[i] == 1 )
				cout<<" + x";
			else if ( a[i] == -1 )
				cout<<" - x";
			else if ( a[i] > 0 )
				cout<<" + "<<a[i]<<'x';
			else
				cout<<" - "<<-1*a[i]<<'x';
			i++;
		}
		if ( i == 8 )
		{
			if ( a[i] == 0 );
			else if ( a[i] == 1 )
				cout<<" + 1";
			else if ( a[i] == -1 )
				cout<<" - 1";
			else if ( a[i] > 0 )
				cout<<" + "<<a[i];
			else
				cout<<" - "<<-1*a[i];
		}
		cout<<endl;

	}

	return 1;
}