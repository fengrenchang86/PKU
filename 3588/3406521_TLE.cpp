#pragma warning (disable:4786)
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>
#include <map>
using namespace std;
struct ac1
{
	char name[30];
	bool operator()(const ac1&m1, const ac1&m2 )
	{
		if( strcmp(m1.name,m2.name) > 0 )
			return true;
		else
			return false;
	}
};
struct ac2
{
	char name[30];
	bool operator()(const ac2&m1, const ac2&m2 )
	{
		if( strcmp(m1.name,m2.name) < 0 )
			return true;
		else
			return false;
	}
};
map<string,int>ma;
priority_queue<ac1,vector<ac1>,ac1>que1;
priority_queue<ac2,vector<ac2>,ac2>que2;
int number,n,m,dir,size;
char task[100111][30];
int cmp ( const void*a, const void*b )
{
	return strcmp( (char *)a , (char *)b ); 
}
void init ()
{
	ma.clear();
	while ( !que1.empty() )
		que1.pop();
	while ( !que2.empty() )
		que2.pop();
	dir = 0;
	size = 0;
	number=0;
}
int gettop ()
{
	if ( dir == 0 )
	{
		ac1 t;
		while ( !que1.empty() )
		{
			t = que1.top();
			que1.pop();
			if ( ma[t.name] == 1 )
			{
				number++;
				ma[t.name] = 0;
				return 1;
			}
		}
	}
	else
	{
		ac2 t;
		while ( !que2.empty() )
		{
			t = que2.top();
			que2.pop();
			if ( ma[t.name] == 1 )
			{
				number++;
				ma[t.name] = 0;
				return 1;
			}
		}
	}
	return 0;
}
void run ( char *t, char *p )
{
	if ( strcmp(t,"New")==0 )
	{
		if ( number < n )
		{
			number++;
			ma[p] = 0;
		}
		else
		{
			ac1 a1;
			ac2 a2;
			strcpy(a1.name,p);
			strcpy(a2.name,p);
			que1.push(a1);
			que2.push(a2);
			ma[p] = 1;
		}
		strcpy(task[size],p);
		size++;
	}
	else if ( strcmp(t,"Sort")==0 )
	{
		if ( strcpy(p,"asc") == 0 )
			dir = 0;
		else
			dir = 1;
	}
	else if ( strcmp(t,"Pause")==0 )
	{
		if ( ma[p] == 0 )
		{
			ma[p] = 2;
			number--;
			while ( number < n )
				gettop();	
		}
		else if ( ma[p] == 1 )
		{
			ma[p] = 2;
		}
	}
	else if ( strcmp(t,"Continue")==0 )
	{
		if ( ma[p] == 2 )
		{
			if ( number < n )
			{
				ma[p] = 0;
				number++;
			}
			else
			{
				ma[p] = 1;
				ac1 a1;
				ac2 a2;
				strcpy(a1.name,p);
				strcpy(a2.name,p);
				que1.push(a1);
				que2.push(a2);
			}
		}
	}
	else if ( strcmp(t,"Finish")==0 )
	{
		if ( ma[p] == 0 )
		{
			number--;
			ma[p] = 3;
			while ( number < n )
				gettop();
		}
	}
}
int main ()
{
	int tcase,i,j;
	char t[200],p[200];
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		init();
		scanf("%d%d",&n,&m);
		for ( i = 0; i < m; i++ )
		{
			scanf("%s %s",t,p);
			run(t,p);
		}
		qsort(task,size,sizeof(task[0]),cmp);
		if ( dir == 0 )
		{
			for ( i = 0; i < size; i++ )
			{
				printf("%s ",task[i]);
				j = ma[task[i]];
				if ( j == 0 )
					printf("downloading\n");
				else if ( j == 1 )
					printf("waiting\n");
				else if ( j == 2 )
					printf("paused\n");
				else
					printf("finished\n");
			}
		}
		else
		{
			for ( i = size-1; i >= 0; i-- )
			{
				printf("%s ",task[i]);
				j = ma[task[i]];
				if ( j == 0 )
					printf("downloading\n");
				else if ( j == 1 )
					printf("waiting\n");
				else if ( j == 2 )
					printf("paused\n");
				else
					printf("finished\n");
			}
		}
		printf("\n");
	}
	return 0;
}