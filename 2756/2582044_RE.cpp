#include <iostream>
using namespace std;
const int max = 800;
int ctoi ( char *a, int t[], int size ) //字符串（数字）储存入数组
{										//字符串a，长度为size，存入t[]中，并返回数组的长度
	int i;
	int k = 4;
	int j = -1;
	int temp[4] = { 1,10,100,1000};
	int x;
	if ( a[0] == '+' )
		x = 1;
	else
		x= 0;
	for ( i = size-1; i >= x; i-- )
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
		printf("%04d",t[i]);
	cout<<endl;
}
int a[200],b[200],c[200];
int main ()
{
	char cha[max],chb[max];
	int sizea,sizeb,tcase;
	cin>>tcase;
	while ( tcase )
	{
		tcase--;
		cin>>cha>>chb;
		sizea = ctoi(cha,a,strlen(cha));
		sizeb = ctoi(chb,b,strlen(chb));
		sizea = plus(a,b,sizea,sizeb,c);
		print(c,sizea);
	}
	return 0;
}