#include <iostream>
using namespace std;
const short max = 4000;
int a[max];
struct node
{
	int v;
	int dis;
	node *next;
	node()
	{dis = 65534; next = NULL; }
}*table[max],*list[max*max];
void insert ( int x, int y, int distance )
{
	node *p = new node;
	if ( table[x] == NULL )
	{
		p->v = y;
		p->dis = distance;
		table[x] = p;
	}
	else
	{
		node *q = table[x];
		while ( q != NULL )
		{
			if ( q->v == y )
			{
				if ( q->dis > distance )
					q->dis = distance;
				return;
			}
			q = q->next;
		}
		q = table[x];
		if ( q->dis > distance )
		{
			p->next = q;
			table[x] = p;
			p->v = y;
			p->dis = distance;
			return ;
		}
		while ( q->next != NULL )
		{
			if ( q->next->dis > distance )
				break;
			q = q->next;
		}
		p->next = q->next;
		q->next = p;
		p->v = y;
		p->dis = distance;
	}
}
int up ( int arr[], int position, int x )
{
	int i = position;
	while ( i > 1 )
	{
		if ( arr[a[i/2]] > arr[x] )
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else
			break;
	}
	return i;
}
void SmallHeapInsert ( int arr[], int& CurrentSize, int x)
{
	int i = up(arr,CurrentSize,x);
	a[i] = x;
	CurrentSize++;
}
int SmallDel ( int arr[], int& CurrentSize )
{
	CurrentSize--;
	int result = a[1];
	int item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && arr[a[i]] > arr[a[i+1]] )
			i++;
		if ( arr[item] <= arr[a[i]] )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
	return result;
}

int main ()
{
	int t,n;
	int CurrentSize=1;
	int min = 65534;
	int position=0;
	int pos = 0;
	int it;
	int i,j;
	int arr[max];
	int X[max] = {0};
	int Y[max] = {0};
	int x,y,distance;
	cin>>t>>n;
	for ( i = 0; i <= n; i++ )
	{
		table[i] = NULL;
		arr[i] = 65534;
		Y[i] = 0;
		X[i] = 0;
	}
	Y[1] = 1;
	X[1] = 1;
	for ( it = 0; it < t; it++ )
	{
		scanf("%d%d%d",&x,&y,&distance);
		insert(x,y,distance);
		insert(y,x,distance);
	}
	node *p = table[1];
	while ( p != NULL )
	{
		arr[p->v] = p->dis;
		list[position++] = p;
		p = p->next;
	}
	int begin = 0;
	for ( j = 1; j <= n-1; j++ )
	{
		min = 65534;
		for ( i = begin; i < position; i++ )
		{
			if ( list[i] != NULL )
			{
				if ( arr[list[i]->v] < min )
				{
					min = arr[list[i]->v];
					pos = i;
				}
			}
		}
		Y[list[pos]->v] = 1;
		p = table[list[pos]->v];
		begin = pos;
		pos = list[pos]->v;
		list[begin] = NULL;
		begin = 0;
		while ( p != NULL )
		{
			if ( Y[p->v] == 0 )
			{
	//			arr[p->v] = p->dis;
	//			X[p->v] = 1;
				list[position++] = p;
		
			if ( Y[p->v] == 0 && arr[pos]+p->dis < arr[p->v] )
				arr[p->v] = arr[pos]+p->dis;
	//		Y[p->v] = 1;
			}
			p = p->next;
		}
	}
	cout<<arr[n]<<endl;
	return 0;
}


/*
int current = 1;
struct ac
{
	int v;
	int dis;
	int next;
	ac()
	{next = -1;dis = 65534;}
}node[max],table[max];
void insert ( int x, int y, int distance )
{
	if ( table[x].next == -1 )
	{
		table[x].next = current;
		node[current].v = y;
		node[current].dis = distance;
		current++;
	}
	else
	{
		int p = table[x].next;
		if ( node[p].v == y )
		{
			if ( node[p].dis > distance )
				node[p].dis = distance;
			return;
		}
		while ( node[p].next != -1 )
		{
			if ( node[p].v != y )
				p = node[p].next;
			else
			{
				if ( node[p].dis > distance )
					node[p].dis = distance;
				break;
			}
		}
		p = table[x].next;
		if ( distance < node[p].dis )
		{
			node[current].next = table[x].next;
			table[x].next = current;
			node[current].v = y;
			node[current].dis = distance;
			current++;
		}
		else
		{
			while ( node[p].next != -1 )
			{
				p = node[p].next;
				if ( node[p].dis > distance )
					break;
			}
			node[current].next = node[p].next;
			node[current].dis = distance;
			node[current].v = y;
			node[p].next = current;
			current++;
		}
	}
}

*/