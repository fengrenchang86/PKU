#include<iostream>
#include<algorithm>
using namespace std;

int a[200][200];
int visited[200];
int num1,num2;
int c[200]; //   必经点
int d[200]; //   分裂点
int flag;   //是否是 必经点
int point;

void bfs2(int i)
{ 

	visited[i] = 2;
	int begin,end;
    begin = end = 0;
	int stack[5000];
    stack[end++] = i;
	int j;
	int t;
    while(begin < end)
	{
       t = stack[begin++];
	   for(j = 1; j <= point; j++)
	   {
		   if(visited[j] == 1 && a[t][j])
		   {
			   flag = 1;
			   begin = end;
			   break;
		   }
		   if( visited[j] != 2 && a[t][j])
		   {
			   visited[j] = 2;
			   stack[end++] = j;  	   
		   }
	   }
	}
 
}

void bfs(int i)
{ 
	visited[i] = 1;
	int begin,end;
    begin = end = 0;
	int stack[5000];
    stack[end++] = i;
	int j;
	int t;
    while(begin < end)
	{
       t = stack[begin++];
	   for(j = 1; j <= point; j++)
	   {
		   if(!visited[j] && a[t][j])
		   {
			   visited[j] = 1;
			   stack[end++] = j;  	   
		   }
	   }
	}
 
}
int main()
{
    int x,y;
	int i,j;
	i = 0;
	num1 = num2 = 0;
	 point = 0;
	for(i = 0; i < 190; i++)
	{
		c[i] = d[i] = 0;
		for(j = 0; j < 190; j++)
			a[i][j] = 0;
	}
	i = 0;
	while(1)
	{
		scanf("%d",&x);
		if(x == -1)
			break;
		a[i][x] = 1;
		if(x > point)
			point = x;
		while(1)
		{
		  scanf("%d",&y);
		  if(y == -2)
			  break;
           a[i][y] = 1;
		   if(y > point)
			   point = y;
		}
		i++;
	}

	int b[200][200];
	int k;

    for(i = 1; i < point; i++)
	{
        for(j = 0; j <= point; j++)
		{
			visited[j] = 0;
	/*		for(k = 0; k <= point; k++)
			{
				b[j][k] = a[j][k];
			}
	*/	}
  /*     for(j = 0; j <= point; j++)
	   {
		   a[i][j] = 0;
		   a[j][i] = 0;
	   }
*/
	    visited[i] = 1;
	    bfs(0);

	   if(visited[point] != 1) //flag = 0
	   {

		   c[num1++] = i;
/*		 for(j = 0; j <= point; j++) //还原
		  {
	    	for(k = 0; k <= point; k++)
			{
				a[j][k] = b[j][k];
			}
		  }*/
           flag = 0;
		   bfs2(i);  //i
	   	if(!flag)
			d[num2++] = i;
		}
  /*     

	    for(j = 0; j <= point; j++) //还原
		  {
		   visited[j] = 0;
			for(k = 0; k <= point; k++)
			{
				a[j][k] = b[j][k];
			}
		  }
    */     
	}//for

	printf("%d",num1);
	for(i = 0; i < num1; i++)
	{
		printf(" %d",c[i]);
	}
	printf("\n");

	printf("%d",num2);
	for(i = 0; i < num2; i++)
	{
		printf(" %d",d[i]);
	}
	printf("\n");



	return 0;
}