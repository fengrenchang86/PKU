#include<iostream>
#include<stdlib.h>
using namespace std;
struct ac
{
	int i,j;
	int x,y;
}t[140000];
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	__int64 i, j;
	i = __int64(c->x)*__int64(d->y);
	j = __int64(c->y)*__int64(d->x);
//	if(c->y == 1073643522)
//		cout<<"golf"<<endl;
	if(i > j)
		return 1;
	else if( i < j )
		return -1;
	else
		return c->i - d->i;
}
int gcd(int x, int y)
{
	if(x % y == 0 )
		return y;
	else
		return gcd(y, x%y);
}
int main ()
{
	int x, y;
	int i, j, k = 0;
	scanf("%d%d", &x, &y);
	for(i = 1; i <= 32767; i++)
	{
		j = i*y/x;
		t[k].x = abs(x*j-y*i);
		t[k].y = y*j;
		t[k].i = i;
		t[k].j = j;
		if(j >= 1 && j <= 32767 && gcd(i,j) == 1 && i*y != j*x)
			k++;
		j++;
		t[k].x = abs(x*j-y*i);
		t[k].y = y*j;
		t[k].i = i;
		t[k].j = j;
		if(j >= 1 && j <= 32767 && gcd(i,j) == 1 && i*y != j*x)
			k++;
		j-=2;
		t[k].x = abs(x*j-y*i);
		t[k].y = y*j;
		t[k].i = i;
		t[k].j = j;
		if(j >= 1 && j <= 32767 && gcd(i,j) == 1 && i*y != j*x)
			k++;
	}
	qsort(t, k, sizeof(t[0]), cmp);
	cout<<t[0].i << " " << t[0].j << endl;
	return 0;
}