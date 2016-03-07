#include<iostream>
#include<math.h>
using namespace std;
int km[50];
bool flag;
double cura;
	int n;
	int sum;
	double end;
	bool tmd[900][900][41] ={1};
bool fg;
int main()
{

	int i;
	scanf("%d",&n);
	sum = 0;
	for( i = 1; i <= n; i++ )
	{
    	scanf("%d",&km[i]);
	//	km[i] = 40;
		//km[i] = rand()%40 + 1; 
		sum += km[i];
	}
	km[i] = 0;
	flag = false;
//	memset(tmd,1,sizeof(tmd));
	void dfs(int a, int b,int c,int dep );
	double comp( double a,double b,double c );
	end = comp( double(sum)/3,double(sum)/3,double(sum)/3);
	cura = 0.0;
	fg = false;
	dfs(0,0,0,1);
    int out = cura*100;
	if(flag)
		printf("%d\n",out);
	else
		printf("-1\n");
  return 0;
}
double comp(double a,double b,double c)
{
  double p = (a + b + c) / double(2);
  double s = double(sqrt(p*(p-a)*(p-b)*(p-c)));
  return s;
}
void dfs(int a,int b,int c,int dep)
{
  if( dep > n + 1 )
    return;
  if( tmd[a][b][dep] == false )
	  return;
  tmd[a][b][dep] = false;
  tmd[b][a][dep] = false;
  tmd[a][c][dep] = false;
  tmd[b][c][dep] = false;
  tmd[c][a][dep] = false;
  tmd[c][b][dep] = false;
  if( a + b + c == sum && a + c > b && a + b > c && b + c > a )
  {
      double t = comp(double(a),double(b),double(c));
	  if( cura < t )
	  {
		  if( t >= end )
			  fg = true;
		  cura = t;
		  flag = true;
	  }
       return;

  }
     if( 2*(a+km[dep]) < sum )
     dfs(a+km[dep],b,c,dep+1);
	 if(fg)
		 return;
	 if( 2*(b+km[dep]) < sum )
     dfs(a,b+km[dep],c,dep+1);
	 if(fg)
		 return;
	 if( 2*(c+km[dep]) < sum )
      dfs(a,b,c+km[dep],dep+1);
	  if(fg)
		 return;

}
