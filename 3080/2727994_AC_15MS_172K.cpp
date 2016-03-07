#include <iostream>
#include <string>
using namespace std;
bool f ( char *a, char *b )
{
	int i,j;
	for ( i = 0; a[i] != NULL; i++)
	{
		for ( j = 0; a[i+j] != NULL && b[j] != NULL;j++ )
		{
			if ( a[i+j] != b[j] )
				break;
		}
		if ( b[j] == NULL )
			return true;
	}
	return false;
}
int main ()
{
	int tcase,n,i,j,k;
	bool find;
	int len;
	int end;
	int temp,v;
	char t[100];
	char ch[100];
	char a[20][100];
	cin>>tcase;
	while ( tcase-- )
	{
		scanf("%d",&n);
		bool find = false;
		for ( i = 0; i < n; i++ )
			scanf("%s",&a[i]);
		end = strlen(a[0]);
		for ( i = 0; i < end-1; i++ )
		{
			ch[0] = a[0][i];
			ch[1] = a[0][i+1];
			v = 2;
			for ( j = i+2; j < end; j++ )
			{
				ch[v] = a[0][i+v];
				v++;
				ch[v] = NULL;
				for ( k = 1; k < n; k++ )
				{
					if ( f(a[k],ch)==false)
						break;
				}
				if ( k != n )
					continue;
				temp = strlen(ch);
				if ( find == false )
				{
					len = temp;
					strcpy(t,ch);
					find = true;
				}
				else if ( temp > len || temp==len && strcpy(t,ch)>0 )
				{
					strcpy(t,ch);
					len = temp;
				}
			}
		}
		if ( find == true )
			printf("%s\n",t);
		else
			printf("no significant commonalities\n");
	}
	return 0;
}