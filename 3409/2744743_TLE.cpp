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
	int n,i,j,k=0;
	char ch[300];
	int t1,t2,t3,t4;
	while ( cin>>n )
	{
		i  = 0;
		for ( k = 0; k < n; k++ )
		{
			cin>>ch;
			t[i].lx1 = better(ch,t[i].x1);
			cin>>ch;
			t[i].ly1 = better(ch,t[i].y1);
			cin>>ch;
			t[i].lx2 = better(ch,t[i].x2);
			cin>>ch;
			t[i].ly2 = better(ch,t[i].y2);
			t[i].v1 = t[i].v2 = 1;
			for ( j = 0; j < k; j++ )
			{
				t1 = t2 = t3 = t4 = 1;
				if ( t[i].lx1 == t[j].lx1 && t[i].ly1==t[j].ly1 )
				{
					if ( cmp(t[i].x1,t[j].x1)==1 && cmp(t[i].y1,t[j].y1)==1 )
					{
						t[i].v1++;
						t[j].v1++;
						t1 = 0;
					}
				}
				if ( t[i].lx2 == t[j].lx1 && t[i].ly2 == t[j].ly1 )
				{
					if ( cmp(t[i].x2,t[j].x1)==1 && cmp(t[i].y2,t[j].y1)==1 )
					{
						t[i].v2++;
						t[j].v1++;
						t2 = 0;
					}
				}
				if ( t[i].lx1 == t[j].lx2 && t[i].ly1 == t[j].ly2 )
				{
					if ( cmp(t[i].x1,t[j].x2)==1 && cmp(t[i].y1,t[j].y2)==1 )
					{
						t[i].v1++;
						t[j].v2++;
						t3= 0;
					}
				}
				if ( t[i].lx2==t[j].lx2 && t[i].ly2==t[j].ly2 )
				{
					if ( cmp(t[i].x2,t[j].x2)==1 && cmp(t[i].y2,t[j].y2)==1 )
					{
						t[i].v2++;
						t[j].v2++;
						t4 = 0;
					}
				}
				if ( t1 == 0 && t4 == 0 || t2 == 0 && t3==0)
				{
					t[j].v1--;
					t[j].v2--;
					break;
				}
			}
			if ( j == k )
				i++;
		}
		n = i;
		for ( i = 0; i < n; i++ )
			{
				if ( t[i].v1 % 2 == 1 || t[i].v2 % 2 == 1 )
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