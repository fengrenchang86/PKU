#include <iostream>
#include <math.h>
using namespace std;

struct AC
{
	double x;
	double y;
	double r;
}p[1002];
double f( AC a, AC b )
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main ()
{
	bool find;
	int i,n,j,pos;
	double F;
	double temp,temp2;
	double cx=0.0,cy=0.0;
	while ( scanf("%d",&n) && n!=0 )
	{
		find = false;
		scanf("%lf %lf %lf",&p[0].x,&p[0].y,&p[0].r);
		for ( i = 1; i < n; i++ )
		{
			scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].r);	
			if ( find == true )
				continue;
			F = p[i].r*p[i].r;
			cx = p[i].x;
			cy = p[i].y;
			if ( (cx-p[i-1].x)*(cx-p[i-1].x)+(cy-p[i-1].y)*(cy-p[i-1].y) > p[i-1].r*p[i-1].r )
			{
				find = true;
				pos = i;
				continue;
			}
			for ( j = i-1; j > 0; j-- )
			{
				cx = (cx*F+p[j].x*p[j].r*p[j].r)/(F+p[j].r*p[j].r);
				cy = (cy*F+p[j].y*p[j].r*p[j].r)/(F+p[j].r*p[j].r);
				F += p[j].r*p[j].r;
				temp = (cx-p[j-1].x)*(cx-p[j-1].x)+(cy-p[j-1].y)*(cy-p[j-1].y);
				temp2 = p[j-1].r*p[j-1].r;
//				if ( (cx-p[j].x)*(cx-p[j].x)+(cy-p[j].y)*(cy-p[j].y) > p[j-1].r*p[j-1].r )
				if ( temp > temp2 )
				{
					find = true;
					pos = i;
					break;
				}
			}
		}
		if ( find == false )
			printf("Feasible\n");
		else
			printf("Unfeasible %d\n",pos);
	}
	return 1;
}