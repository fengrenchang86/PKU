#include <iostream>
#include <math.h>
using namespace std;
double pi = asin(1)*2;
struct node
{
	int R;
	int S;
	int P;
	int T;
}ac[120];
int f ( int x, int y, int R, int S, int P )
{
	P /= 2;
	if ( x <= R+P && x >= R-P && y <= S+P && y >= S-P )
		return 1;//能够炸到
	else
		return 0;//不能炸到
}
int main ()
{
	int m,n,k;
	int i,j,h;
	int count = 0;
	int c;
	scanf("%d%d%d",&m,&n,&k);
	for ( i = 0; i < k; i++ )
		scanf("%d%d%d%d",&ac[i].R,&ac[i].S,&ac[i].P,&ac[i].T);
	for ( i = 0; i < m; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			c = 0;
			for ( h = 0; h < k; h++ )
			{
				if ( ac[h].T != f(i,j,ac[h].R,ac[h].S,ac[h].P) )
				{
					c = 1;
					break;
				}
			}
			if ( c == 0 )
				count++;
		}
	}
	cout<<count<<endl;
	return 0;
}