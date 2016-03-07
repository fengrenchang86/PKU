/*
6
(A-B + C) - (A+(B - C)) - (C-(D- E) )
  ((A)-( (B)))
A-(B+C)
(( (A)+(((B)))-(A-B-C))-(D-C) )
(((B) ) )
*/
#include <iostream>
using namespace std;
int Left[1000];
int Right[1000];
int stack[1000];
char ch[1000];
void init ()
{
	gets(ch);
	int type=0;
	int i,j,front=-1;
	for ( i = 0; i < 1000; i++ )
		Left[i] = Right[i] = -1;
	for ( i = 0; ch[i] != 0; i++ )
	{
		if ( ch[i] == '(' )
			stack[++front] = i;
		else if ( ch[i] == ')' )
		{
			Left[i] = stack[front];
			Right[stack[front]] = i;
			front--;
		}
	}
/*	for ( i = 0; ch[i] != 0; i++ )
		printf("%d: %c\n",i,ch[i]);
	printf("\n");
	for ( i = 0; ch[i] != 0; i++ )
	{
		if ( ch[i] == '(' )
			printf("%d\n",Right[i]);
		else if ( ch[i] == ')' )
			printf("%d\n",Left[i]);
	}*/
	for ( i = 0; ch[i] != 0; i++ )
	{
		if ( ch[i] == '(' )
		{
			if ( type == 0 )
			{
				ch[i] = ' ';
				ch[Right[i]] = ' ';
			}
			else
				type = 0;
		}
		else if ( ch[i] == '+' )
			type = 0;
		else if ( ch[i] == '-' )
			type = 1;
	}
	j = 0;
	for ( i = 0; ch[i] != 0; i++ )
	{
		if ( ch[i] != ' ' )
			ch[j++] = ch[i];
	}
	ch[j] = 0;
	for ( i = 0; ch[i] != 0; i++ )
	{
		if ( ch[i] == '(' && ch[i+2] == ')' )
			ch[i] = ch[i+2] = ' ';
		if ( ch[i] != ' ' )
			printf("%c",ch[i]);
	}
	printf("\n");
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	getchar();
	while ( tc-- )
	{
		init();
	}
	return 0;
}