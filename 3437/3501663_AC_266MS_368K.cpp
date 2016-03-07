#include <iostream>
using namespace std;
struct ac
{
	int left,right,father;
	int lay;
}acnode[12000];
char ch[32000];
void solve ()
{
	int i,p,q,num=1,x,f;
	for ( i = 0; i <= 10000; i++ )
		acnode[i].left = acnode[i].right = acnode[i].father = -1;
	acnode[0].lay = 0;
	q = p = 0;
	for ( i = 0; ch[i] != 0; i++ )
	{
		if ( ch[i] == 'd' )
			q++;
		else
			q--;
		if ( q > p )
			p = q;
	}
	printf("%d => ",p);
	x = p = 0;
	for ( i = 0; ch[i] != 0; i++ )
	{
		if ( ch[i] == 'd' )
		{
			if ( acnode[p].left == -1 )
			{
				acnode[p].left = num;
				acnode[num].father = p;
				acnode[num].lay = acnode[p].lay+1;
				if ( acnode[num].lay > x )
					x = acnode[num].lay;
				p = num;
				num++;
			}
			else
			{
				f = p;
				q = acnode[p].left;
				while ( acnode[q].right != -1 )
					q = acnode[q].right;
				acnode[q].right = num;
				acnode[num].father = f;
				acnode[num].lay = acnode[q].lay+1;
				if ( acnode[num].lay > x )
					x = acnode[num].lay;
				p = num;
				num++;
			}
		}
		else
		{
			p = acnode[p].father;
		}
	}
	printf("%d\n",x);
}
int main ()
{
	int it = 1;
	while ( scanf("%s",ch)!=EOF )
	{
		if ( ch[0] == '#' )
			break;
		printf("Tree %d: ",it++);
		solve();
	}
	return 0;
}