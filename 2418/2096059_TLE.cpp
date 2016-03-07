
#include <stdlib.h>
#include <iostream>
using namespace std;

struct ac
{
	char name[35];
	int count;
	ac(){count=1;}
};

int cmp(const void*a, const void*b)
{
	return strcmp( (*(ac*)a).name , (*(ac*)b).name ); 
}

int main ()
{
	ac t[10001];
	int i,end=0;
	char input[35];
	int sum = 0;
	while( cin.getline(input,40,'\n') )
	{
		sum++;
		for ( i = 0; i < end; i++ )
			if ( strcmp(input,t[i].name) == 0 )
				break;
		if ( i < end )
			t[i].count++;
		else
		{
			strcpy(t[i].name,input);
			end++;
		}
	}
	qsort(t,end,sizeof(t[0]),cmp);
	for ( i = 0; i < end; i++ )
	{
		printf("%s ",t[i].name);
		printf("%.4lf\n",100.0*t[i].count/sum);
	}
	return 0;
}
