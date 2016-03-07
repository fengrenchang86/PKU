
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int* visited;
bool flag;
struct clothes
{
	int time;
	char ch[100];
};
int cmp ( const void *a , const void *b ) 
{
    return strcmp( (*(clothes *)a).ch , (*(clothes *)b).ch ); 
} 
int cmp2 ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
 /* -----    DP ----------
int gettime(clothes st[],int first,int end)
{
	int v[100][1000000];
	int n = end - first;
    int* a = new int[n];
	int i,j,sum,div,tem;
	i = first;
	j = 1;
	sum = 0;
	tem = 0;
	while(i < end)
	{
      a[j] = st[i].time;
	  sum += st[i].time;
	  j++;
	  i++;
	}
	div = sum/2;      //sum为时间总和
	qsort(a,n,sizeof(int),cmp2);
	for(i = 0; i <= div; i++)
		v[i][0] = 0;
	 for(j = 0; j <= n; j++)
		 v[0][j] = 0;
	 for(i = 1; i <= n; i++)
		 for(j = 1; j <= div; j++)
		 {
			 v[i][j] = v[i-1][j];
			 if(j >= a[i] && v[i-1][j-a[i]]+a[i] <= div)
			 {
				tem = v[i][j] = v[i][j] > (v[i-1][j-a[i]]+a[i]) ? v[i][j] : (v[i-1][j-a[i]]+a[i]);
                    
			 }
		 }
		 tem = tem > (sum - tem) ? tem : (sum - tem);
    return tem;
}
*/

void DFS(int a[],int div,int v,int sum,int n)
{
	int i = v;
	if(i > n) return ;
	if(sum == div)
	{
		flag = 1;
		return ;
	}

	while(visited[i] == 1 || sum + a[i] > div)
	{	
		i++;
		if(i > n)
			break;
	        
	}
	if(i > n) return ;
	if(sum + a[i] == div)
	{
		flag = 1;
		return;
	}
	visited[i] = 1;
	sum += a[i];
	DFS(a,div,i+1,sum,n);
	visited[i] = 0;
    if(flag == 1)
		return;
	if(sum != div)
	{
		sum -= a[i];
		DFS(a,div,i+1,sum,n);
	}

}
/*
void dfs ( int a[], int sum,  int position, int t,int k )
{
	if ( t == sum )
	{
		flag = 1;
		return;
	}
	int i = position;
	while ( visited[position] == 1 || t+a[i]> sum )
	{
		if ( position > k )
			break;
		position++;
	}
	if ( position > k )
		return;	
	if ( t + a[i] == sum )
	{
		flag = 1;
		return;
	}
	t += a[i];
	visited[i] = 1;
	dfs(a,sum,position+1,t,k);
	visited[i] = 0;
	if ( flag == 1 )
		return;
	if ( t != sum )
	{
		t -= a[i];
	  dfs(a,sum,position+1,t,k);
	}
}*/
int gettime(clothes st[],int first,int end)      //对一种颜色的处理
{
    int n = end - first;                          
    int* a = new int[n+1];                  //a来保存这种颜色的所有时间
	visited = new int[n+1];                 //用来标志是否访问过 
	int i,j,k;
	int sum,div,temp;                   //sum 为时间总和 div为中间值
	i = first;                          
	j = 1;
	sum = 0;
//	tem = 0;
	temp = 0;
	while(i < end)             //把颜色的时间存到 a[]中
	{
      a[j] = st[i].time;
	  sum += st[i].time;        //求和
	  j++;
	  i++;
	}
	div = (sum+1)/2;      //sum为时间总和
	qsort(a,n+1,sizeof(int),cmp2);           //排序
	flag = false;
	for(i = 1; i <= n; i++)           //遍历
	{
      for(k = 0; k <= n; k++)
		visited[k] = 0;             
	  for(j = div; j < sum; j++) 
	  {
	   // dfs(a,j,i,0,n);       //调用DFS
		  DFS(a,j,i,0,n);          
	  if(flag)
		 break;
	  }
	  if(flag)
		 break;
   // if(sum - tem < sum - temp)
//		 temp = tem;
	}
     temp = j;
//	temp = temp > (sum - temp) ? temp : (sum - temp);
	
	return temp;
}


int main()
{
	int m,n;
//	char** a;
	char a[20][20];                //存输入的字符
	int i;                
	 clothes st[1000];                  //保存时间和颜色
	while(cin>>m>>n)
	{
		int t;
		int first,end;
         if(m == 0 && n == 0)
		   break;
      // a = new char*[m];
	   for(i = 0; i < m; i++)
	   {
		   //a[i] = new char[100];
		   cin>>a[i];           //输入字符
	   }
	   
	  // clothes* st = new clothes[n];
	 
	   for(i = 0; i < n; i++)
		   cin>>st[i].time>>st[i].ch;
	   
	  qsort(st,n,sizeof(st[0]),cmp);      //对颜色排序
	   first = 0;
	   end = 0;
	  t = 0;
	  while(end <= n)                     //范围为0 ~ n-1，n没用的
	  {
		   end = first + 1;
		  while(strcmp(st[end].ch,st[first].ch)==0)  //对一种颜色的处理
			      end++;
		  t += gettime(st,first,end);   //每次的调用目的求出这种颜色最少需要的时间
		  if(end == n)
			  break;
		  first = end;                 
	  }
	  flag = 0;
	  cout<<t<<endl;
	}
	return 0;
}
/*

#include <iostream>
#include <string.h>
using namespace std;
char col[20][20];
int a[20][120];
int l[120];
int flag=0;
void sort( int k, int n )
{
	int i,j,q;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			if ( a[k][i] < a[k][j] )
			{
				q = a[k][i];
				a[k][i] = a[k][j];
				a[k][j] = q;
			}
		}
	}
}
void dfs ( int t, int sum, int position, int k )
{
	if ( t == sum )
	{
		flag = 1;
		return;
	}
	int i = position;
	while ( l[position] == 1 || t+a[k][position] > sum )
	{
		if ( position >= a[k][110] )
			break;
		position++;
	}
	if ( position >= a[k][110] )
		return;	
	if ( t + a[k][position] == sum )
	{
		flag = 1;
		return;
	}
	t += a[k][position];
	l[position] = 1;
	dfs(t,sum,position+1,k);
	l[position] = 0;
	if ( flag == 1 )
		return;
	if ( t != sum )
	{
		t -= a[k][position];
		dfs(t,sum,position+1,k);
	}
}
int main ()
{
	int i,j,m,n;
	char put[20];
	int num;
	int time;
	while  ( scanf("%d%d",&m,&n) && !(m==0&&n==0 ) )
	{
		for ( i = 0; i <= m; i++ )
			a[i][110]= a[i][111]= 0;
		for ( i = 0; i < m; i++ )
			scanf("%s",col[i]);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d %s",&num,put);
			for ( j = 0; j < m; j++ )
				if ( strcmp(put,col[j])==0 )
					break;
			a[j][a[j][110]++] = num;
			a[j][111] += num;
		}
		for ( i = 0; i < m; i++ )
			sort(i,a[i][110]);
		time = 0;
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j <= a[i][110]; j++ )
				l[i] = 0;
			for ( j = (a[i][111]+1)/2; j <= a[i][111]; j++ )
			{
				dfs(0,j,0,i);
				if ( flag == 1 )
				{
					flag = 0;
					time += j;
					break;
				}
				flag = 0;
			}
		}
		cout<<time<<endl;
	}
	return 1;
}
*/