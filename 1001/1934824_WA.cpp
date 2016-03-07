#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int todig( char *a , int &little)
{
	int i;
	int num = 0;
	for ( i = 0; a[i] != '.'; i++ )
	{
		num *= 10;
		num += a[i]-'0';
	}
	little = i;
	i++;
	while ( a[i] != NULL )
	{
		if ( a[i] >= '0' && a[i] <= '9' )
		{
			num*=10;
			num+=a[i]-'0';
			i++;
		}
	}
	little = i-1-little;
	return num;
}
void chengfa ( int a[], int b[], int &sizea, int &sizeb, int c[], int &sizec )
{
	int i,j;
	for ( i = 0; i < 100; i++ )
		c[i] = 0;
	for ( i = 0; i < sizea; i++ )
	{
		for ( j = 0; j < sizeb; j++ )
			c[i+j] += a[i]*b[j];
	}
	sizec = sizea+sizeb-1;
	for ( i = 0; i < sizec; i++ )
	{
		c[i+1] += c[i]/10000;
		c[i] %= 10000;
	}
	while ( c[sizec] > 0 )
		sizec++;
}
int tochar( char *t, int a[], int sizea )
{
	int i;
	int c = 0;
	for ( i = 0; i < sizea; i++ )
	{
		t[c++] = a[i]%10+'0';
		t[c++] = a[i]%100/10+'0';
		t[c++] = a[i]%1000/100+'0';
		t[c++] = a[i]/1000+'0';
	}
	t[c] = NULL;
	return c;
}




int main ()
{
	char s[500];
	int a[500];
	int b[500];
	int c[500];
	int sizea,sizeb,sizec;
	int exp;
	int i;
	int g;
	int end;
	int little;
	while ( scanf("%s %d",s,&exp)!=EOF )
	{	
		for ( i = 0; i < 100; i++ )
			a[i] = b[i] = c[i] = 0;
		sizea = sizeb = 1;
		a[0] = 1;
		b[0] = todig(s,little);
		for ( i = 0; i < 10; i++ )
		{
			b[i+1] += b[i]/10000;
			b[i] %= 10000;
		}
		while ( b[sizeb]>0 )
			sizeb++;
		for ( i = 0; i < exp; i++ )
		{
			chengfa(a,b,sizea,sizeb,c,sizec);
			for ( g = 0; g < sizec; g++ )
				a[g] = c[g];
			a[g] = 0;
			sizea = sizec;
		}
		sizec = tochar(s,c,sizec);
		little = little*exp;
		while ( s[sizec-1] == '0' )
			sizec--;
		if ( little >= sizec )
		{
			cout<<".";
			for ( i = 0; i < little-sizec; i++ )
				cout<<'0';
			for ( i = sizec-1; i >= 0; i-- )
				cout<<s[i];
			cout<<endl;
		}
		else
		{
			end = 0;
			while ( s[end] == '0' )
				end++;
			little = sizec - little;
			g = 0;
			i = sizec-1;
			for ( ; i >=0 && g < little; i-- )
			{
				if ( g == little )
					break;
				g++;
				cout<<s[i];
			}
			if ( i+1 == end )
				continue;
			cout<<'.';
			for ( ; i >= end; i-- )
				cout<<s[i];
			cout<<endl;
		}
	}
	return 1;
}
