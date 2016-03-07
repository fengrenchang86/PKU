#include <iostream>
#include <queue>
using namespace std;
struct ac
{
	int pos;
	int val;
	bool operator()(const ac&m1, const ac& m2)
	{
		if ( m1.val != m2.val )
			return m1.val < m2.val;
		else
			return m1.pos > m2.pos;
	}
};
struct HUI
{
	int next;
	int father;
	int back;
	int val;
	char c;
	HUI(){next=-1;back=-1;back=-1; }
}a[1100000];
priority_queue<ac,vector<ac>,ac>que;
char ch[1200000];
int next[1200000];
int len;
void init ()
{
	int i,j;
	ac p;
	scanf(" %s",ch);
	len = strlen(ch);
	j = len-1;
	a[j].next = -1;
	a[j].val = 1;
	a[j].c = ch[j];
	j = 1;
	for ( i = len-1; i >= 0; i-- )
	{
		a[i].next = i+1;
		a[i].c = ch[i];
		a[i].val = j;
		if ( ch[i] == ch[i+1] )
			j++;
		else
		{
			a[i+1].val = j;
			a[i+1].back = i;
			a[i+j].father = i+1;
			next[i+1] = i+j;
			p.val = j;
			p.pos = i+1;
			que.push(p);
			j = 1;
		}
	}
	a[0].c = ch[0];
	a[0].val = j;
	a[0].next = 1;
	a[1].back = 0;
	a[j-1].father = 0;
	next[0] = j-1;
	p.val = j;
	p.pos = 0;
	que.push(p);
}

void solve ()
{
	ac p;
	int i,k;
	int m = 0;
	while ( !que.empty() && m < len-1 )
	{
		p = que.top();
		que.pop();
		if ( a[p.pos].val == -1 )
			break;
		k = p.pos;
		printf("%c",a[k].c);
		for ( i = k; ; )
		{
			printf(" %d",i+1);
			m++;
			a[i].val = -1;
			i = a[i].next;
			if ( i == -1 )
				break;
			if ( a[i].c != a[k].c )
				break;
		}
		k = a[k].back;
		if ( k != -1)
			a[k].next = i;
		if ( i == -1 )
			continue;
		if ( k != -1 && a[k].c == a[i].c )
		{
			k = a[k].father;
			a[k].val += a[i].val;
			next[k] = next[i];
			a[next[i]].father = k;
			p.pos = k;
			p.val = a[k].val;
			que.push(p);
		}
		else if ( k == -1 )
		{
			a[i].back = -1;
		}
		printf("\n");
	}
}
int main ()
{
	init();
	solve();
	return 0;
}