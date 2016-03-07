#include <iostream>
using namespace std;
int main ()
{
	int list1[10],list2[10];
	int tcase;
	cin>>tcase;
	int a,b;
	int x,y,i;
	while ( tcase-- )
	{
		x = y =0;
		memset(list1,0,sizeof(list1));
		memset(list2,0,sizeof(list2));
		cin>>a>>b;
		for ( i = 0; i < 4; i++ )
		{
			if ( a%10 == b%10 )
				x++;
			else
			{
				list1[a%10]++;
				list2[b%10]++;
			}
			a /= 10;
			b /= 10;
		}
		for ( i = 0; i < 10; i++ )
		{
			y += list1[i]<list2[i]?list1[i]:list2[i];
		}
		printf("%dA%dB\n",x,y);
	}
	return 0;
}