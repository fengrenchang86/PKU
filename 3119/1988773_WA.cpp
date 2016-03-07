#include <iostream>
#include <iomanip>
using namespace std;
int f ( int a, int b,int x, int y )
{
	if ( a*x-y+b > 0 )
		return 1;
	else if ( a*x-y+b < 0 )
		return -1;
	else 
		return 0;
}
int main ()
{
	int arr[80000];
	int tcase,it;
	int x,y,n,a,b,i,j,k,p,pos,c;
	scanf("%d",&tcase);
	for ( it = 1; it <= tcase; it++ )
	{
		scanf("%d %d",&a,&b);
		scanf("%d",&n);
		if ( f(a,b,0,0) == 0 )
		{
			if ( f ( a,b,-1,0 ) == 0 )
			{
				if ( f ( a,b,-1,1) > 0 )
				{
					p = 1;
					x = -1;
					y = 1;
				}
				else
				{
					p = -1;
					x = -1;
					y = 1;
				}
			}
			else if ( f ( a ,b, 1, 0 ) > 0 )
			{
				p = 1;
				x = 1;
				y = 0;
			}
			else
			{
				p = -1;
				x = 1;
				y = 0;
			}
		}
		else if ( f ( a,b,0,0 ) > 0 )
		{
			p = 1;
			x = 0;
			y = 0;
		}
		else
		{
			p = -1;
			x = 0;
			y = 0;
		}
		c = 1;
		arr[0] = 0;
		pos = 1;
		i = 0;
		while ( c <= 65536*65536 )
		{
			i++;
			while ( x >= -1*i )
			{
				x--;
				if ( x < -i )
				{
					x++;
					break;
				}
				if ( p*f(a,b,x,y) < 0 )
				{
					arr[pos++] = c++;
					p *= -1;
				}
				else if ( f ( a,b,x,y) != 0 )
				{c++;}
		
			}
//			y--;
			while ( y <= i )
			{
				y++;
				if ( y > i )
				{
					y--;
					break;
				}
				if ( p*f(a,b,x,y) < 0 )
				{
					arr[pos++] = c++;
					p *= -1;
				}
				else if ( f ( a,b,x,y) != 0 )
					c++;
			}
	//		x--;
			while ( x <= i )
			{
				x++;
				if ( x > i )
				{
					x--;
					break;
				}
				if ( p*f(a,b,x,y) < 0 )
				{
					arr[pos++] = c++;
					p *= -1;
				}
				else if ( f ( a,b,x,y) != 0 )
					c++;
			}
//			y++;
			while ( y >= -1*i )
			{
				y--;
				if ( y < -i )
				{
					y++;
					break;
				}
				if ( p*f(a,b,x,y) < 0 )
				{
					arr[pos++] = c++;
					p *= -1;
				}
				else if ( f ( a,b,x,y) != 0 )
					c++;
			}
		}
		printf("Caso %d\n",it);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d %d",&a,&b);
			if ( a > b )
			{
				k = a;
				a = b;
				b = k;
			}
			k = 0;
			while ( arr[k] <= a )
				k++;
			if ( k%2==0 )
				a = 1;
			else
				a = -1;
			while ( arr[k] <= b )
				k++;
			if ( k%2 == 0 )
				b = 1;
			else
				b = -1;
			
			if ( a*b > 0 )
				printf("Mesmo lado da fronteira\n");
			else
				printf("Lados opostos da fronteira\n");
		}
	//	for ( j = 0; j < 20; j++ )
	//		printf("%d\n",arr[j]);
	/*	for ( i = 5; i >= -5; i-- )
		{
			for ( j = -5; j <= 5; j++ )
				if ( g[j+100][i+100] >= 0 )
					cout<<setw(5)<<g[j+100][i+100];
				else
					cout<<setw(5)<<'*';
//				printf("%d  ",g[i+100][j+100]);
			printf("\n");
		}
	}*/
	return 1;
	}
}