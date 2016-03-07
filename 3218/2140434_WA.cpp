#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
char ans[10000];
int getword ( char *a )
{
	int i=0;
	while ( a[i] != NULL )
	{
		if ( a[i] == ' ' && a[i+1] != ' ' && a[i+1] != NULL )
			return 0;
		i++;
	}
	return 1;
}
void get ( char *a, int& col )	//使输入的多行字符合并为一行，存在ans[]
{
	int i = 0;
	while ( a[i] != NULL )
	{
		while ( a[i] != ' ' && a[i] != NULL )
		{
			ans[col] = a[i];
			col++;
			i++;
		}
		if ( a[i] == ' ' )
		{
			ans[col] = a[i];
			col++;
			i++;
	//		while ( a[i] == ' ' )
	//			i++;
		}
	}
//	col--;
//	while ( ans[col] == ' ' )
//		col--;
//	col++;
//	ans[col] = ' ';
//	col++;
}
void L ( char *a )
{
	printf("%s\n",a);
}
void R ( char *a )
{
	int i;
	int len = strlen(a);
	len = 75-len;
	for ( i = 0; i < len ;i++ )
		printf(" ");
	printf("%s\n",a);
}
void C ( char *a )
{
	int len = strlen(a);
//	len = 75 - len;
//	for ( i = 0; i < len/2; i++ )
//		printf(" ");
	cout<<setw((75-len)/2)<<"";
	printf("%s",a);
//	for ( i = 0; i < (len+1)/2; i++ )
//		printf(" ");
	printf("\n");
}
void J ( char *a )
{
	int i,x,y,count;
	i = 0;
	count = 0;
	while ( a[i] != NULL )
	{
		while ( a[i] != ' ' && a[i] != NULL )
			i++;
		if ( a[i] == ' ' )
		{
			count++;
			i++;
		}
	}
	i = 75-i;
	if ( count != 0 )
	{
		x = i/count;
		y = i%count;
	}
	else
		x = y = 0;
	i = 0;
	int j;
	while ( a[i] != NULL )
	{
		while ( a[i] != ' ' && a[i] != NULL )
		{
			printf("%c",a[i]);
			i++;
		}
		if ( a[i] == ' ' )
		{
			printf(" ");
			for ( j = 0; j < x; j++ )
				printf(" ");
			if ( y > 0 )
			{
				printf(" ");
				y--;
			}
			i++;
		}
	}
	printf("\n");
}
void out ( char type )	//把ans[]分开成多行，每一行最多75个字符，并且每个单词不会分开出现在两行
{
	char a[100];
	int i = 0;
	int j = 0;
	while ( ans[i] != NULL )
	{
		if ( j == 75 )
		{
			if ( ans[i] != ' ' && ans[i] != NULL )//还有单词，那么当前的单词要放到下一行
			{
				i--;
				j--;
				while ( ans[i] != ' ' )
				{
					i--;
					j--;
				}
				a[j] = NULL;	
				i++;
				j = 0;
			}
			else if ( ans[i] == ' ' )
			{
				a[j] = NULL;
				i++;
				j = 0;
			}
			else
			{
				a[j] = NULL;
				j = 0;
			}
			//	字符串数组a[]处理完毕，一下根据要求调用函数处理a[]的格式问题
			switch ( type )
			{
			case 'L':
				L ( a );
				break;
			case 'R':
				R ( a );
				break;
			case 'C':
				C ( a );
				break;
			case 'J':
				J ( a );
				break;
			};
		}
		else
		{
			a[j] = ans[i];
			j++;
			i++;
		}
	}
	if ( j != 0 )
	{
		a[j] = NULL;
		//	字符串数组a[]处理完毕，一下根据要求调用函数处理a[]的格式问题
		switch ( type )
		{
		case 'L':
			L ( a );
			break;
		case 'R':
			R ( a );
			break;
		case 'C':
			C ( a );
			break;
		case 'J':
			if ( getword(a) == 1 )
				L ( a );
			else
				C ( a );
			break;
		};
	}
}

int main ()
{
 //	fstream fin("file.in");
	char type;
	cin>>type;
	cin.ignore();
	char a[100];
	int col = 0;
	while ( cin.getline(a,100,'\n') )
	{
		get(a,col);
	}
//	col--;
	ans[col] = NULL;
	out ( type );
	return 0;
}
