#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int begin;
	int end;
	int stud;
	int pc;
	bool ok;
	ac(){ok==false;}
}a[1010];
int cmp( const void *a , const void *b ) 
{ 
    struct ac *c = (ac *)a; 
    struct ac *d = (ac *)b; 
    if(c->stud != d->stud) return c->stud - d->stud; 
    else return c->begin - d->begin; 
} 
int main ()
{
	int m,n,r,i,q,j,k;
	int time,pc,stud,s;
	int b,e;
	while ( scanf("%d%d",&n,&m) && !(m==0&&n==0) )
	{
		scanf("%d",&r);
		for ( i = 0; i <= m; i++ )
			student[i] = 0;
		j = 1;
		a[0].stud=-1;
		for ( i = 1; i <= r; i++ )
		{
			scanf("%d%d%d%d",&time,&pc,&stud,&s);
			if ( s == 1 )
			{
				a[j].begin = time;
				a[j].pc = pc;
				a[j].stud = stud;
				a[j].ok = false;
				j++;
			}
			else
			{
				for ( k = 1; k < j; k++ )
				{
					if ( a[k].ok==false && a[k].pc == pc && a[k].stud == stud )
					{
						a[k].end = time;
						a[k].ok = true;
					}
				}
			}
		}
		qsort(a,j,sizeof(a[0]),cmp);
		k = j;
		scanf("%d",&q);
		for ( i = 0; i < q; i++ )
		{
			time = 0;
			scanf("%d%d%d",&b,&e,&stud);
			j = 1;
			while ( j < k && a[j].stud != stud )
				j++;
			for ( ;j < k && a[j].stud == stud; j++ )
			{
				if ( a[j].begin <= b && b <= a[j].end )
				{
					time += (a[j].end-b);
					b = a[j].end;
					if ( a[j].end > e )
					{
						time -= (a[j].end-e);
						break;
					}
				}
				else if ( a[j].begin >= b )
				{
					time += (a[j].end-a[j].begin);
					b = a[j].end;
					if ( e <= a[j].begin )
					{
						time -= (a[j].end-a[j].begin);
						break;
					}
					else if ( e > a[j].begin && e <= a[j].end )
					{
						time -= (a[j].end-e);
						break;
					}
				}
			}
			printf("%d\n",time);
		}
	}
	return 0;
}

