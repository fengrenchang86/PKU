#include <iostream>
using namespace std;
void print ( int list[], char *a, int l )
{
	int i;
	for ( i = 0; i < l; i++ )
		printf("%c",a[list[i]]);
	printf("\n");
}
int main ()
{
	char a[100];
	int t[26] = { 0 };
	int temp[20];
	int ct;
	int list[20];
	int i,j,k;
	int l,c;
	for ( i = 0; i < 20; i++ )
		list[i] = i;
	scanf("%d %d",&l,&c);
	cin.ignore();
	cin.getline(a,100,'\n');
	for ( j = 0; a[j] != NULL; j++ )
	{
		if ( a[j] >= 'a' && a[j] <= 'z' )
			t[a[j]-'a'] = 1;
	}
	for ( i = 0, j = 0; j < c; i++ )
	{
		if ( t[i] == 1 )
		{
			a[j++] = i+'a';
		}
	}
	while ( 1 )
	{
		if ( list[0] >= c - l )
			break;
		print(list,a,l);
		i = l - 1;
		list[l-1]++;
		while ( list[i] > c-l+i )
		{
			i--;
			if ( i < 0 )
				break;
			list[i]++;
		}
		for ( j = i; j < l; j++ )
			list[j+1] = list[j] + 1;
		print(list,a,l);
	}
	return 1;
}