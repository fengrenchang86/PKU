#include <iostream>
using namespace std;
int main ()
{
	char ch[1200];
	int tcase,i;
	int point,word,dig;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase --;
		cin>>ch;
		point = -1;
		word = 0;
		dig = 0;
		for ( i = 0; ch[i] != NULL; i++ )
		{
			if ( !(ch[i]>='0'&&ch[i]<='9') && !(ch[i]=='.'||ch[i]=='e'||ch[i]=='E'||ch[i]=='-'||ch[i]=='+'))
			{
				printf("ILLEGAL\n");
				break;
			}
			if ( dig == 1 )
			{
				if ( ch[i] >= '0' && ch[i] <= '9' )
				{
					dig = 0;
					if ( word == -1 )
						word = 0;
					if ( point == -1 )
						point = 0;
				}
				else
				{
					printf("ILLEGAL\n");
					break;
				}
			}
			else if ( dig == -1 && ch[i] >= '0' && ch[i] <= '9' )
			{
				printf("ILLEGAL\n");
				break;
			}
			else if ( dig == 0 && ch[i] >= '0' && ch[i] <= '9' )
			{
				if ( word == -1 )
					word = 0;
				if ( point == -1 )
					point = 0;
			}
			else if ( point < 0 && ch[i] == '.' )
			{
				printf("ILLEGAL\n");
				break;
			}
			else if ( ch[i] == '.' )
			{
				point = -2;
				if (!( ch[i+1] >= '0' && ch[i+1] <= '9' ))
				{
					printf("ILLEGAL\n");
					break;
				}
				dig = 0;
				i++;
			}
			else if ( word < 0 && (ch[i] == 'e' || ch[i] == 'E' ))
			{
				printf("ILLEGAL\n");
				break;
			}
			else if ( ch[i] == 'e' || ch[i] == 'E' )
			{
				if ( ch[i+1] != '+' && ch[i+1] != '-' && !(ch[i+1]>='0'&&ch[i+1]<='9'))
				{
					printf("ILLEGAL\n");
					break;
				}
				i++;
				if ( (ch[i] == '+' || ch[i] == '-' ) && ch[i+1] == NULL )
				{
					printf("ILLEGAL\n");
					break;
				}
				word = -2;
				point = -2;
				dig = 1;
			}
		}
		if ( ch[i] == NULL )
			printf("LEGAL\n");

	}
	return 0;
}