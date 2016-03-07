#include <iostream>
using namespace std;
struct str
{
	int x;
	int y;
	int z;
	int v;
	char name[10];
};
void print(char *a )
{
	int i;
	for ( i = 0; a[i] != NULL; i++ )
		cout<<a[i];
}
int main ()
{
	int n;
	int i;
	int max;
	int min;
	int p,q;
	while ( cin>>n && n != -1 )
	{
		max = -1;
		min = 9999991;
		str *a = new str[n];
		for ( i = 0; i < n; i++ )
		{
			cin>>a[i].x>>a[i].y>>a[i].z>>a[i].name;
			a[i].v = a[i].x*a[i].y*a[i].z;
			if ( a[i].v > max )
			{
				max = a[i].v;
				p = i;
			}
			if ( a[i].v < min )
			{
				min = a[i].v;
				q = i;
			}
		}
		print(a[p].name);
		cout<<" took clay from ";
		print(a[q].name);
		cout<<"."<<endl;
	}
	return 1;
}