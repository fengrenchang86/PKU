
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

void insert(char *a,char *b)//a--->boss
{
   int i = 0;
   int f1=-1;
   for( i; i < end; i++)
   {
	   if(strcmp(List[i].name,a) == 0)
	   {
         f1 = i;
		 break;
	   }
   }
   if(f1 == -1)
   {
	   f1 = end;
	   end++;
   }
   strcpy(List[f1].name,a);
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

void ok(char *ch)
{
   int t = fine(ch);
   visited[t] = 0;
				node *p = new node;
				p = List[t].next;
				while(p)
				{
				int  m = fine(p->name);
				if(!visited[m])
				{
					p=p->next;
					continue;
				}
				if(visited[m])
					ok(p->name);
					int temp;
		        temp = f[m][0] > f[m][1] ? f[m][0] : f[m][1];
		        f[t][0] += temp;
	          	f[t][1] += f[m][0];
				if ( f[m][0] == f[m][1] )
					g[t][0] = 0;
				if(f[m][0] > f[m][1] && !g[m][0])
                   g[t][0] = 0;
				if(f[m][1] > f[m][0] && !g[m][1])
					g[t][0] = 0;
				if(!g[m][0]) 
				  g[t][1] = 0;
				p = p->next;
			
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
         	insert(ch1,ch2);

		}
        for(i = 0; i < end; i++)
		{
				f[i][0] = 0;
				f[i][1] = 1;
				g[i][0] = g[i][1] = 1;

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