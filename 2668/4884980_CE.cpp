#include<iostream>
#include <math.h>
using namespace std;

int main()
{
	double x, y;
	int n, d;
	int i, k;
	while(scanf("%d %d", &d, &n) != EOF)
	{
		if(n == 0 && d == 0)
			break;
		if(n > 50)
		{
			y = log(n) + 0.57721566490153286060651209;
			y *= d;
			
		}
		else
		{
			y = 0.0;
			for(i = 1; i <= n; i++)
			{
				y += (double)(1.0/i);
			}
			y *= d;
		}
		if(y - (int)y >= 0.5)
			printf("%d\n", (int)y + 1);
		else
			printf("%d\n", (int)y);
			/*		y = log(k);
			cout<<y + 0.57721566490153286060651209<<endl;
			x = 0.0;
			for(i = 1; i <= k; i++)
			{
			x += (double)(1.0/i);
		}
		cout<<x<<endl;
		*/
	}
	return 0;
}