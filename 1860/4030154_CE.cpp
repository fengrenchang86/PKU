#include<iostream>
using namespace std;
#define N 110
#define ACM 1e-8
const double inf = 20000000000000.000;

double dis[N];
int n, beginP;
double beginMoney;
struct ac
{
	int v;
	double r, c;
	ac *next;
}*list[N];

void init()
{
	int i;
	for(i = 0; i < n; i++)
		list[i] = NULL;
}
void insert(int x, int y, double r, double c)
{
	ac *p = new ac;
	p->c = c;
	p->r = r;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
bool BellmanFord()
{
	ac *p;
	bool tag;
	double temp;
	int i;
	for(i = 0; i <= n; i++)
	{
		dis[i] = 0.0;
	}
	dis[beginP] = beginMoney;
/*
	for(j = 0; j < n; j++)
	{
		k = -1;
		for(i = 0; i < n; i++)
		{
			if(!visit[i] && (k == -1 || dis[i] < dis[k]))
				k = i;
		}
		visit[k] = true;
		for(i = 0; i < n; i++)
		{
			temp = (dis[k] - c[k][i]) * r[k][i];
			if(!visit[i] && temp - dis[i] >= ACM)
				dis[i] = temp;
		}
	}
	*/
	tag = true;
	while(tag)
	{
		tag = false;
		for(i = 0; i < n; i++)
		{
			if(dis[i] < ACM)
				continue;
			p = list[i];
			while(p != NULL)
			{
				temp = (dis[i] - p->c) * p->r;
				if(temp - dis[p->v] >= ACM)
				{
					dis[p->v] = temp;
					tag = true;
				}
				p = p->next;
			}
		}
		if(dis[beginP] - beginMoney >= ACM)
			return true;