#include <iostream>
#include <string>
using namespace std;
char a[4100][210];
bool findt;
char ans[210];
int main ()
{
	int comp(char*,char *);
	char temp[210];
	int n,i,j,k,len,begin,end,mid;
	while ( scanf("%d",&n) && n!=0 )
	{
		for ( i = 0; i < n; i++ )
			scanf("%s",&a[i]);
		len = strlen(a[0]);
		begin = 0;
		end = len-1;
		while ( begin < end )
		{
			mid = (begin+end)/2;
			for ( i = 0; i+mid < len; i++ )
			{
				for ( j = 0; j < mid; j++ )
					temp[j] = a[0][i+j];
				temp[j] = NULL;
				k = 1;
				for ( j = 1; j < n; j++ )
				{
					if ( comp(temp,a[j])==0 )
						break;
					else
						k++;
				}
				if ( k == n )
					break;
			}
			if ( k == n )
			{
				if ( begin == mid )
				{
					begin = end = mid;
					break;
				}
				begin = mid;
			}
			else
			{
				if ( end == mid )
				{
					begin = end = mid;
					break;
				}
				end = mid;
			}
		}
		findt = false;
		if ( end != 0 )
		{
			for ( i = 0; i < end; i++ )
			{
				for ( j = 0; j < end; j++ )
					temp[j] = a[0][i+j];
				temp[j] = NULL;
				k = 1;
				for ( j = 1; j < n; j++ )
				{
					if ( comp(temp,a[j])==0)
						break;
					else
						k++;
				}
				if ( findt == false && k == n || findt == true && strcmp(temp,ans)<0 && k == n)
				{
					findt = true;
					strcpy(ans,temp);
				}
			}
			cout<<ans<<endl;
		}
		else
			cout<<"IDENTITY LOST"<<endl;
	//	cout<<end<<endl;
	}
	return 0;
}
int comp ( char *a, char *b ) //if ( a <= b )return 1; else return 0;
{
	int i=0,j=0;
	while ( a[i] != NULL && b[j] != NULL )
	{
		if ( a[i] == b[j] )
		{
			i++;
			j++;
		}
		else
			j++;
	}
	if ( a[i] == NULL )
		return 1;
	else
		return 0;
}