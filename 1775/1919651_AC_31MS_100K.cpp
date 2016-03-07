#include <iostream>
using namespace std;
int main ()
{
	int list[10] = {1,1,2,6,24,120,720,5040,40320,362880};
	int d[12];
	int e[12];
	d[0] = list[0];
	e[0] = list[1];
	short a[11] = { 0, 0, 0 ,0 , 0, 0 ,0 ,0 ,0,0,0};
	int count = 0;
	int p = 0;
	char k[100];
	int v[1200] = { 0 };
	int i = 0;
	while ( a[10] == 0 )
	{
		a[0]++;
		p = 0;
		while ( a[p] == 2 )
		{
			a[p+1]++;
			a[p++]=0;
		}
		for ( i = 0; i < 10; i++ )
		{
			if ( a[i] == 1 )
				v[count]+=list[i];
		}
	//	printf("%d\n",v[count]);
	//	cin.getline(k,100,'\n');
		count++;
	}
	while ( scanf("%d",&p) && p>=0 )
	{
		for ( i = 0; v[i] < p; i++ )
		{
			if ( v[i] >= p )
				break;
		}
		if ( v[i] == p )
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 1;
}