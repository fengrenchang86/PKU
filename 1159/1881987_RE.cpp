#include <iostream>
using namespace std;
int main ()
{
	int size;
	int i;
	int j;
	int k;
	int max;
	int c;
	while( scanf("%d",&size)!=EOF )
	{
//		cin>>size;
		max = 0;
		char *a = new char[size+1];
//		char **t;
//		t = new char*[size];
//		for ( i = 0; i < size ; i++ )
//			t[i] = new char[size];
		scanf ( "%s", a );
//		for ( i = 0; i < size; i++ )
//			t[i][0] = t[0][i] = 0;
		unsigned short int t[3000][3000]={0};
		for ( i = 0; i < size; i++ )
		{
			for ( j = size-1; j >= 0; j-- )
			{
				if ( a[i] == a[j] )
					t[i+1][size-j+1] = t[i][size-j]+1;
				else if ( t[i+1][size-j] > t[i][size-j+1] )
					t[i+1][size-j+1] = t[i+1][size-j];
				else
					t[i+1][size-j+1] = t[i][size-j+1];
			}
		}
		cout<<size-int(t[size][size])<<endl;
	}
	return 1;
}