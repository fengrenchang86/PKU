#include <iostream>
#include <string>
using namespace std;
char t[1200000];
char ans[1200000];
char v[1200000];
int len;
int f ( int x )
{
	int i,k=x*10;
	
	for ( i = 0; i < len; i++ )
	{
		k += t[i]-'0';
		v[i] = k/11+'0';
		k %= 11;
		k*=10;
	}
	v[i] = NULL;
	if ( k == 0 )
	{
		strcpy(ans,v);
		return 1;
	}
	else
		return 0;
}
int main ()
{
	int i,j,k=1;
	while ( scanf(" %s",&t) )
	{
		if ( t[0] == '0' && t[1] == NULL )
			break;
		len = strlen(t);
		j = 0;
		for ( i = 1; i <= 9; i++ )
			j+=f(i);
		if ( j == 1 )
			printf("%d. %s\n",k,ans);
		else
		{
			j = f(10);
			if ( j == 1 )
				printf("%d. %s\n",k,ans);
			else
				printf("%d. IMPOSSIBLE\n",k);
		}
		k++;
	}
	return 0;
}