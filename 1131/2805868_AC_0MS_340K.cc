#include <iostream>
#include <string>
using namespace std;
char ch[100][300];
int main ()
{
	void divide8(char*,char*);
	void cheng ( char*,int,char*);
	void plus(char*, char*);
	int i;
	char t[300],t2[300];
	char sum[300];
	strcpy(ch[0],"0.125");
	for ( i = 1; i < 100; i++ )
	{
		strcpy(t,ch[i-1]);
		divide8(ch[i-1],ch[i]);
		strcpy(ch[i-1],t);
	}
	while ( cin>>t )
	{
		if ( t[0] == '1' )
		{
			printf("1 [8] = 1 [10]\n");
			continue;
		}
		else if ( t[1] == NULL )
		{
			printf("0 [8] = 0 [10]\n");
			continue;
		}
		strcpy(sum,"0.0");
		for ( i = 2; t[i] != NULL; i++ )
		{
			cheng(ch[i-2],t[i]-'0',t2);
			plus(t2,sum);
		}
		if ( sum[2] == NULL )
			sum[1] = NULL;
		printf("%s [8] = %s [10]\n",t,sum);
	}
	return 0;
}
void plus (char *a, char *sum )
{
	int s1 = strlen(a);
	int s2 = strlen(sum);
	int i,j;
	if ( s1 < s2 )
	{
		for ( i = 2; i < s1; i++ )
			sum[i] = sum[i]+a[i]-'0';
		j = s2-1;
	}
	else
	{
		for ( i = 2; i < s2; i++ )
			sum[i] = sum[i]+a[i]-'0';
		while ( i < s1 )
		{
			sum[i] = a[i];
			i++;
		}
		sum[i] = NULL;
		j = s1 - 1;
	}
	i = j;
	while ( j > 2 )
	{
		sum[j-1] += (sum[j]-'0')/10;
		sum[j] = (sum[j]-'0')%10+'0';
		j--;
	}
	j = i;
	while ( sum[j] == '0' )
		j--;
	sum[j+1] = NULL;
}
void cheng ( char *a, int k, char *b ) // b= a*k;
{
	int i,n=strlen(a);
	strcpy(b,"0.");
	for ( i = 2; i < n; i++ )
		b[i] = (a[i]-'0')*k+'0';
	b[i] = NULL;
	for ( i = n-1; i > 2; i-- )
	{
		b[i-1] += (b[i]-'0')/10;
		b[i] = (b[i]-'0')%10+'0';
	}
	i = n-1;
	while ( b[i] == '0' )
		i--;
	b[i+1] = NULL;
}
void divide8 ( char*a, char *b ) //   b = a/8;
{
	int i=2,j;
	b[0] = '0';
	b[1] = '.';
	int n = strlen(a);
	while ( 1 )
	{
		j = a[i]-'0';
		b[i] = j/8+'0';
		if ( i+1 < n )
			a[i+1] += j%8*10;
		else
			a[i+1] = j%8*10+'0';
		i++;
		if ( a[i] == '0' && i >= n )
			break;
	}
	b[i] = NULL;
}