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
		short *t[2];
		t[0] = new short[size+1];
		t[1] = new short[size+1];
		scanf ( "%s", a );
		for ( i = 0; i < size; i++ )
			t[0][i] = 0;
		t[1][0] = 0;
		for ( i = 0; i < size; i++ )
		{
			t[(i+1)%2][0] = 0;
			for ( j = 0; j < size; j++ )
			{
				if ( a[i] == a[size-j-1] )
					t[(i+1)%2][j+1] = t[i%2][j]+1;
				else
					t[(i+1)%2][j+1] = t[i%2][j+1]>t[(i+1)%2][j]?t[i%2][j+1]:t[(i+1)%2][j];
			}
		}
//		cout<<t[i][j]<<endl;
		cout<<size-(t[i%2][j])<<endl;
	}
	return 1;
}
