#include <iostream.h>
#include <stdio.h>

void main ()
{
	char a[10];
	int num;
	int t[12] = {0, 1, 2, 3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11};
	int low = 0;
	int hight = 11;
	while ( 1 )
	{
		scanf("%d",&num);
		if ( num == 0 )
			break;
		getchar();
		gets(a);
		if(a[4]== 'h')
		{
			if ( hight+1 >= num )
				hight = num-1;
		}
		else if (a[4]== 'l')
		{
			if ( low-1 <= num )
				low = num+1;
		}
		else 
		{
			if ( hight < low )
				cout<<"Stan is dishonest"<<endl;
			else if ( num<=hight && num>= low )
				cout<<"Stan may be honest"<<endl;
			else
				cout<<"Stan is dishonest"<<endl;
			low = 1;
			hight = 10;
		}
	}	

}