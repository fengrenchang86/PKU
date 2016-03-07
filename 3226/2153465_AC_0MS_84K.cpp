#include <iostream>
#include <fstream>
using namespace std;
int cheng ( int a[], int sizea, int x, int b[] )
{				//数组a[sizea]×x，保存到数组b[]
	int size = sizea;
	int i;
	for ( i = 0; i < size; i++ )
		b[i] = a[i];
	while ( i < 2*size )
	{
		b[i] = 0;
		i++;
	}
	for ( i = 0; i < size; i++ )
		b[i] *= x;
	for ( i = 0; i < size; i++ )
	{
		b[i+1] += b[i]/10000;
		b[i] %= 10000;
	}
	if ( b[size] > 0 )
		size++;
	return size;//返回数组b[]的长度
}
int plus ( int a[], int b[], int sizea, int sizeb, int c[] )
{			//数组a[sizea]+数组b[sizeb],结果存入数组c[]
	int i ;
	int max = sizea<sizeb ? sizea:sizeb;
	c[0] = 0;
	for ( i = 0; i < max; i++ )
	{
		c[i+1] = (a[i]+b[i])/10000;
		c[i] += (a[i]+b[i])%10000;
	}
	if ( sizea < sizeb )
	{
		c[i] += b[i];
		for ( i++; i < sizeb; i++ )
			c[i] = b[i];
	}
	else if ( sizea > sizeb )
	{
		c[i] += a[i];
		for ( i++; i < sizea; i++ )
			c[i] = a[i];
	}
	while ( c[i] <= 0 && i > 0 )
		i--;
	return i+1;
}
int visit[30];
int main ()
{
//	fstream fin("file.txt");
	int *a = new int[30];
	int *b = new int[30];
	int *c = new int[30];
	int *temp;
	int sizea,sizeb,sizec;
	int n;
	int i,j;
	int num;
	char ch[30];
	int v[30];
	while ( cin>>n && n!=0)
	{
		for ( i = 0; i < 30; i++ )
		{
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
			visit[i] = 0;
		}
		cin>>ch;
		for ( i = 0; i < n; i++ )
			v[i+1] = ch[i]-'A'+1;
		sizea = 1;
		sizeb = 0;
		sizec = 1;
		c[0] = 0;
		for ( i = 1; i <= n; i++ )
		{
			num = 0;
			visit[v[i]] = 1;
			for ( j = 0; j < v[i]; j++ )
				if ( visit[j] == 1 )
					num++;
			sizea = 1;
			a[0] = v[i]-1-num;
			for ( j = 26-i; j >= 27-n; j-- )
			{
				sizea = cheng(a,sizea,j,b);
				temp = a;
				a = b;
				b = temp;
			}
			sizec = plus(a,c,sizea,sizec,b);
			temp = c;
			c = b;
			b = temp;
		}
		printf("%d",c[sizec-1]);
		for ( i = sizec-2; i >= 0; i-- )
			printf("%04d",c[i]);
		printf("\n");
	}
	return 0;
}