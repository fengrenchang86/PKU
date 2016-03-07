#include <iostream>
using namespace std;
struct ac
{
	int id;
	int width;
	ac *next, *back;
}*pList[120], *pHead;
int W;
void Remove(int nId)
{
	ac *p;
	if (pList[nId] == NULL)
	{
		return;
	}
	else if (pList[nId] == pHead)
	{
		p = pHead;
		pHead = pHead->next;
		delete p;
		if (pHead != NULL)
		{
			pHead->back = NULL;
		}
	}
	else
	{
		p = pList[nId];
		p->back->next = p->next;
		if (p->next != NULL)
		{
			p->next->back = p->back;
		}
		
		delete p;
	}
	pList[nId] = NULL;
}
void Add(int nId, int nWidth)
{
	if (pList[nId] != NULL)
	{
		Remove(nId);
	}
	ac *p = new ac;
	pList[nId] = p;
	p->id = nId;
	p->width = nWidth;
	p->next = pHead;
	p->back = NULL;
	if (pHead != NULL)
	{
		pHead->back = p;
	}
	pHead = p;
}
void Solve(int tc)
{
	char ch;
	int id, width;
	pHead = NULL;
	int i;
	for (i = 0; i <= 100; i++)
	{
		pList[i] = NULL;
	}
	while (scanf(" %c", &ch) != EOF)
	{
		if (ch == 'R')
		{
			scanf("%d", &id);
			Remove(id);
		}
		else if (ch == 'A')
		{
			scanf("%d %d", &id, &width);
			Add(id, width);
			ac *p = pHead;
			i = 0;
			while (p != NULL)
			{
				i += p->width;
				if (i > W)
				{
					break;
				}
				p = p->next;
			}
			ac *q;
			while (p != NULL)
			{
				q = p->next;
				Remove(p->id);
				p = q;
			}
		}
		else
		{
			ac *p = pHead;
			i = 0;
			printf("PROBLEM %d:", tc);
			while (p != NULL)
			{
				i += p->width;
				if (i > W)
				{
					break;
				}
				printf(" %d", p->id);
				p = p->next;
			}
			printf("\n");
			break;
		}
	}
}
int main()
{
	int tc = 1;
	while (scanf("%d", &W) != EOF)
	{
		if (W == -1)
		{
			break;
		}
		Solve(tc++);
	}
	return 0;
}