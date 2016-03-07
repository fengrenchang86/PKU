#include <iostream>
using namespace std;
int main ()
{
	int size;
	int i;
	int j;
	while( scanf("%d",&size)!=EOF )
	{
//		cin>>size;
		char *a = new char[size+1];
		short **t;
		t = new short*[size+1];
		for ( i = 0; i < size+1 ; i++ )
			t[i] = new short[size+1];
		scanf ( "%s", a );
		for ( i = 0; i < size; i++ )
			t[i][0] = t[0][i] = 0;
		for ( i = 0; i < size; i++ )
		{
			for ( j = 0; j < size; j++ )
			{
				if ( a[i] == a[size-j-1] )
					t[i+1][j+1] = t[i][j]+1;
				else
					t[i+1][j+1] = t[i][j+1]>t[i+1][j]?t[i][j+1]:t[i+1][j];
			}
		}
//		cout<<t[i][j]<<endl;
		cout<<size-(t[i][j])<<endl;
	}
	return 1;
}