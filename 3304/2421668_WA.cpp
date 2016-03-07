#include <iostream>
#include <stdlib.h>
using namespace std;
struct line_point
{
	double x1,x2,y1,y2;
}line[110];
bool jiao ( double a, double b, double x1, double y1, double x2, double y2 )
{
	if ( (a*x1-y1+b)*(a*x2-y2+b) <= 0 )
		return true;
	else
		return false;
}
int main ()
{
	int tcase;
	int num,i,j,k;
	double a,b;
	bool ok;
	scanf("%d",&tcase);
	while ( tcase )
	{
		scanf("%d",&num);
		for ( i = 0; i < num ;i++ )
			cin>>line[i].x1>>line[i].y1>>line[i].x2>>line[i].y2;
		if ( num == 1 )
		{
			cout<<"Yes!"<<endl;
			tcase--;
			continue;
		}
		for ( i = 0; i < num-1; i++ )
		{
			for ( j = i+1; j < num; j++ )
			{
				ok = true;
				if ( line[i].x1 == line[j].x1 )
				{
					a = line[i].x1;
					for ( k = 0; k < num; k++ )
					{
						if ( !(line[k].x1<=a&&a<=line[k].x2 || line[k].x2<=a&&a<=line[k].x1) )
						{
							ok = false;
							break;
						}
					}
				}
				else
				{
					a = (line[i].y1-line[j].y1)/(line[i].x1-line[j].x1);
					b = line[i].y1-a*line[i].x1;
					for ( k = 0; k < num; k++ )
					{
						if ( jiao(a,b,line[k].x1,line[k].y1,line[k].x2,line[k].y2) == false )
						{
							ok = false;
							break;
						}
					}
				}
				if ( ok == true )
					break;
				ok = true;
				if ( line[i].x1 == line[j].x2 )
				{
					a = line[i].x1;
					for ( k = 0; k < num; k++ )
					{
						if ( !(line[k].x1<=a&&a<=line[k].x2 || line[k].x2<=a&&a<=line[k].x1 ) )
						{
							ok = false;
							break;
						}
					}
				}
				else
				{
					a = (line[i].y1-line[j].y2)/(line[i].x1-line[j].x2);
					b = line[i].y1-a*line[i].x1;
					for ( k = 0; k < num; k++ )
					{
						if ( jiao(a,b,line[k].x1,line[k].y1,line[k].x2,line[k].y2) == false )
						{
							ok = false;
							break;
						}
					}
				}
				if ( ok == true )
					break;
				ok = true;
				if ( line[i].x2 == line[j].x1 )
				{
					a = line[i].x2;
					for ( k = 0; k < num; k++ )
						{
						if ( !(line[k].x1<=a&&a<=line[k].x2 || line[k].x2<=a&&a<=line[k].x1 ) )
						{
							ok = false;
							break;
						}
					}
				}
				else
				{
					a = (line[i].y2-line[j].y1)/(line[i].x2-line[j].x1);
					b = line[i].y2-a*line[i].x2;
					for ( k = 0; k < num; k++ )
					{
						if ( jiao(a,b,line[k].x1,line[k].y1,line[k].x2,line[k].y2) == false )
						{
							ok = false;
							break;
						}
					}
				}
				if ( ok == true )
					break;
				ok = true;
				if ( line[i].x2 == line[j].x2 )
				{
					a = line[i].x2;
					for ( k = 0; k < num; k++ )
						{
						if ( !(line[k].x1<=a&&a<=line[k].x2 || line[k].x2<=a&&a<=line[k].x1 ) )
						{
							ok = false;
							break;
						}
					}
				}
				else
				{
					a = (line[i].y2-line[j].y2)/(line[i].x2-line[j].x2);
					b = line[i].y2-a*line[i].x2;
					for ( k = 0; k < num; k++ )
					{
						if ( jiao(a,b,line[k].x1,line[k].y1,line[k].x2,line[k].y2) == false )
						{
							ok = false;
							break;
						}
					}
				}
				if ( ok == true )
					break;
			}
			if ( ok == true )
				break;
		}
		if ( ok == true )
			cout<<"Yes!"<<endl;
		else
			cout<<"No!"<<endl;
		tcase--;
	}
	return 0;
}