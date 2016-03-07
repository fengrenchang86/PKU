#include <iostream>
#include <iomanip>
using namespace std;
const int max = 50;
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
			if( yes == true && l != 0)
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