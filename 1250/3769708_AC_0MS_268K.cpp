#include<iostream>
using namespace std;
int n;
int buf[30];
int use[30];
char ch[30000];
int que[10000];
void init()
{
	int i;
	for(i = 0; i < 30; i++)
	{
		buf[i] = -1;
		use[i] = 0;
	}
}
int findbuf( int x )
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(buf[i] == -1)
			return i;
	}
	return -1;
}
int getpos( int x )
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(buf[i] == x )
			return i;
	}
	return -1;
}
void solve()
{
	scanf(" %s",ch);
	init();
	int i,j=0,k=0;
	int ans = 0;
	int nbegin=0,nend = 0;
	for(i = 0; ch[i] != 0; i++)
	{
		k = ch[i]-'A';
		if( use[k] == 0 )
		{
			use[k] = 1;
			j = findbuf(k);
			if(j != -1)
			{
				use[k]++;
				buf[j] = k;
			}
			else
			{
				que[nend++] = k;
			}
		}
		else if( use[k] == 1 )
		{
			ans++;
			use[k] = 0;
		}
		else
		{
			j = getpos(k);
			use[k] = 0;
			buf[j] = -1;
			while(nbegin<nend)
			{
				if(use[que[nbegin]] == 1 )
					break;
				nbegin++;
			}
			if( nbegin < nend )
			{
				k = que[nbegin];
				nbegin++;
				use[k] = 2;
				buf[j] = k;
			}
		}
	}
	if( ans == 0 )
		printf("All customers tanned successfully.\n");
	else
		printf("%d customer(s) walked away.\n",ans);
	return;
}
int main ()
{
	while(cin>>n && n)
		solve();
	return 0;
}
