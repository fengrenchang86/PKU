#include <iostream>
using namespace std;
int use[120000];
int cash;
void updata ( int count, int value )
{
	int i,j,k;
	if ( use[cash] == 1 )
		return;
	for ( i = 0; i < cash; i++ )
	{
		if ( use[i] == 1 )
			use[i] = 2;
	}
	for ( i = 0; i < cash; i++ )
	{
		if ( use[i] != 2 )
			continue;
		k = 0;
		for ( j = value; i+j <= cash && k < count; j+=value,k++ )
		{
			if ( use[i+j] == 0 )
				use[i+j] = 1;
		}
	}
	for ( i = 0; i < cash; i++ )
		if ( use[i] == 2 )
			use[i] = 1;	
}
int main ()
{
	int i,n;
	int count,value;
	while ( scanf("%d%d",&cash,&n) != EOF )
	{
		memset(use,0,sizeof(use));
		use[0] = 1;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d",&count,&value);
			updata(count,value);
		}
		for ( i = cash; i >= 0; i-- )
		{
			if ( use[i] == 1 )
				break;
		}
		if ( i < 0 )
			i = 0;
		cout<<i<<endl;
	}
	return 0;
}