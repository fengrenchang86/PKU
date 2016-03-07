#include <iostream>
#include <string>
using namespace std;
int f ( char *t )
{
	if ( strcmp(t,"UTC") == 0 )
		return 0;
	if ( strcmp(t,"GMT") == 0 )
		return 0;
	if ( strcmp(t,"WET") == 0 )
		return 0;
	if ( strcmp(t,"BST") == 0 )
		return 10;
	if ( strcmp(t,"IST") == 0 )
		return 10;
	if ( strcmp(t,"WEST") == 0 )
		return 10;
	if ( strcmp(t,"CET") == 0 )
		return 10;
	if ( strcmp(t,"CEST") == 0 )
		return 20;
	if ( strcmp(t,"EET") == 0 )
		return 20;
	if ( strcmp(t,"EEST") == 0 )
		return 30;
	if ( strcmp(t,"MSK") == 0 )
		return 30;
	if ( strcmp(t,"MSD") == 0 )
		return 40;
	if ( strcmp(t,"AST") == 0 )
		return -40;
	if ( strcmp(t,"ADT") == 0 )
		return -30;
	if ( strcmp(t,"NST") == 0 )
		return -35;
	if ( strcmp(t,"NDT") == 0 )
		return -25;
	if ( strcmp(t,"EST") == 0 )
		return -50;
	if ( strcmp(t,"EDT") == 0 )
		return -40;
	if ( strcmp(t,"CST") == 0 )
		return -60;
	if ( strcmp(t,"CDT") == 0 )
		return -50;
	if ( strcmp(t,"MST") == 0 )
		return -70;
	if ( strcmp(t,"MDT") == 0 )
		return -60;
	if ( strcmp(t,"PST") == 0 )
		return -80;
	if ( strcmp(t,"PDT") == 0 )
		return -70;
	if ( strcmp(t,"HST") == 0 )
		return -100;
	if ( strcmp(t,"AKST") == 0 )
		return -90;
	if ( strcmp(t,"AKDT") == 0 )
		return -80;
	if ( strcmp(t,"AEST") == 0 )
		return 100;
	if ( strcmp(t,"AEDT") == 0 )
		return 110;
	if ( strcmp(t,"ACST") == 0 )
		return 95;
	if ( strcmp(t,"ACDT") == 0 )
		return 105;
	if ( strcmp(t,"AWST") == 0 )
		return 80;
}
int main ()
{
	int tcase;
	int a,b,i,j;
	int time1,time2;
	char ch[300],time[30];
	scanf(" %d",&tcase);
	cin.ignore();
	while ( tcase )
	{
		tcase--;
		gets(ch);
		if ( ch[0] == 'n' )
		{
			a = 12;
			b = 0;
			i = 0;
		}
		else if ( ch[0] == 'm' )
		{
			a = 0;
			b = 0;
			i = 0;
		}
		else
		{
			a = 0;
			i = 0;
			while ( ch[i] >= '0' && ch[i] <= '9' )
			{
				a *= 10;
				a += ch[i]-'0';
				i++;
			}
			b = 0;
			while ( ch[i] < '0' || ch[i] > '9' )
				i++;
			while ( ch[i] >= '0' && ch[i] <= '9' )
			{
				b *= 10;
				b += ch[i]-'0';
				i++;
			}
			while ( ch[i] < 'a' || ch[i] >= 'z' )
				i++;
			if ( ch[i] == 'p' && a != 12 )
				a += 12;
		}
		while ( ch[i] < 'A' || ch[i] > 'Z' )
			i++;
		j = 0;
		while ( ch[i] >= 'A' && ch[i] <= 'Z' )
			time[j++] = ch[i++];
		time[j] = NULL;
		time1 = f(time);
		while ( ch[i] < 'A' || ch[i] > 'Z' )
			i++;
		j = 0;
		while ( ch[i] >= 'A' && ch[i] <= 'Z' )
			time[j++] = ch[i++];
		time[j] = NULL;
		time2 = f(time);
		time2-=time1;
		if ( time2 > 0 )
			time1 = 1;
		else
			time1 = -1;
		if ( time2 % 10 == 5 )
			b += time1*30;
		time2/=10;
		a += time1*time2;
		a += 24;
		a %= 24;
		while ( b >= 60 )
		{
			a++;
			b-=60;
		}
		while ( b < 0 )
		{
			a--;
			b+=60;
		}
		a += 24;
		a %= 24;
		if ( a == 0 && b == 0 )
			printf("midnight\n");
		else if ( a == 12 && b == 0 )
			printf("noon\n");
		else if ( a < 12 )
		{
			if ( a == 0 )
				a += 12;
			printf("%d:%d a.m.\n",a,b);
		}
		else
			printf("%d:%d p.m.\n",a-12,b);
	}
	return 0;
}