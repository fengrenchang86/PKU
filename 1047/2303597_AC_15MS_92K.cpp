#include <iostream>
using namespace std;
int cheng( int a[], int k, int size )
{
	int i;
	for ( i = 0; i < size; i++ )
		a[i] *= k;
	a[size] = 0;
	for ( i = 0; i < size; i++ )
	{
		a[i+1] += a[i]/10000;
		a[i] %= 10000;
	}
	if ( a[size] > 0 )
		size++;
	return size;
}
void change ( int a[], int size, char *t, int len )
{
	int key;
	int i,j = len-1;
	t[len] = NULL;
	int c;
	for ( i = 0; i < size && j >= 0; i++ )
	{
		key = a[i];
		for ( c = 0; c < 4; c++ )
		{
			t[j] = (key%10)+'0';
			key/=10;
			j--;
			if ( j < 0 )
				break;
		}
	}
}
int com ( char *a, char *b, int len )
{
	int i,j,c = 0;
	i = 0;
	j = 0;
	while ( i <= len )
	{
		j = 0;
		if ( a[i] == b[j] )
		{
			while ( a[i] == b[j] )
			{
				i++;
				j++;
				c++;
				if ( b[j] == NULL )
					return 1;
			}
			i--;
		}
		i++;
	}
	return 0;
}
int main ()
{
	int pow[4] = {1,10,100,1000};
	char ch[100];
	int a[20];
	int s[20];
	char out[200];
	int i,j;
	int size;
	char q[200];
	int len;
	int flag;
	while ( cin>>ch )
	{
		for ( i = 0; i < 20; i++ )
			a[i] = 0;
		len = strlen(ch);
		for ( i = len; i < 2*len; i++ )
			q[i] = q[i-len] = ch[i-len];
		q[2*len] = NULL;
		i = len-1;
		j = 0;
		while ( i >= 0 )
		{
			a[j/4] += pow[j%4]*(ch[i]-'0');
			j++;
			i--;
		}
		size = j/4;
		if ( j%4!=0 )
			size++;
		for ( i = 0; i < size; i++ )
			s[i] = a[i];
		flag = 1;
		for ( i = 2; i <= len; i++ )
		{
			for ( j = 0; j < size; j++ )
				a[j] = s[j];
			size = cheng(a,i,size);
			change(a,size,out,len);
			if ( com(q,out,len) == 0 )
			{
				flag = 0;
				printf("%s is not cyclic\n",ch);
				break;
			}
		}
		if ( flag == 1 )
			printf("%s is cyclic\n",ch);
	}
	return 0;
}