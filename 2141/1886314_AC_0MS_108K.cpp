#include <iostream>
using namespace std;
int main ()
{
	char list[30];
	char a[128]={' '};
	char code[100];
	cin.getline(list,100,'\n');
	int i;
	for ( i = 0; i < 26; i++ )
	{
		a['a'+i] = list[i];
		a['A'+i] = list[i]-'a'+'A';
	}
	a[' '] = ' ';
	cin.getline ( code, 100, '\n');
	for ( i = 0; code[i] != 0; i++ )
		cout<<a[code[i]];
	printf("\n");
	return 1;
}