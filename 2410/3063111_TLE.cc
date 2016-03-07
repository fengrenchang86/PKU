#include <iostream>
#include <string>
using namespace std;
char mem[40][10];
int f ( char *t )
{
	int k = 0;
	int i,j=1;
	for ( i = 7; i >= 3; i-- )
	{
		if ( t[i] == '1' )
			k += j;
		j *= 2;
	}
	return k;
}
void type ( char *t, char *ans )
{
	int i;
	for ( i = 0; i < 3; i++ )
		ans[i] = t[i];
	ans[i] = NULL;
}
void itoc ( int x, char *t )
{
	int i,j, k = 128;
	for ( i = 0; i < 8; i++ )
	{
		j = x/k;
		x %= k;
		k/=2;
		t[i] = j+'0';
	}
	t[i] = NULL;
}
int ctoi ( char *t )
{
	int i,j=0,k = 128;
	for ( i = 0; i < 8; i++ )
	{
		if ( t[i] == '1' )
			j += k;
		k /= 2;
	}
	return j;
}
int pc,accu;
int main ()
{
	int i,j;
	char oper[10],temp[10];
	while ( cin>>mem[0] )
	{
		pc = accu = 0;
		for ( i = 1; i < 32; i++ )
			cin>>mem[i];
		while ( 1 )
		{
			type(mem[pc],oper);
			if ( strcmp(oper,"111")==0 )
				break;
			else if ( strcmp(oper,"000") == 0 )
			{
				i = f( mem[pc] );
				itoc(accu,temp);
				strcpy(mem[i],temp);
				pc++;
			}
			else if ( strcmp(oper,"001") == 0 )
			{
				i = f(mem[pc]);
				accu = ctoi(mem[i]);
				pc++;
			}
			else if ( strcmp(oper,"010") == 0 && accu == 0 )
			{
				pc = f(mem[pc]);
			}
			else if ( strcmp(oper,"100") == 0 )
			{
				accu += 255;
				pc++;
			}
			else if ( strcmp(oper,"101") == 0 )
			{
				accu++;
				pc++;
			}
			else if ( strcmp(oper,"110") == 0 )
			{
				pc = f(mem[pc]);
			}
			accu %= 256;
			pc %= 32;
		}
		itoc(accu,temp);
		cout<<temp<<endl;
	}
	return 0;
}