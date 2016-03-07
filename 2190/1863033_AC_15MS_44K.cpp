#include <iostream.h>
void main ()
{
	char put[10];
	int sum ;
	int i;
	int j;
	while ( cin>>put )
	{
		sum = 0;
	for ( i = 0; i < 9; i++ )
	{
		if ( put[i] >= '0' && put[i] <= '9' )
			sum += (put[i] - '0')*(10-i);
		else
			j = i;
	}
	if ( put[i] >= '0' && put[i] <= '9' )
		sum += (put[i] - '0');
	else if ( put[i] == 'X' )
		sum += 10;
	else
		j = i;
	i = 0;
	while ( (sum+i*(10-j))%11 != 0 )
	{
		i++;
		if ( i == 11 )
			break;
	}
	if ( i == 11 || i == 10&&j!=9 )
		cout<<"-1"<<endl;
	else if ( i == 10 )
		cout<<"X"<<endl;
	else
		cout<<i<<endl;
	}
}