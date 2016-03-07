#include <iostream>
#include <iomanip>
using namespace std;
const int max = 50;
/*
struct node 
{
	int key;
	node *next;
	node (int a)
	{
		key = a;
		next = NULL; 
	}
};
int insert  ( int a, int b, node *list[] )
{
	node *temp = new node(b);
	node *p = list[a];
	if ( p == NULL )
		list[a] = temp;
	else
	{
		while ( p->next != NULL )
			p = p->next;
		p->next = temp;
	}
	return 1;
}
int bianli ( node *list[],int t[] )
{
	int i = 0;
	node *p;
	while ( list[i] == NULL )
	{
		i++;
		if ( i > max )
			return 1;
	}
	p = list[i];
	while ( p != NULL )
	{
		if ( t[p->key] == 1 )
			return -1;
		t[p->key] = 1;
		p = p->next;
		if ( p == NULL )
		{
			i++;
			while ( list[i] == NULL )
			{
				i++;
				if ( i > max )
					break;
			}
			p = list[i];
		}
	}
}
int main ()
{
	int a,b;
	int count = 1;
	bool yes = true;
	int i,j;
	int t[max]={0};
	short c[max+1][max+1]={0};
	node *list[max] = { NULL };
	while ( scanf("%d %d",&a,&b) && !(a==-1&&b==-1) )
	{
		if ( a==0 && b== 0 )
		{
			if ( yes == true )
				printf("Case %d is a tree.\n",count++);
			else
				printf("Case %d is not a tree.\n",count++);
			yes = true;
			for ( i = 0; i < max; i++ )
			{
				list[i] = NULL; 
				t[i] = 0 ;
			}
			for ( i = 0; i < max; i++ )
			{
				for ( j = 0; j < max; j++ )
					c[i][j] = 0;
			}
			continue;
		}
		if  ( yes == false )
			continue;
		c[a][b] = 1;
		if ( a == b )
		{
			yes = false;
			continue;
		}
		if ( c[b][a] == 1 )
		{
			yes = false;
			continue;
		}
		insert(a,b,list);
	}
	return 1;
}
*/
bool go ( int c[][max], int v[], int l, int &root,int large)
{
	bool yes = true;
	int i;
	int j;
	int k;
	int count = 0;
	j = 0;
	int g[max] = { 0 };
	short h[max*max] = { 0 };
	for ( k = 0; k < l; k++ )	//	把根找出来！
	{
		count = 0;
		for ( i = 1; i < large; i++ )
		{
			if ( c[i][v[k]] == 1 ) //不是根
			{
				count = -1;
				break;
			}
		}
		if ( count != -1 )
		{
			j++;
			root = v[k];
	//		printf("the root is %d.\n",root);
			if ( j >= 2 )
				return false;
		}
	}
	int start = 0;
	int end = 1;
	count = 1;
	i = 0;
	j = 1;
	h[0] = root;
	g[root] = 1;
	k = 0;
	while ( k < end )
	{
		k = i;
		i = end;
		for (; k <= i; k++ )
		{
			for ( j = 0; j < large; j++ )
			{
				if ( c[h[k]][j] == 1 )
				{
					if ( g[j] == 0 )
					{
						g[j] = 1;
						h[end++] = j;
					}
					else
						return false;
				}
			}
		}
	}
	return true;
}
int main ()
{
	int a,b;
	int root;
	int large=0,l = 0;
	int count = 1;
	bool yes = true;
	int i,j;
	int c[max][max];
	for ( i =0; i < max; i++ )
		for ( j = 0;j < max;j ++ )
			c[i][j] = 0;
	int t[max] = { 0 };
	int r[max] = { 0 };
	int v[max] = { 0 };
	while ( scanf("%d %d",&a,&b) && !(a==-1&&b==-1) )
	{
		if ( a == 0 && b == 0 )
		{
			if( yes == true )
				yes = go ( c,v,l,root,large);
			if ( yes == true )
				printf("Case %d is a tree.\n",count++);
			else
				printf("Case %d is not a tree.\n",count++);
			yes = true;
	//		for ( i = 1; i < max; i++ )
	//		{
	//			for ( j = 1; j < max; j++ )
	//			{
	//				cout<<setw(4)<<c[i][j];
	//			}
	//			cout<<endl;
	//		}
	//		printf("the max is %d\n",large);
			for ( i = 0; i < max; i++ )
			{
				for ( j = 0; j < max; j++ )
					c[i][j] = 0;
			}
			large = 0;
			l = 0;
	//		printf("these are the point:\n");
	//		for ( i = 0; i < l; i++ )
	//			printf("%d ",v[i]);
	//		cout<<endl;
			for ( i = 0; i < max; i++ )
				v[i] = t[i] = r[i] = 0;
			continue;
		}
		r[b]++;
		if ( yes == false )
			continue;
		if  ( a == b )		//指向自己本身，不属于树
		{
			yes = false;
			continue;
		}
		if ( c[a][b] == 1 || c[b][a] ==1 )		//指向父亲，不属于树
		{
			yes = false;
			continue;
		}
		else
			c[a][b] = 1;
		if ( r[b] == 2 )		//2个指向一个，不属于数
		{
			yes = false;
			continue;
		}
		if ( a > large )	//求顶点的最大值
			large = a;
		if ( b > large )
			large = b;
		if ( t[a] == 0 )
		{
			v[l++] = a;
			t[a] = 1;
		}
		if ( t[b] == 0 )
		{
			v[l++] = b;
			t[b] = 1;
		}
		c[a][b] = 1;
	}
	return 1;
}