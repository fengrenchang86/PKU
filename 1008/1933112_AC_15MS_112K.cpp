#include <iostream>
using namespace std;
int compare ( char *a, char *b )
{
	int i = 0;
	for ( i = 0; a[i] != NULL; i++ )
		if ( a[i] != b[i] )
			return 0;
	return 1;
}
int get(char *a, int &day, int &year, int &month,char list[][10] )
{
	int i;
	char h[20];
	int j = 0;
	day = 0;
	year = 0;
	for ( i = 0; a[i] >='0' && a[i] <= '9'; i++ )
	{
		day *= 10;
		day += (a[i]-'0');
	}
	while ( a[i] < 'a' || a[i] > 'z' )
		i++;
	while ( a[i] >= 'a' && a[i] <= 'z' )
		h[j++] = a[i++];
	while ( a[i] < '0' || a[i] > '9' )
		i++;
	for ( ; a[i] >= '0' && a[i] <= '9'; i++ )
	{
		year *= 10;
		year += (a[i]-'0');
	}
	for ( i = 0; i < j; i++ )
		a[i] = h[i];
	a[i] = '\0';
	for ( i = 0; i < 19; i++ )
	{
		if ( compare(a,list[i])==1 )
			break;
	}
	month = i;
	return 1;
}
void to ( char *a, char *b )
{
	int i;
	for ( i = 0; b[i] != NULL; i++ )
		a[i] = b[i];
}
int main ()
{
	char list[20][10];
	to ( list[0], "pop");
	to ( list[1], "no");
	to ( list[2], "zip");
	to ( list[3], "zotz");
	to ( list[4], "tzec");
	to ( list[5], "xul");
	to ( list[6], "yoxkin");
	to ( list[7], "mol");
	to ( list[8], "chen");
	to ( list[9], "yax");
	to ( list[10], "zac");
	to ( list[11], "ceh");
	to ( list[12], "mac");
	to ( list[13], "kankin");
	to ( list[14], "muan");
	to ( list[15], "pax");
	to ( list[16], "koyab");
	to ( list[17], "cumhu");
	to ( list[18], "uayet");
	char index[20][10] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat",
		"muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
	char a[20],b[20];
	int n,i;
	int c;
	int x,y;
	int year,day,month,num;
	scanf("%d",&n);
	printf("%d\n",n);
	cin.ignore();
	for ( i = 0; i < n; i++ )
	{
		cin.getline(a,100,'\n');
		get(a,day,year,month, list);
//		printf("day = %d,  year = %d, month = %d\n",day,year,month);
		num = year*365+20*month+day;
		year = num/260;
		num %= 260;
		x = y = 0;
		for ( c = 0; c < num; c++ )
		{
			++x%=13;
			++y%=20;
		}
		x++;
		printf("%d %s %d\n",x,index[y],year);
//		printf("month is : %s\n",a);
//		printf("    %d\n",compare(a,"zac") );
	}
	return 1;
}