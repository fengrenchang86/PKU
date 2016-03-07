#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct ac
{
	int lay;
	char ch;	//0,1,2
	ac*father;
	ac*na, *nb, *nc;
}*pHead, *ans;
stack<ac*>zhan;
vector<char>vec;
int n;
bool flag;
int m = 0;
bool check(ac *p)
{
	ac *x, *y, *q;
	if (p == pHead)
	{
		return true;
	}
	y = p->father;
	q = y;
	while (q->lay * 2 >= p->lay)
	{
		x = p;
		y = q;
		while (x->ch == y->ch)
		{
			x = x->father;
			y = y->father;
			if (y == pHead || x == q)
			{
				return false;
			}
		}
		q = q->father;
		if (q == pHead)
		{
			return true;
		}
	}
	return true;
}
void acm(ac*p, ac*father, char ch, int lay)
{
	p->father = father;
	p->ch = ch;
	p->lay = lay;
}
void dfs()
{
	ac *p;
	zhan.push(pHead);
	while (!zhan.empty())
	{
		p = zhan.top();
		zhan.pop();
		if (p->lay >= n)
		{
			ans = p;
			return;
		}
		p->na = new ac;
		p->nb = new ac;
		p->nc = new ac;
		acm(p->na, p, 0, p->lay + 1);
		acm(p->nb, p, 1, p->lay + 1);
		acm(p->nc, p, 2, p->lay + 1);
		if (check(p->na))
		{
			zhan.push(p->na);
		}
		if (check(p->nb))
		{
			zhan.push(p->nb);
		}
		if (check(p->nc))
		{
			zhan.push(p->nc);
		}
	}	
}
void Make()
{
	flag = false;
	pHead = new ac;
	pHead->father = NULL;
	pHead->lay = 0;
	pHead->na = NULL;
	pHead->nb = NULL;
	pHead->nc = NULL;
	dfs();
}
int main()
{
	n = 5000;
	Make();
	vec.clear();
	ac *p = ans;
	while (p != pHead)
	{
		if (p->ch == 0)
			vec.push_back('P');
		else if (p->ch == 1)
			vec.push_back('O');
		else
			vec.push_back('N');
		p = p->father;
	}
	int i, j;
	while (scanf("%d", &n) && n != 0)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c", vec[4999-j]);
		}
		printf("\n");
	}
	return 0;
}