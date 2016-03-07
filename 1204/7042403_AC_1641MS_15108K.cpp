#include <iostream>
using namespace std;
char szNameTable[1020][1020];
struct ac
{
	int x, y;
	char ch;
}v[1200];
int m, n, t;
int dir[][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int nFinal = 0;
struct TRIENODE
{
	TRIENODE(){
		int i;
		for (i = 0; i < 26; i++)
		{
			pChild[i] = NULL;
		}
		pFather = NULL;
		data = -1;
		nSonCount = 0;
	}
	TRIENODE *pFather;
	TRIENODE *pChild[26];
	int data;
	int nSonCount;
};
class TrieTree
{
public:
	TrieTree(){
		pRoot = new TRIENODE;
		m_nInsertCount = 0;
	}
	TRIENODE *pRoot;
	int m_nInsertCount;
	int Search(char* pStr);
	int Search(int x, int y, int nDir);
	void Insert(char *pStr);
};
int TrieTree::Search(int x, int y, int nDir)
{
	int tx = x;
	int ty = y;
	TRIENODE *p = pRoot;
	char ch;
	while (x >= 0 && x < n && y >= 0 && y < m && p != 0)
	{
		if (p->nSonCount == 0)
		{
			return 0;
		}
		ch = szNameTable[x][y] - 'A';
		if (p->pChild[ch] == NULL)
		{
			return 0;
		}
		p = p->pChild[ch];
		if (p->data > 0)
		{
			int x = p->data;
			p->data = -2;
			v[x].x = tx;
			v[x].y = ty;
			v[x].ch = nDir + 'A';
			nFinal++;
		}
		x += dir[nDir][0];
		y += dir[nDir][1];
	}
	int g = 0;
	while (p != pRoot)
	{
		if (p->data == -2)
		{
			g++;
		}
		p->nSonCount -= g;
		p = p->pFather;
	}
	return 0;
}
void TrieTree::Insert(char *pStr)
{
	TRIENODE *p = pRoot;
	char *q = pStr;
	char ch;
	while (*q != NULL)
	{
		if (*pStr >= 'A' && *q <= 'Z')
		{
			ch = *q - 'A';
		}
		else if (*pStr >= 'a' && *q <= 'z')
		{
			ch = *q - 'a';
		}
		else
			return;
		p->nSonCount++;
		if (p->pChild[ch] == NULL)
		{
			p->pChild[ch] = new TRIENODE;
			p->pChild[ch]->pFather = p;
		}
		p = p->pChild[ch];
		q++;
	}
	p->data = ++m_nInsertCount;
}

int TrieTree::Search(char* pStr)
{
	TRIENODE *p = pRoot;
	char *q = pStr;
	char ch;
	while (*q != NULL)
	{
		if (*q >= 'A' && *q <= 'Z')
		{
			ch = *q - 'A';
		}
		else if (*q >= 'a' && *q <= 'z')
		{
			ch = *q - 'a';
		}
		else
			return 0;
		if (p->pChild[ch] == NULL)
		{
			return 0;
		}
		p = p->pChild[ch];
		if (p->data > 0)
		{
			int x = p->data;
			p->data = -1;
			return x;
		}
		q++;
	}
	return 0;
}

void Make(int nDir, int x, int y, char *p)
{
	int i = 0;
	while (x >= 0 && x < n && y >= 0 && y < m)
	{
		p[i++] = szNameTable[x][y];
		x += dir[nDir][0];
		y += dir[nDir][1];
	}
	p[i] = NULL;
}
int main()
{
	int i, j, k, l, ans = 0;
	char ch;
	char dis[1200];
	//	freopen("e:\\stdin.txt", "r", stdin);
	//	freopen("e:\\out.txt", "w", stdout);
	while (scanf("%d %d %d", &n, &m, &t) != EOF)
		//	n = m = t = 1000;
	{
		l = t;
		nFinal = 0;
		TrieTree tree;
		for (i = 0; i < n; i++)
		{
			scanf(" %s", &szNameTable[i]);
		}
		//		freopen("e:\\stdout.txt", "r", stdin);
		for (i = 0; i < t; i++)
		{
			scanf(" %s", dis);
			tree.Insert(dis);
		}
		for (i = 0; i < n && nFinal < t; i++)
		{
			for (j = 0; j < m && nFinal < t; j++)
			{
				for (k = 0; k < 8 && nFinal < t; k++)
				{
					//				Make(k, i, j, dis);
					//				ans = tree.Search(dis);
					tree.Search(i, j, k);
				}
			}
		}
		for (i = 1; i <= t; i++)
		{
			printf("%d %d %c\n", v[i].x, v[i].y, v[i].ch);
		}
	}
	return 0;
}