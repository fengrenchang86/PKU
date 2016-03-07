#include <iostream>
using namespace std;
char list[30];
int find[30];
void f ( char *a )
{
	if ( a[0] == 0 )
		return ;
	int i;
	int min = 30;
	int pos;
	for ( i = 0; a[i] != NULL; i++ )
	{
		if ( find[a[i]-'A'] < min )
		{
			min = find[a[i]-'A'];
			pos = i;
		}
	}
	char b[30],c[30];
	for ( i = 0; i < pos; i++ )
		b[i] = a[i];
	b[i] = NULL;
	int j;
	i = 0;
	for ( j = pos+1; a[j] != NULL; j++,i++ )
		c[i] = a[j];
	c[i] = NULL;
	f(b);
	f(c);
	printf("%c",a[pos]);
}
int main ()
{
	char a[30];
	int i;
	while ( scanf("%s %s",list,a)!=EOF )
	{
		for ( i = 0; list[i] != NULL; i++ )
			find[list[i]-'A'] = i;
		f(a);
		printf("\n");
	}
	return 1;
}