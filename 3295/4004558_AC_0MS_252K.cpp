#include<iostream>
using namespace std;
char str[10000];
bool val[10];
bool finish;
int pos;
bool N();
bool A();
bool C();
bool E();
bool K();
bool exp();
int GetVal(char ch)
{
	return int(ch-'p');
}
bool letter()
{
	char ch = str[pos];
	pos++;
	return val[ch-'p'];
}
bool exp()
{
	bool flag;
	switch(str[pos])
	{
	case 'K':
		flag = K();
		break;
	case 'A':
		flag = A();
		break;
	case 'C':
		flag = C();
		break;
	case 'E':
		flag = E();
		break;
	case 'N':
		flag = N();
		break;
	default:
		flag = letter();
	}
	return flag;
}
bool N()
{
	pos++;
	return !exp();
}
bool K()
{
	pos++;
	bool f1, f2;
	f1 = exp();
	f2 = exp();
	if(f1 == f2 && f1 == true)
		return true;
	else
		return false;
}
bool A()
{
	pos++;
	bool f1, f2;
	f1 = exp();
	f2 = exp();
	if(f1 == f2 && f1 == false)
		return false;
	else
		return true;
}
bool C()
{
	pos++;
	bool f1, f2;
	f1 = exp();
	f2 = exp();
	if(f1 == true && f2 == false)
		return false;
	else
		return true;
	return true;
}
bool E()
{
	pos++;
	bool f1, f2;
	f1 = exp();
	f2 = exp();
	if(f1 == f2)
		return true;
	else
		return false;
}
void Love(int lay)
{
	if(finish == false)
		return;
	if(lay == 5)
	{
		pos = 0;
		if(exp()==false)
			finish = false;
		if(str[pos] != NULL)
			cout<<".";
		return;
	}
	val[lay] = true;
	Love(lay+1);
	val[lay] = false;
	Love(lay+1);
}
int main()
{
	while(scanf(" %s", &str) != EOF)
	{
		if(str[0] == '0')
			break;
		finish = true;
		memset(val, false, sizeof(val));
		Love(0);
		if(finish == true)
			printf("tautology\n");
		else
			printf("not\n");
	}
	return 0;
}