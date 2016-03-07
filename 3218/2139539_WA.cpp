#include <iostream>
#include <fstream>
using namespace std;
int list[128];
char ans[1000];
int row = 0, col = 0;
int begin = 0;
void get ( char *a )
{
	int i = 0;
	while ( a[i] == ' ' )
		i++;
	while ( a[i] != NULL )
	{
		ans[col++] = a[i];
		i++;
	}
	i = col-1;
	while ( ans[i] == ' ' )
	{
		ans[i] = NULL;
		i--;
	}
	ans[i+1] = ' ';
	col = i+2;
	ans[i+2] = NULL;
}
void printL ( )
{
	char a[100];
	int count = 0;
	int i = 0, j = 0;
	while ( ans[i] != NULL )
	{
		if ( count == 75 )
		{
			count = 0;
			while ( a[j] != ' ' && ans[i] != NULL && ans[i] != ' ')
			{
				i--;
				j--;
			}
			a[j] = NULL;
			printf("%s\n",a);
			i ++;
			j = 0;
		}
		else
		{
			a[j++] = ans[i];
			i++;
			count++;
		}
	}
	if ( count != 0 )
	{
		a[j] = NULL;
		printf("%s\n",a);
	}
}
void printR ( )
{
	int len;
	char a[100];
	int count = 0;
	int i = 0, j = 0;
	while ( ans[i] != NULL )
	{
		if ( j == 75 )
		{
			if ( ans[i] != ' ' && ans[i] != NULL )
			{
				j--;
				i--;
				while ( a[j] != ' ' )
				{
					i--;
					j--;
				}
			}
			count = 0;
			
			a[j] = NULL;
			len = strlen(a);
			for ( j = 0; j < 75-len; j++ )
				printf(" ");
			printf("%s\n",a);
			i ++;
			j = 0;
		}
		else
		{
			a[j] = ans[i];
			j++;
			i++;
			count++;
		}
	}
	if ( count != 0 )
	{
		a[j] = NULL;
		len = strlen(a);
		for ( j = 0; j < 75-len; j++ )
			printf(" ");
		printf("%s\n",a);
	}
}

void printC ( )
{
	int len;
	char a[100];
	int count = 0;
	int i = 0, j = 0;
	while ( ans[i] != NULL )
	{
		if ( j == 75 )
		{
			if ( ans[i] != ' ' && ans[i] != NULL )
			{
				j--;
				i--;
				while ( a[j] != ' ' )
				{
					i--;
					j--;
				}
			}
			count = 0;
			
			a[j] = NULL;
			len = strlen(a);
			len = 75-len;
			for ( j = 0; j < len/2; j++ )
				printf(" ");
			printf("%s",a);
			for ( j = 0; j < (len+1)/2; j++ )
				printf(" ");
			printf("\n");
			i ++;
			j = 0;
		}
		else
		{
			a[j] = ans[i];
			j++;
			i++;
			count++;
		}
	}
	if ( count != 0 )
	{
		a[j] = NULL;
		len = strlen(a);
		len = 75-len;
		for ( j = 0; j < len/2; j++ )
			printf(" ");
		printf("%s",a);
		for ( j = 0; j < (len+1)/2; j++ )
			printf(" ");
		printf("\n");
	}
}

void printJ ( )
{
	int x,y,z;
	int len;
	char a[100];
	int count = 0;
	int i = 0, j = 0;
	int k;
	while ( ans[i] != NULL )
	{
		if ( j == 75 )
		{
			if ( ans[i] != ' ' && ans[i] != NULL )
			{
				j--;
				i--;
				while ( a[j] != ' ' )
				{
					i--;
					j--;
				}
			}
			a[j] = NULL;
			len = strlen(a);
			len = 75-len;
			j = 0;
			count = 1;
			while ( a[j] != NULL )
			{
				while ( a[j] != ' ' && a[j] != NULL)
				{
					j++;
				}
				if ( a[j] == ' ' )
					count++;
				j++;
			}
			x = len/count;
			y = len%count;
			for ( j = 0; a[j] != NULL;j++ )
			{

				printf("%c",a[j]);
				if ( a[j] == ' ' )
				{
					for ( k = 0; k < x; k++ )
						printf(" ");
					if ( y > 0 )
						printf(" ");
					y--;
				}
			}
			printf("\n");
/*			
			a[j] = NULL;
			len = strlen(a);
			for ( j = 0; j < 75-len; j++ )
				printf(" ");
			printf("%s\n",a);
			i ++;
*/			while ( ans[i] == ' ')
				i++;
			count = 0;
			j = 0;
		}
		else
		{
			a[j] = ans[i];
			j++;
			i++;
			count++;
		}
	}
	if ( count != 0 )
	{
		a[j] = NULL;
		printf("%s\n",a);
	}
}
int main ()
{
	int i;
//	fstream fin("file.in");
	char type;
	cin>>type;
	cin.ignore();
	char a[1000];
	while ( cin.getline(a,100,'\n') )
	{
		get(a);
	}
	i = 0;
	while ( ans[i] != NULL )
		i++;
	i--;
	while ( ans[i] == ' ' )
		i--;
	i++;
	ans[i] = NULL;
	if ( type == 'C')
		printC();
	else if ( type == 'R')
		printR();
	else if ( type == 'L')
		printL();
	else
		printJ();
	return 0;
}




/*
void L(char *a )
{
	int i = 0;
	int j = 0;
	while ( a[i] == ' ' )
		i++;
	while ( a[i] != NULL )
	{
		ans[j] = a[i];
		i++;
		j++;
	}
	ans[j] = NULL;
	printf("%s\n",ans);
}
void R(char *a )
{
	int i = 0;
	int j = 0;
	while ( a[i] != NULL )
	{
		ans[j] = a[i];
		i++;
		j++;
	}
	j--;
	while ( ans[j] == ' ' )
		j--;
	ans[j+1] = NULL;
	printf("%s\n",ans);
}
void C(char *a)
{
	int i,j=0;
	int len = 0;
	i = 0;
	while ( a[i] == ' ' )
		i++;
	while ( a[i] != NULL )
	{
		ans[j++] = a[i];
		i++;
		len++;
	}
	i--;
	while ( a[i] == ' ' )
	{
		a[i] = NULL;
		i--;
		len--;
	}
	len = 75-len;
	for ( i = 0; i < len/2; i++ )
		cout<<' ';
	printf("%s",ans);
//	for ( i = 0; i < (len+1)/2; i++ )
//		cout<<' ';
	cout<<endl;
}
void J ( char *a )
{
	int i,j;
	int begin;
	int word = 0;
	i = 0;
	while ( a[i] == ' ' )
		i++;
	while ( a[i] != NULL )
	{
		if ( a[i] == ' ' )
		{
			word++;
			while ( a[i] == ' ' )
				i++;
		}
		i++;
	}
	int len = 0;
	i = 0;
	while ( a[i] == ' ' )
		i++;
	begin = i;
	while ( a[i] != NULL )
	{
		i++;
		len++;
	}
	i--;
	while ( a[i] == ' ' )
	{
		i--;
		len--;
	}
	int base = (75-len)/word;
	int k = (75-len)%word;
	int num = 0;
	i = begin;
	j = 0;
	int ii;
	while ( j < 75 )
	{
		if ( a[i] == ' ' )
		{
			ans[j++] = ' ';
			num++;
			for ( ii = 0; ii < base; ii++ )
				ans[j++] = ' ';
			if ( num <= k )
				ans[j++] = ' ';
		}
		else
		{
			ans[j] = a[i];
			j++;
		}
		i++;
	}
	printf("%s\n",ans);
}
int main ()
{
	char a[10][100];
	memset(list,0,sizeof(list));
	char type;
	cin>>type;
	int i = 0;
	cin.ignore();
	while ( cin.getline(a[i],100,'\n') )
	{
		if ( type == 'L' )
			L(a[i]);
		else if ( type == 'R' )
			R(a[i]);
		else if ( type == 'C' )
			C(a[i]);
		else
			J(a[i]);
	}
	return 0;
}*/
//was to remember that distant afternoon when his father took him to discover
