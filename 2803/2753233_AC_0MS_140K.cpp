#include <iostream>
using namespace std;
int x= 0,y=0;
void f ( char *a )
{
	int i,k=0;
	char b[300];
	int len = strlen(a);
	if ( len > 4 && a[0]=='a' && a[1]=='n' && a[2]=='t' && a[3] == 'i' && x==0 )
	{
		x = 1;
		i = 4;
		while ( a[i] != NULL )
			b[k++] = a[i++];
		b[k] = NULL;
		printf("against ");
		f(b);
	}
	else if ( len > 4 && a[0]=='p' && a[1]=='o' && a[2]=='s' && a[3] == 't' && x==0)
	{
		x = 1;
		i = 4;
		while ( a[i] != NULL )
			b[k++] = a[i++];
		b[k] = NULL;
		printf("after ");
		f(b);
	}
	else if ( len > 3 && a[0]=='p' && a[1]=='r' && a[2]=='e' && x==0)
	{
		x = 1;
		i = 3;
		while ( a[i] != NULL )
			b[k++] = a[i++];
		b[k] = NULL;
		printf("before ");
		f(b);
	}
	else if ( len > 2 && a[0]=='r' && a[1]=='e' && x==0)
	{
		x = 1;
		i = 2;
		while ( a[i] != NULL )
			b[k++] = a[i++];
		b[k] = NULL;
		f(b);
		printf(" again");
	}
	else if ( len > 2 && a[0]=='u' && a[1]=='n' && x==0)
	{
		x = 1;
		i = 2;
		while ( a[i] != NULL )
			b[k++] = a[i++];
		b[k] = NULL;
		printf("not ");
		f(b);
	}
	else if ( len > 2 && a[len-1]=='r' && a[len-2] == 'e'&&y==0)
	{
		y = 1;
		a[len-2] = NULL;
		printf("one who ");
		f(a);
		printf("s");
	}
	else if ( len > 3 && a[len-1]=='g' && a[len-2] == 'n' && a[len-3]=='i' &&y==0)
	{
		y = 1;
		a[len-3] = NULL;
		printf("to actively ");
		f(a);
	}
	else if ( len > 3 && a[len-1]=='e' && a[len-2] == 'z' && a[len-3]=='i' &&y==0)
	{
		y = 1;
		a[len-3] = NULL;
		printf("change into ");
		f(a);
	}
	else if ( len > 1 && a[len-1] == 's' &&y==0)
	{
		y = 1;
		a[len-1] = NULL;
		printf("multiple instances of ");
		f(a);
	}
	else if ( len > 4 && a[len-1]=='n' && a[len-2] == 'o' && a[len-3]=='i'&&a[len-4]=='t'&&y==0)
	{
		y = 1;
		a[len-4] = NULL;
		printf("the process of ");
		f(a);
		printf("ing");
	}
	else
		printf("%s",a);
}
int main ()
{
	int n,i;
	char a[1000];
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		x = 0;
		y = 0;
		cin>>a;
		f(a);
		cout<<endl;
	}
	return 0;
}