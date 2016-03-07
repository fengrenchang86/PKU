#include <iostream.h>
int m1;
int m2;
int temp[4];
void main ()
{
	int re( int );
	int input;
	int c;
	int n;
	
	while ( cin>>input && input != -1 )
	{
		
		cout<<"N="<<input<<':'<<endl;
		c = 0;
		do
		{
			c++;
			n = re ( input );
			input = m1 - m2;
			if (( n != 4 || input == 0 ) && c==1 )
			{
				c = 0;
				break;
			}
			input = m1 - m2;
			cout<<m1<<"-"<<m2<<"="<<input<<endl;
		}while ( input != 0 && input !=6174 );
		if ( c > 1 )
			cout<<"Ok!! "<<c<<" times"<<endl;
		else if ( c== 1 )
			cout<<"Ok!! "<<c<<" time"<<endl;
		else 
			cout<<"No!!"<<endl;
	}
	
}

int re ( int in )
{
	int i;
	int j;
	int k;
	if ( in < 10 )
	{
		m1 = in;
		m2 = in;
		return 1;
	}
	else if ( in < 100 )
	{
		temp[0] = in - in/10*10;
		in /= 10;
		temp[1] = in - in/10 * 10;
		if ( temp[0] < temp[1] )
		{
			k = temp[0];
			temp[0] = temp[1];
			temp[1] = k;
		}
		m1 = temp[0]*10 + temp[1];
		m2 = temp[1]*10 + temp[0];
		return 2;
	}
	else if ( in < 1000 )
	{
		temp[0] = in - in/10*10;
		in /= 10;
		temp[1] = in - in/10*10;
		in /= 10;
		temp[2] = in - in/10*10;
		for ( i = 0; i < 2; i++ )
		{
			for ( j = i+1; j < 3; j++ )
			{
				if ( temp[i] < temp[j] )
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			}
		}
		m1 = temp[0]*100 + temp[1]*10 + temp[2];
		m2 = temp[2]*100 + temp[1]*10 + temp[0];
		return 3;
	}
	else
	{
		temp[0] = in- in/10*10;
		in /= 10;
		temp[1] = in - in/10*10;
		in /= 10;
		temp[2] = in - in/10*10;
		in /= 10;
		temp[3] = in - in/10 *10;
		for ( i = 0; i < 3; i++ )
		{
			for ( j = i+1; j <4; j++ )
			{
				if ( temp[i] < temp[j] )
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			}
		}
		m1 = temp[0]*1000 + temp[1]*100 + temp[2]*10 + temp[3];
		m2 = temp[3]*1000 + temp[2]*100 + temp[1]*10 + temp[0];
		return 4;
	}

}
