
#include <iostream>
#include <string.h>
using namespace std;

struct ac
{
	char name[35];
	int count;
	ac(){count=1;}
};
int Qsort( ac t[], int start, int end )
{
	int i;
	t[0] = t[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && strcmp(t[up].name,t[0].name) >=0 )
		{
			up--;
			continue;
		}
		if ( i == 0 && strcmp(t[up].name,t[0].name) < 0 )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && strcmp(t[down].name,t[0].name ) <= 0 )
		{
			down++;
			continue;
		}
		if ( i == 1 && strcmp(t[down].name,t[0].name ) > 0  )
		{
			t[up] = t[down];
			i = 0;
			up--;
		}
	}
	t[down] = t[0];
	return down;
}
void qs ( ac t[], int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(t,start,end);
		qs ( t,start,mid-1);
		qs ( t,mid+1,end);
	}
}

int main ()
{
	ac t[10001];
	int i,end=1;
	char input[35];
	int sum = 0;
	while( gets(input)!=NULL )
	{
	//	if ( input[0] == '0')
	//		break;
		sum++;
		for ( i = 1; i < end; i++ )
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
	qs(t,1,end-1);
	for ( i = 1; i < end; i++ )
	{
		printf("%s ",t[i].name);
		printf("%.4lf\n",100.0*t[i].count/sum);
	}
	return 0;
}
