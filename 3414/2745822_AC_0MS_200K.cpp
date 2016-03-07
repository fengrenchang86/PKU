
#include<iostream>
using namespace std;
struct ac
{
	int l;
	int r;
	int x; // 1 --> fill, 2 --> pround , 3 -- > drop
	int y;
	int s; //来源
};
ac queue[10000000];
int visited[200][200];
void out(int i)
{
	ac g = queue[i];
	if( g.s != 0 )
		out(g.s);
			 if( g.x == 1 )
				{
				  printf("FILL(1)\n");
				}
				 
				  if( g.x == 2 )
				  {
                      printf("POUR(1,2)\n");
				  }
				  if( g.x == 3 )
				  {
                      printf("DROP(1)\n");
				  }

				  if( g.y == 1 )
				  {
					  printf("FILL(2)\n");
				  }
				  if( g.y == 2 )
				  {
                      printf("POUR(2,1)\n");
				  }
				  if( g.y == 3 )
				  {
                      printf("DROP(2)\n");
				  }
}
int main()
{

	int a,b,c;
	int flag;
	while(scanf("%d%d%d",&a,&b,&c) != EOF)
//	cin>>a>>b>>c;
	{

		flag = 0;
 
        ac t;
		t.l = 0;
		t.r = 0;
		t.x = 0;
		t.y = 0;
		t.s = 0;

        int begin,end;
		begin = end = 0;
		queue[end++] = t;
        int sit;
		int i,j;
		for ( i = 0; i <= 100; i++ )
			for ( j = 0; j <= 100; j++ )
				visited[i][j] = 0;
		visited[0][0] = 1;
		while(begin < end)
		{
           ac tem = queue[begin++];

		   if( tem.l == c || tem.r == c )
		   {

                   sit = begin - 1;
			   flag = 1;
			   break;
		   }
		   if( end > 10000000)
			   break;
			ac temp;
       //       if( tem.l == 0 && tem.x != 3) // fill left如果不是刚刚倒出导致0的话可以填
			   {
		//		   ac temp;
				   temp.l = a;
				   temp.r = tem.r;
				   temp.x = 1;
				   temp.y = 0;
				   temp.s = begin-1;
				   if( visited[temp.l][temp.r] == 0)
				   {
				//   temp.ps = tem.s;
				    queue[end++] = temp;
				    visited[temp.l][temp.r] = 1;
				   }
			   }
		//	  if( tem.r == 0 && tem.y != 3)
			  {
		//		   ac temp;
				   temp.l = tem.l;
				   temp.r = b;
				   temp.x = 0;
				   temp.y = 1;
                   temp.s = begin-1;
				   if( visited[temp.l][temp.r] == 0)
				   {
				//   temp.ps = tem.s;
				    queue[end++] = temp;
				    visited[temp.l][temp.r] = 1;
				   }			  
			  }

	//		  if(tem.l != 0 && tem.r != b && tem.x != 2)   // 倒给 b
			  {
		//		  ac temp;
			     if(tem.l >= b-tem.r)
				 {
					   temp.r = b;
					   temp.l = tem.l - (b-tem.r);
				 }
				 else
				   {
					   temp.r = tem.r + tem.l;
					   temp.l = 0;
				   }
				   temp.x = 2;         // pround  1 --> 2
				   temp.y = 0;
				   temp.s = begin-1;
				   if( visited[temp.l][temp.r] == 0)
				   {
				//   temp.ps = tem.s;
				    queue[end++] = temp;
				    visited[temp.l][temp.r] = 1;
				   }
			  }

	//		  if(tem.r != 0 && tem.l != b && tem.y != 2)   // 倒给 a
			  {
	//			  ac temp;
			     if(tem.r >= a-tem.l)
				 {
					   temp.l = a;
					   temp.r = tem.r - (a-tem.l);
				 }
				 else
				   {
					   temp.l = tem.r + tem.l;
					   temp.r = 0;
				   }
				   temp.x = 0;         // pround  1 --> 2
				   temp.y = 2;
				   temp.s = begin-1;
				   if( visited[temp.l][temp.r] == 0)
				   {
				//   temp.ps = tem.s;
				    queue[end++] = temp;
				    visited[temp.l][temp.r] = 1;
				   }
			  }

			  /////////////drop...
		//	  if( tem.l != 0 && tem.x != 1)
			  {
		//		  ac temp;
				  temp.l = 0;
				  temp.r = tem.r;
				  temp.x = 3;
				  temp.y = 0;
				  temp.s = begin-1;
				  if( visited[temp.l][temp.r] == 0)
				   {
				//   temp.ps = tem.s;
				    queue[end++] = temp;
				    visited[temp.l][temp.r] = 1;
				   }
			  }

	//		  if(tem.r != 0 && tem.y != 1)
			  {
	//			  ac temp;
				  temp.r = 0;
				  temp.l = tem.l;
				  temp.x = 0;
				  temp.y = 3;
				  temp.s = begin-1;
				  if( visited[temp.l][temp.r] == 0)
				   {
				//   temp.ps = tem.s;
				    queue[end++] = temp;
				    visited[temp.l][temp.r] = 1;
				   }
			  }
		}
 //        printf("end = %d\n,end");
		if( flag )
		{
			int v = 1;
			ac tl = queue[sit];
			while(tl.s != 0)
			{
                 v++;
				 tl = queue[tl.s];
			}
			printf("%d\n",v);
            out(sit);   
		}
		else
		{
           printf("impossible\n");
		}
	}
	return 0;
}