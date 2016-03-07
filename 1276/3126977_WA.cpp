#include <iostream>
using namespace std;
bool use[120000];
int cash;
void updata ( int count, int value )
{
	int i,j,k;
	for ( i = 0; i < cash; i++ )
	{
		if ( use[i] == false )
			continue;
		k = 0;
		for ( j = value; i+j <= cash && k < count; j+=value,k++ )
			use[i+j] = true;
	}
}
int main ()
{
	int i,n;
	int count,value;
	while ( scanf("%d%d",&cash,&n) != EOF )
	{
		memset(use,false,sizeof(use));
		use[0] = true;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d",&count,&value);
			updata(count,value);
		}
		for ( i = cash; i >= 0; i-- )
		{
			if ( use[i] == true )
				break;
		}
		if ( i < 0 )
			i = 0;
		cout<<i<<endl;
	}
	return 0;
}