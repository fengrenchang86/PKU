#include <iostream>
using namespace std;
int main ()
{
	int v[26];
	int g[26];
	bool w[26];
	int tcase,i,count;
	char ch[2000];
	bool plus;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		cin>>ch;
		memset(g,0,sizeof(g));
		memset(w,0,sizeof(w));
		for ( i = 0; i < 26; i++ )
			v[i] = i+1;
		count = 0;
		if ( ch[0] == '+' && ch[1]!='+' )
		{
			i = 1;
			plus = true;
		}
		else if ( ch[0] != '+' && ch[0] != '-' )
		{
			i = 0;
			plus = true;
		}
		else
		{
			i = 0;
			plus = false;
		}
		for (; ch[i] != NULL; i++ )
		{
			if ( ch[i] == '+' && ch[i+1] == '+')
			{
				v[ch[i+2]-'a']++;
				i+=2;
			}
			else if ( ch[i] == '-' && ch[i+1] == '-' )
			{
				v[ch[i+2]-'a']--;
				i+=2;
			}
			{
				w[ch[i]-'a'] = true;
				if( plus == true )
					count += v[ch[i]-'a'];
				else
					count -= v[ch[i]-'a'];
				if ( ch[i+1] == '+' && ch[i+2] == '+' )
				{
					g[ch[i]-'a']++;
					i +=2;
					if ( ch[i+1] == '-' )
						plus = false;
					else
						plus = true;
				}
				else if ( ch[i+1] =='-' && ch[i+2]=='-')
				{
					g[ch[i]-'a']--;
					i +=2;
					if ( ch[i+1] == '+' )
						plus = true;
					else
						plus = false;
				}
				if ( ch[i+1] == '+' )
				{
					plus = true;
					i++;
				}
				else if ( ch[i+1] == '-' )
				{
					plus = false;
					i++;
				}
			}
		}
		printf("Expression: %s\n",ch);
		printf("value = %d\n",count);
		for ( i = 0; i < 26; i++ )
		{
			if ( w[i] == true )
			{
				printf("%c = %d\n",char(i+'a'),v[i]+g[i]);
			}
		}
	}
	return 0;
}