
#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	char name[200];

    node *next;   
}List[300];
    int end;
	int f[300][5];
	int g[300][5];
	int visited[300];
	int visit[300];
void insert(char *a,char *b)//a--->boss
{
   int i = 0;
   int j = 0;
   int f1,f2;
   int flag1 = 0, flag2 = 0;
   for( i; i < end; i++)
   {
	   if(strcmp(List[i].name,a) == 0)
	   {
         f1 = i;
		 flag1 = 1;
	   }
	   if(strcmp(List[i].name,b) == 0)
	   {
         f2 = i;
		 flag2 = 1;
	   }
	   if( flag1 && flag2 )
	    break;
   }
   if(!flag1)
   {
	   f1 = end;
	   end++;
   }
   if(!flag2)
   {
	   f2 = end;
	   end++;
   }
   strcpy(List[f1].name,a);
   strcpy(List[f2].name,b);
   node *tem = new node;
   strcpy(tem->name,b);
   tem->next = List[f1].next;
   List[f1].next = tem;
}
void init()
{
   end = 0;
   int i;
   for( i = 0; i < 300; i++)
   {
	   List[i].next = NULL;
       visit[i] = 1;
	   visited[i] = 1;
   }
}
int fine(char *ch)
{
	
	int i;
	for( i = 0; i < end; i++ )
	{
		if(strcmp(List[i].name,ch)==0)
			break;
	}
	return i;
}
void getOrder(char *ch)
{
   int t = fine(ch);
   visit[t] = 0;
   node *p = new node;
   p = List[t].next;
   while(p)
   {
	   int tem = fine(p->name);
	   if(visit[tem])
		   getOrder(p->name);
	   p = p->next;
   }
}
void ok(char *ch)
{
   int t = fine(ch);
   visited[t] = 0;
			if(List[t].next == NULL)
			{
				f[t][0] = 0;
				f[t][1] = 1;
				g[t][0] = g[t][1] = 1;
			}
			else
			{
				node *p = new node;
				p = List[t].next;
				while(p)
				{
				int  m = fine(p->name);
				if(visited[m])
					ok(p->name);
			//	else //0-->不去
			//	{
					int temp;
		        temp = f[m][0] > f[m][1] ? f[m][0] : f[m][1];
		        f[t][0] += temp;
	          	f[t][1] += f[m][0];
				if(f[m][0] == f[m][1])
				  g[t][0] = 0; //初始化为1
                if (f[m][0] > f[m][1] && g[m][0] == 0 )
					g[t][0] = 0;
				if( f[m][0] < f[m][1] && g[m][1] == 0 )
					g[t][0] = 0;
				if ( g[m][0] == 0 )
					f[m][1] = 0;

			//	}
				p = p->next;
			
				}
			}
}
int main()
{
	int n;
	char boss[120];
	char ch1[120],ch2[120];
	int i,j;

    while(cin>>n)
	{
		if(n==0)
			break;
         init();
        cin>>boss;
		for( i = 1; i < n; i++)
		{
			cin>>ch1>>ch2;
			insert(ch2,ch1);
	//		insert(ch1,ch2);

		}
        for(i = 0; i < end; i++)
		{
				f[i][0] = 0;
				f[i][1] = 1;
				g[i][0] = g[i][1] = 1;

		}
		getOrder(boss);
		for(i = 0; i < end; i++)
		{
			if(visit[i])
			{
				node *p = new node;
				node *pre = new node;
				pre = p = List[i].next;
				while(p)
				{
					j = fine(p->name);
					if(!visit[j])
					{
						insert(List[j].name,List[i].name);
						if(p==pre)
							List[i].next = p->next;
						else
							pre->next = p->next;
						delete p;
                        break;
					}
					pre = p;
					p = p->next;
				}
			}
		}
		ok(boss);
		j = fine(boss);
		if(f[j][0] > f[j][1] && g[j][0])
		cout<<f[j][0]<<" "<<"Yes";
		else if(f[j][0] > f[j][1] && !g[j][0])
		cout<<f[j][0]<<" "<<"No";
         else if(f[j][1] > f[j][0] && g[j][1])
			 cout<<f[j][1]<<" "<<"Yes";
		 else if(f[j][1] > f[j][0] && !g[j][1])
			 cout<<f[j][1]<<" "<<"No";
		 else if(f[j][0] == f[j][1])
			 cout<<f[j][1]<<" "<<"No";
         cout<<endl; 
		

	}
	return 0;

}
/*

#include <iostream>
#include <string>
using namespace std;
struct wf
{
	char name[120];
	wf *next;
}list[300];
bool visit[300];
int end;
bool unique;
void insert ( char *a, char *b )
{
	int i;
	for ( i = 0; i < end; i++ )
	{
		if (strcmp(b,list[i].name)==0)
			break;
	}
	if ( i == end )
	{
		strcpy(list[end].name,b);
		end++;
	}
	wf *p = new wf;
	strcpy(p->name,a);
	p->next = list[i].next;
	list[i].next = p;
}
int max;
int count;
void init()
{
	end = 0;
	max = 0;
	unique = true;
	for ( int i = 0; i < 300; i++ )
	{
		list[i].next = NULL;
		visit[i] = false;
	}
}
int find ( char *a )
{
	int i;
	for ( i = 0; i < end; i++ )
	{
		if ( strcmp(a,list[i].name) ==0 )
			break;
	}
	return i;
}
void dfs ( int node, int &x, int &y, int &wx, int &wy )
{
	visit[node] = true;
	int t,tx=0,ty=0;
	int unix,uniy;
	x = 0;
	y = 1;
	wx = wy = 0;
	wf *p = list[node].next;
	while ( p != NULL )
	{
		t = find(p->name);
		if ( visit[t] == true )
		{
			p = p->next;
			continue;
		}
		dfs(t,tx,ty,unix,uniy);
		if ( tx == ty )
			wx = 1;
		if ( tx > ty && unix == 1 )
			wx = 1;
		else if ( ty > tx && uniy == 1 )
			wy = 1;
		if ( unix == 1 )
			wy = 1;
		if ( x == 0 )
		{
			if ( x + tx>ty?tx:ty > max )
				max = x+tx>ty?tx:ty;
		}
		x += tx>ty?tx:ty;
		if ( x > max )
			max = x;
		y += tx;
		p = p->next;
		if ( y > max )
			max = y;
	}
	if ( y < 1 )
	{
		y = 1;
		wx = 0;
		wy = 0;
	}
}
int main ()
{
 	int n,i,x,y,wx,wy;
	char boss[120];
	char cha[120],chb[120];
	while ( cin>>n && n!=0 )
	{
		cin>>boss;
		if ( n == 1 )
		{
			cout<<"1 Yes"<<endl;
			continue;
		}
		init();
		x = 0;
		y = 0;
		for ( i = 0; i < n-1; i++ )
		{
			cin>>cha>>chb;
			insert(cha,chb);
			insert(chb,cha);
		}
		dfs(find(boss),x,y,wx,wy);
		cout<<max<<" ";
//		cout<<wx<<" "<<wy<<" ";
		if ( x == y )
			cout<<"No"<<endl;
		else if ( x > y && wx == 1 )
			cout<<"No"<<endl;
		else if ( x < y && wy == 1 )
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}
*/