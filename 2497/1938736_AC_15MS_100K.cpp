#include <iostream>
using namespace std;
int main ()
{
	int tcase, it;
	int m,p;
	int pro[30];
	int a[30],b[30],c[30];
	int s1,s2,s3;
	int p1,p2,p3;
	int m1,m2,m3;
	int i;
	int j;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase;it++)
	{
		scanf("%d %d",&m,&p );
		for ( i = 0; i < p; i++ )
			scanf("%d",&pro[i]);
		printf("Scenario #%d:\n",it+1);
		m3 = i = p3 = s3 = 0;
		c[0] = pro[0];
		for ( i = 1; i < p; i++ )
			c[i] = c[i-1]+pro[i];
		i = 0;
		while ( 1 )
		{
			m3 += pro[i];
			if ( m3 <= m )
				s3++;
			else
				break;
			i++;
			if ( i == p )
				break;
		}
		for ( i = 0; i < s3; i++ )
			p3 += c[i];
		for ( i = 0; i < p-1; i++)
		{
			for ( j = i+1; j<p; j++ )
			{
				if ( pro[i]>pro[j] )
				{
					s1 = pro[i];
					pro[i] = pro[j];
					pro[j] = s1;
				}
			}
		}
		a[0] = pro[0];
		for ( i = 1; i < p; i++ )
			a[i] = a[i-1]+pro[i];
		b[0] = pro[p-1];
		for ( i = 1; i < p; i++ )
			b[i] = b[i-1]+pro[p-i-1];
	//	printf("%d = %d \n",a[p-1],b[p-1]);
		m1 = 0;
		i = 0;
		p1 = 0;
		s1 = s2 = 0;
		while ( 1 )
		{	
			m1 += pro[i];
			if ( m1 <= m )
				s1++;
			else
				break;
			i++;
			if ( i == p )
				break;
		}
		m2 = 0;
		i = 0;
		p2 = 0;
		while ( 1 )
		{
			m2 += pro[i];
			if ( m2 <= m )
				s2++;
			else
				break;
			i++;
			if( i == p )
				break;
		}
		for ( i = 0; i < s1; i++ )
			p1 += a[i];
		for ( i = 0; i < s2; i++ )
			p2 += b[i];
	//	printf("bill solve %d, ste solve %d, linu solve %d\n",s3,s1,s2);
	//	printf("bill use %d, ste use %d, linu use %d\n",p3,p1,p2);
		if ( s1 > s2 || s1 == s2 && p1<=p2)
		{
			if ( s1 > s3 )
				printf("Steve wins with %d solved problems and a score of %d.\n",s1,p1);
			else if ( s3 > s1 )
				printf("Bill wins with %d solved problems and a score of %d.\n",s3,p3);
			else if ( p1 <= p3 )
				printf("Steve wins with %d solved problems and a score of %d.\n",s1,p1);
			else
				printf("Bill wins with %d solved problems and a score of %d.\n",s3,p3);
		}
		else 
		{
			if ( s2 > s3 )
				printf("Linus wins with %d solved problems and a score of %d.\n",s2,p2);
			else if ( s3 > s2 )
				printf("Bill wins with %d solved problems and a score of %d.\n",s3,p3);
			else if ( p3 < p2 )
				printf("Bill wins with %d solved problems and a score of %d.\n",s3,p3);
			else
				printf("Linus wins with %d solved problems and a score of %d.\n",s2,p2);
		}
		printf("\n");
	}			
	return 1;
}