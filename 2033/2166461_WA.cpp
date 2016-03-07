#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
//	fstream cin("file.in");
	char ch[9000];
	int a,b,c;
	int i;
	while ( cin>>ch && ch[0] != '0'  )
	{
		if ( ch[1] == NULL )
		{
			cout<<1<<endl;
			continue;
		}
		a = 1;
		if ( (ch[0]-'0')*10+ch[1]-'0' <= 26 )
			b = 2;
		else
			b = 1;
		c = b;
		i = 2;
		while ( ch[i] != NULL )
		{
			c = b;
			if ( (ch[i-1]-'0')*10+ch[i]-'0' <= 26 )
				c += a;
			a = b;
			b = c;
			i++;
		}
		cout<<c<<endl;
	}
	return 0;
}