#include<iostream>
using namespace std;
struct ac
{
	int dig[600];
	int size;
}x, y, z, t[600];
char ca[1200],cb[1200];
void plus( ac a, ac b, ac &c )
{
	ac d;
	int i,carry=0;
	for ( i = 0; i < 600; i++ )
		d.dig[i] = 0;
	d.size = 1;
	for ( i = 0; i < 100; i++ )
	{
		d.dig[i] = (a.dig[i]+b.dig[i]+carry)%10;
		carry = (a.dig[i]+b.dig[i]+carry)/10;
	}
	i = 599;
	while ( d.dig[i] == 0 && i > 0 )
		i--;
	d.size = i+1;
	c = d;
}
void substrac(ac a, ac b,  ac &c)
{
	ac d;
	int i, carry = 0;
	memset(d.dig, 0, sizeof(d.dig));
	for(i = 0; i < a.size; i++)
	{
		d.dig[i] = a.dig[i] - carry - b.dig[i];
		if(d.dig[i] < 0)
		{
			d.dig[i] += 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	d.size = 599;
	while(d.size > 0 && d.dig[d.size] == 0)
		d.size--;
	d.size++;
	c = d;
}
void cheng ( ac a, ac b, ac &c )
{
	ac d;
	memset(d.dig,0,sizeof(d.dig));
	d.size = 0;
	int i,j;
	for ( i = 0; i < a.size; i++ )
	{
		for ( j = 0; j < b.size; j++ )
			d.dig[i+j]+=a.dig[i]*b.dig[j];
	}
	for ( i = 0; i < 600; i++ )
	{
		d.dig[i+1] += d.dig[i]/10;
		d.dig[i] %= 10;
	}
	d.size = 599;
	while ( d.size > 0 && d.dig[d.size] == 0 )
		d.size --;
	d.size++;
	c = d;
}
void cheng(ac a, int val, ac &c)
{
	ac d;
	int i, carry = 0;
	memset(d.dig, 0, sizeof(a.dig));
	for(i = 0; i < a.size; i++)
		d.dig[i] = a.dig[i] * val;
	for(i = 0; i < 600; i++)
	{
		d.dig[i+1] += d.dig[i] / 10;
		d.dig[i] %= 10;
	}
	d.size = 599;
	while(d.size > 0 && d.dig[d.size] == 0)
		d.size--;
	d.size++;
	c = d;
}
void chToac ( char *t, ac &a )
{
	memset(a.dig,0,sizeof(a.dig));
	a.size = 0;
	int i = strlen(t)-1;
	int k = 0,j=0;
	while ( i >= 0 )
	{
		j += (t[i]-'0');
		a.dig[a.size++] = j;
		j = 0;
		i--;
	}
	if ( j != 0 )
		a.dig[a.size++] = j;
}
void print(int k, char ch)
{
	int i;
	for(i = 0; i < k; i++)
		printf("%c", ch);
}
void print ( ac a )
{
	printf("%d",a.dig[a.size-1]);
	int i = a.size-2;
	while ( i >= 0 )
	{
		printf("%d",a.dig[i]);
		i--;
	}
	printf("\n");
}
void OperOne(char ch)
{
	int nMax = x.size > y.size+1 ? x.size: y.size+1;
	if(ch == '+')
		plus(x, y, z);
	else
		substrac(x, y, z);
	nMax = nMax > z.size ? nMax:z.size;
	print(nMax - x.size, ' ');
	print(x);
	print(nMax - y.size - 1, ' ');
	printf("%c", ch);
	print(y);
	print(nMax, '-');
	printf("\n");
	print(nMax - z.size, ' ');
	print(z);
	printf("\n");
}
void OperTwo()
{
	int i, j, n = y.size;
	int nMax;
	j = x.size > y.size + 1 ? x.size:y.size+1;
	nMax = j;
	cheng(x, y, z);
	nMax = nMax > z.size ? nMax:z.size;
	for(i = 0; i < n; i++)
	{
		cheng(x, y.dig[i], t[i]);
		nMax = nMax > t[i].size+i ? nMax : t[i].size+i;
	}
	print(nMax - x.size, ' ');
	print(x);
	print(nMax - y.size - 1, ' ');
	printf("*");
	print(y);
	print(nMax - j, ' ');
	print(j, '-');
	printf("\n");
	if(n != 1)
	{
		for(i = 0; i < n; i++)
		{
			print(nMax - t[i].size - i, ' ');
			print(t[i]);
		}
		print(nMax, '-');
		printf("\n");
	}
	print(nMax - z.size, ' ');
	print(z);
	printf("\n");
}

int main ()
{
	char tch[100000];
	char ch;
	int i, j, k;
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf(" %s", &tch);
		i = 0;
		j = k = 0;
		while(tch[i] >= '0' && tch[i] <= '9')
			ca[j++] = tch[i++];
		ca[j] = 0;
		ch = tch[i];
		i++;
		while(tch[i] >= '0' && tch[i] <= '9')
			cb[k++] = tch[i++];
		cb[k] = 0;
		chToac(ca, x);
		chToac(cb, y);
		if(ch == '*')
			OperTwo();
		else
			OperOne(ch);

	}
	return 0;
}