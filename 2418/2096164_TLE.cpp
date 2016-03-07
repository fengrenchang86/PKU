
#include <iostream>
#include <string.h>
using namespace std;
int a[10001];
struct ac
{
	char name[35];
	int count;
	ac(){count=1;}
};
int Qsort( ac t[], int start, int end )
{
	int i;
	a[0] = a[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && strcmp(t[a[up]].name,t[a[0]].name) >=0 )
		{
			up--;
			continue;
		}
		if ( i == 0 && strcmp(t[a[up]].name,t[a[0]].name) < 0 )
		{
			a[down] = a[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && strcmp(t[a[down]].name,t[a[0]].name ) <= 0 )
		{
			down++;
			continue;
		}
		if ( i == 1 && strcmp(t[a[down]].name,t[a[0]].name ) > 0  )
		{
			a[up] = a[down];
			i = 0;
			up--;
		}
	}
	a[down] = a[0];
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
	while( scanf("%[^\n]",input)!=EOF )
	{
		cin.ignore();
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
	for ( i = 0; i <= end; i++ )
		a[i] = i;
	qs(t,1,end-1);
	for ( i = 1; i < end; i++ )
	{
		printf("%s ",t[a[i]].name);
		printf("%.4lf\n",100.0*t[a[i]].count/sum);
	}
	return 0;
}
