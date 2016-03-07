#include <iostream>
using namespace std;
struct BigDig
{
	int dig[80];
	int size;
}pow[50];

void UpdataBigDig(BigDig &x)
{
	memset(x.dig, 0, sizeof(x.dig));
	x.size = 0;
}
void FixBigDig(BigDig &x)
{
	while(x.size > 0 && x.dig[x.size] == 0)
		x.size--;
	x.size++;
}
void atoBigDig(BigDig &x, char *str)
{
	int i, j = 0, k = 1;
	UpdataBigDig(x);
	for(i = strlen(str) - 1; i >= 0; i--)
	{
		if(k == 1000)
		{
			k = 1;
			x.dig[x.size++] = j;
			j = 0;
		}
		j += k * (str[i] - '0');
		k *= 10;
	}
	x.dig[x.size++] = j;
	FixBigDig(x);
}
int CompBigDig(BigDig x, BigDig y)	///比较x，y，x大则返回1，x小则返回－1，相等返回0
{
	if(x.size > y.size)
		return 1;
	else if(x.size < y.size)
		return -1;
	int i;
	for(i = x.size-1; i >= 0; i--)
	{
		if(x.dig[i] > y.dig[i])
			return 1;
		else if(x.dig[i] < y.dig[i])
			return -1;
	}
	return 0;
}
void PrintBigDig(BigDig x)
{
	int i;
	printf("%d", x.dig[x.size-1]);
	for(i = x.size - 2; i >= 0; i--)
		printf(",%03d", x.dig[i]);
	printf("\n");
}
void Multi(BigDig x, int k, BigDig &y)	//	y = x*k
{
	UpdataBigDig(y);
	int i;
	for(i = 0; i < x.size; i++)
	{
		y.dig[i] = x.dig[i] * k;
	}
	for(i = 0; i < x.size; i++)
	{
		y.dig[i+1] += y.dig[i] / 1000;
		y.dig[i] %= 1000;
	}
	y.size = x.size + 1;
	FixBigDig(y);
}
int Mod(BigDig x, int k)
{
	int i, j = 0;
	for(i = x.size-1; i >= 0; i--)
	{
		j *= 1000;
		j += x.dig[i];
		j %= k;
	}
	return j % k;
}
void Divide(BigDig &x, int k)
{
	int i, j = 0;
	for(i = x.size - 1; i >= 0; i--)
	{
		j *= 1000;
		j += x.dig[i];
		x.dig[i] = j / k;
		j %= k;
	}
	FixBigDig(x);
}
void Plus(BigDig &x, BigDig y) //x += y
{
	int i;
	if(y.size > x.size)
		x.size = y.size;
	x.size ++;
	for(i = 0; i < x.size; i++)
	{
		x.dig[i] += y.dig[i];
	}
	for(i = 0; i < x.size; i++)
	{
		x.dig[i+1] += x.dig[i] / 1000;
		x.dig[i] %= 1000;
	}
	FixBigDig(x);
}
void Minue(BigDig &x, BigDig y)	//x -= y
{
	int i, carry = 0;
	for(i = 0; i < x.size; i++)
	{
		if(x.dig[i]-carry >= y.dig[i])
		{
			x.dig[i] = x.dig[i] - carry - y.dig[i];
			carry = 0;
		}
		else
		{
			x.dig[i] = 1000 + x.dig[i] - carry - y.dig[i];
			carry = 1;
		}
	}
	FixBigDig(x);
}
void SolveStr(char *str)
{
	BigDig h, c;
	UpdataBigDig(h);
	h.size = 1;
	int i, j = 0;
	for(i = strlen(str) - 1; i >= 0; i--, j++)
	{
		Multi(pow[j], str[i] - 'a' + 1, c);
		Plus(h, c);
	}
	printf("%s", str);
	j = 22 - strlen(str);
	for(i = 0; i < j; i++)
		printf(" ");
	PrintBigDig(h);
}
void SolveDig(char *ctr)
{
	char str[1000];
	int i = 0, k = 0;
	BigDig Ori, temp, x;
	UpdataBigDig(temp);
	temp.size = 1;
	atoBigDig(Ori, ctr);
	x = Ori;
	while(Ori.size != 1 || Ori.dig[0] != 0)
	{
		k = Mod(Ori, 26);
		if(k == 0)
			k = 26;
		str[i++] = char(k+'a'-1);
		temp.dig[0] = k;
		Minue(Ori, temp);
		if(Ori.size == 1 && Ori.dig[0] == 0)
			break;
		Divide(Ori, 26);
	}
	str[i] = NULL;
	k = 22 - i;
	i--;
	while(i >= 0)
	{
		printf("%c", str[i]);
		i--;
	}
	while(k)
	{
		printf(" ");
		k--;
	}
	PrintBigDig(x);
}
int main()
{
	char str[100];
	BigDig x, y;
	int i;
	pow[0].dig[0] = 1;
	pow[0].size = 1;
	for(i = 1; i <= 40; i++)
	{
		Multi(pow[i-1], 26, pow[i]);
//		PrintBigDig(pow[i]);
	}
	while(cin>>str)
	{
//  		atoBigDig(x, str);
// 		i = Mod(x, 26);
// 		printf("%d\n", i);
// 		if(i == 0)
// 		{
// 			Divide(x, 26);
// 			PrintBigDig(x);
// 		}
// 		continue;
// 		cin>>str;
// 		atoBigDig(y, str);
// 		PrintBigDig(x);
// 		printf(" and \n");
// 		PrintBigDig(y);
// 		if(CompBigDig(x, y) == 1)
// 		{
// 			Minue(x, y);
// 			PrintBigDig(x);
// 		}
// 		else
// 		{
// 			Minue(y, x);
// 			PrintBigDig(y);
// 		}
		if(str[0] == '*')
			break;
		else if(str[0] >= 'a' && str[0] <= 'z')
			SolveStr(str);
		else
			SolveDig(str);
		continue;
		atoBigDig(x, str);
		PrintBigDig(x);
		Multi(x, 26, y);
		PrintBigDig(y);
	}
	return 0;
}