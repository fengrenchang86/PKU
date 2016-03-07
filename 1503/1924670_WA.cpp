#include <iostream>
#include <iomanip>
using namespace std;

int ctoi ( char *a, int t[], int size ) //字符串（数字）储存入数组
{										//字符串a，长度为size，存入t[]中，并返回数组的长度
	int begin = 0;
	while ( a[begin] == '0' )
		begin++;
	int i;
	int k = 4;
	int j = -1;
	int temp[4] = { 1,10,100,1000};
	for ( i = size-1; i >= begin; i-- )
	{
		if ( k == 4 )
		{
			k = 0;
			j++;
			t[j] = temp[k]*(a[i]-'0');
			k++;
		}
		else
		{
			t[j] += temp[k]*(a[i]-'0');
			k++;
		}
	}
	return j+1;
}	//数组t[]中，低位在细数下标，高位在大数下标

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
	while ( c[i] <= 0 )
		i--;
	return i+1;
}
void print( int t[], int size )
{
	cout<<t[size-1];
	for ( int i = size-2; i >= 0; i-- )
		cout<<setw(4)<<setfill('0')<<t[i];
	cout<<endl;
}
void main ()
{
	char *a = new char[120];
	int *na = new int[100];
	int *nb = new int[100];
	int *nc = new int[100];
	int i;
	int sizea,sizeb;
	scanf("%s",a);
	sizea = ctoi(a,na,strlen(a));
	while ( scanf("%s",a)&&a[0]!='0')
	{
		sizeb = ctoi(a,nb,strlen(a));
		sizea = plus(na,nb,sizea,sizeb,nc);
		for ( i = 0; i < sizea; i++ )
			na[i] = nc[i];
		for ( i = 0; i <= sizeb; i++ )
			nb[i] = 0;
		na[i] = 0;
	}
	print(na,sizea);	
}