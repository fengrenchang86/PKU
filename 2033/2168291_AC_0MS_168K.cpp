#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
//	fstream cin("file.in");
	char ch[90000];
	int a,b,c;
	int i;
	while ( cin>>ch && ch[0] != '0'  )
	{
		if ( ch[1] == NULL )
		{
			cout<<1<<endl;
			continue;
		}
		a = 0;
		b = 1;
		i = 0;
		while ( ch[i] != NULL )
		{
			c = b;
			if ( (ch[i] == '1' || ch[i] == '2' ) && ch[i+1] == '0' )
			{
				i++;
			}
			else if ( (ch[i-1]-'0')*10+ch[i]-'0' <= 26 && ch[i-1] != '0' )
			{
				c += a;
			}
			a = b;
			b = c;
			i++;
		}
		cout<<c<<endl;
	}
	return 0;
}