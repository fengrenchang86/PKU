#include <iostream>
#include <fstream>
using namespace std;
/*
	S		(((()()())))
	P-sequence	    4 5 6666
	W-sequence	    1 1 1456
	((())()(()))
	3 3 4 6 6 6
	*/
int main ()
{
	bool flag;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char ch[8100000];
//	char ch[1000];
	int tcase,it;
	int n,i,j,k;
	int count;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		flag = true;
		scanf("%d",&n);
		j = 0;
		count = 1;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&k);
			while ( count <= k )
			{
				ch[j++] = '(';
				count++;
			}
			ch[j++] = ')';
		}
		for ( i = 0; ch[i] != NULL; i++ )
		{
			if ( ch[i] == ')' )
			{
				k = 1;
				j = i-1;
				count = 1;
				while ( count != 0 )
				{
					if ( ch[j] == '(' )
						count--;
					else
					{
						count++;
						k++;
					}
					j--;
				}
				if ( flag == true )
				{
					cout<<k;
					flag = false;
				}
				else
					cout<<" "<<k;
				
			}
		}
		cout<<endl;
	}
	return 0;
}