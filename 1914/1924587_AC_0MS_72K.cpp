/*
#include <iostream>
using namespace std;

long double f( double a[][4] )
{
	long double d = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
		-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
		+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
	return d;
}
long double change ( double a[][4], double b[], int k,bool q )
{
	double c[3];
	int i;
	for ( i = 0; i < 3; i++ )
	{
		c[i] = a[i][k];
		if ( q == true)
			a[i][k] = b[i];
	}
	double g = f(a);
	for ( i = 0; i < 3; i++ )
		a[i][k] = c[i];
	return g;
}
int main ()
{
	int n;
	double a[3][4];
	double b[3];
	long double ans[4];
	scanf("%d",&n);
	int i;
	int j , k;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j< 3; j++ )
		{
			for ( k = 0; k < 4; k++ )
				scanf("%d",&a[j][k]);
		}
		b[0] = a[0][3];
		b[1] = a[1][3];
		b[2] = a[2][3];
		for ( j = 0; j < 3; j++ )
		{
			ans[j] = change(a,b,j,true);
			if ( ans[j] < 0.0005 && ans[j] > -0.0005 )
				printf("%.0lf ",0);
			else
				printf("%.0lf ",ans[j]);
		}
		ans[3] = change(a,b,j,false);
		printf("%.0lf",ans[3]);
		printf("\n");
		if ( ans[3] == 0 )
			printf("No unique solution\n");
		else
		{
			for ( j = 0; j < 3; j++ )
			{
				ans[j] = ans[j]/ans[3];
				if ( ans[j] < 0.0005 && ans[j] > -0.0005  )
					ans[j] = 0.0;
			}
			printf("Unique solution:");
			for ( j = 0; j < 3; j++ )
				printf(" %0.3lf",ans[j]);
			printf("\n");
		}
		if ( i != n-1 )
		printf("\n");
	}
	return 1;
}
*/
#include <stdio.h>
int main()
{
    int ca,i,j,f;
    double mat[5][5],b[5],a1,a2,a3,a,tmp;
    scanf("%d",&ca);
    while(ca--)
    {
        f=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++) 
			{
				scanf("%lf",&mat[i][j]);
			}
				scanf("%lf",&b[i]);
			
        }
        a=mat[0][0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1])-
          mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0])+
          mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);
        a1=b[0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1])-
          mat[0][1]*(b[1]*mat[2][2]-mat[1][2]*b[2])+
          mat[0][2]*(b[1]*mat[2][1]-mat[1][1]*b[2]);
        a2=mat[0][0]*(b[1]*mat[2][2]-mat[1][2]*b[2])-
          b[0]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0])+
          mat[0][2]*(mat[1][0]*b[2]-b[1]*mat[2][0]);
        a3=mat[0][0]*(mat[1][1]*b[2]-b[1]*mat[2][1])-
          mat[0][1]*(mat[1][0]*b[2]-b[1]*mat[2][0])+
          b[0]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);
        if(a!=0.0) f=1;
        if(a1<0.0005&&a1>-0.0005) a1=0.0;
        if(a2<0.0005&&a2>-0.0005) a2=0.0;
        if(a3<0.0005&&a3>-0.0005) a3=0.0;
        if(a<0.00005&&a>-0.0005) a=0.0;
        printf("%.0lf %.0lf %.0lf %.0lf\n",a1,a2,a3,a);
        if(f)
        {
            printf("Unique solution: ");
            tmp=a1/a;
            if(tmp<0.0005&&tmp>-0.0005) printf("0.000");
            else printf("%.3lf",tmp);
            tmp=a2/a;
            if(tmp<0.0005&&tmp>-0.0005) printf(" 0.000");
            else printf(" %.3lf",tmp);
            tmp=a3/a;
            if(tmp<0.0005&&tmp>-0.0005) printf(" 0.000");
            else printf(" %.3lf",tmp);
            printf("\n");
        }
        else printf("No unique solution\n");
        printf("\n");
    }
    return 0;
}
