#include <iostream>
using namespace std;
int main ()
{
	char a[1200];
	char b[1200];
	int va[256];
	int vb[256];
	int i,j;
	while ( cin.getline(a,1200,'\n')!=0 )
	{
		cin.getline(b,1200,'\n');
		for ( i = 0; i < 256; i++ )
			va[i] = vb[i] = 0;
		for ( i = 0; a[i] != NULL; i++ )
			va[a[i]]++;
		for ( i = 0; b[i] != NULL; i++ )
			vb[b[i]]++;
		for ( i = 0; i < 256; i++ )
		{
			if ( va[i] > vb[i] )
				va[i] = vb[i];
			for ( j = 0; j < va[i]; j++ )
				printf("%c",char(i));
		}
		cout<<endl;
	}
	return 0;
}