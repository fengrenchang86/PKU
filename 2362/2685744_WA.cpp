
#include<iostream>
#include<algorithm>
using namespace std;
int visited[200];
int sum;
int part;
int num = 0;
int a[200];
int flag;
int len;
int n;

//状态
//组成的木棍的条数 num <= 4
//当前和 part <= sum
//flag 标志 
void init()
{
	int i;
	for(i = 1; i <= n+1; i++)
	{
        visited[i] = 0;
		a[i] = 0; 
	}
	flag = 0;
	len = 0;
	part = 0;
	sum = 0;
	num = 0;

}
// 另种写法:
 void dfs(int depth) 
{
	//可以返回的条件
   if(depth > n)
	  return;
  if(part + a[depth] == sum && num == 3)
  {
	  visited[depth] = 1;
	  flag = 1;
	  return ;
  }  
   if((part - num*len) + a[depth] < len)
  {
	  visited[depth] = 1;
	  part += a[depth];
	  dfs(depth+1);
	  if(flag)
		  return;
	  visited[depth] = 0;
	  part -= a[depth];
	  
  }
   if((part - num*len) + a[depth] == len)
   {
	  num++;
	  visited[depth] = 1;
	  part += a[depth];
	  int i;
	  for(i=1;i<=n;i++)
         if(!visited[i])
             break;
            dfs(i);
	  if(flag)
		  return;
	  visited[depth] = 0;
	  part -= a[depth];
	  num--;
	  return;
  //    goto loop;
  }  
dfs(depth+1);//不要这个木棍
 
}

int main()
{
  int ca;
  scanf("%d",&ca);
  while(ca--)
  {

	  scanf("%d",&n);
	  init();
	  int i;
	  sum = 0;
	  for(i = 1; i <= n; i++)
	  {
		  scanf("%d",&a[i]);
		  sum += a[i];
	  }
	 part = 0;
	 num = 0;
	 flag = 0;
	 len = sum / 4;
	 if( sum % 4 )
	 {
         printf("no\n");
		 continue;
	 }
	 sort(&a[1],&a[n+1]);
	// a[0] = 2000000000;
	// qsort(a,n+1,sizeof(a[0]),cmp);
	 dfs(1);

	 if(flag)
	 {
		 printf("yes\n");
	 }
	 else
	 {
		 printf("no\n");
	 }
  }


	return 0;
}

