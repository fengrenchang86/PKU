#include <iostream>
using namespace std;
struct ac
{
	char x1[260],x2[260],y1[260],y2[260];
	int lx1,lx2,ly1,ly2;
	int v1,v2;
}t[3100];
int main ()
{
	int better ( char*, char* );
	int cmp ( char *a, char *b );
	int n,i,j;
	char ch[300];
	while ( cin>>n )
	{
		for ( i = 0; i < n; i++ )
		{
			cin>>ch;
			t[i].lx1 = better(ch,t[i].x1);
			cin>>ch;
			t[i].ly1 = better(ch,t[i].y1);
			cin>>ch;
			t[i].lx2 = better(ch,t[i].x2);
			cin>>ch;
			t[i].ly2 = better(ch,t[i].y2);
			t[i].v1 = t[i].v2 = 0;
		}
		for ( i = 0; i < n-1; i++ )
		{
			for ( j = i+1; j < n; j++ )
			{
				if ( t[i].lx1 == t[j].lx1 && t[i].ly1==t[j].ly1 )
				{
					if ( cmp(t[i].x1,t[j].x1)==1 && cmp(t[i].y1,t[j].y1)==1 )
					{
						t[i].v1++;
						t[j].v1++;
					}
				}
				if ( t[i].lx2 == t[j].lx1 && t[i].ly2 == t[j].ly1 )
				{
					if ( cmp(t[i].x2,t[j].x1)==1 && cmp(t[i].y2,t[j].y1)==1 )
					{
						t[i].v2++;
						t[j].v1++;
					}
				}
				if ( t[i].lx1 == t[j].lx2 && t[i].ly1 == t[j].ly2 )
				{
					if ( cmp(t[i].x1,t[j].x2)==1 && cmp(t[i].y1,t[j].y2)==1 )
					{
						t[i].v1++;
						t[j].v2++;
					}
				}
				if ( t[i].lx2==t[j].lx2 && t[i].ly2==t[j].ly2 )
				{
					if ( cmp(t[i].x2,t[j].x2)==1 && cmp(t[i].y2,t[j].y2)==1 )
					{
						t[i].v2++;
						t[j].v2++;
					}
				}
			}
		}
		for ( i = 0; i < n; i++ )
			{
				if ( t[i].v1 == 0 || t[i].v2 == 0 )
					break;
			}
			if ( i < n )
				cout<<0<<endl;
			else
				cout<<1<<endl;
	}
	return 0;
}
int better ( char *a, char *b )//delete the '0' before the string a then store it to sting *b
{
	int i = 0;
	while ( a[i] != NULL && a[i] == '0' )
		i++;
	int j = 0;
	while ( a[i] != NULL )
		b[j++] = a[i++];
	if ( j == 0 )
		b[j++] = '0';
	b[j] = NULL;
	return j;
}
int cmp ( char *a, char *b )
{//if the letter in string a complete equal the letter in string b, return 1, else return -1
	int i = 0;
	while ( a[i] != NULL )
	{
		if ( a[i] != b[i] )
			return -1;
		else if ( b[i] == NULL )
			return -1;
		i++;
	}
	if ( b[i] != NULL )
		return -1;
	return 1;
}