#include<iostream.h>
class node
{
public:
	int num;
	node *next;
	node *back;
	node ()
	{
		num = 0;
		next = NULL;
		back = NULL;
	}
};
class chang
{
public:
	char store[1000];
	int N;
	node *head1;
	node *tail1;
	chang()
	{
		head1 = NULL; 
		tail1 = NULL;
	}
	void input ();
	void insert1 ( );	//头插入
	void chengfa ( int );	//乘法
	void tochar ( int e );	//链中int数据转换成字符格式
};

void chang::tochar ( int e )
{
	node *temp;
	int pos = 0;
	temp = head1;
	do
	{
		store[pos] = temp->num / 1000 + '0';
		pos++;
		store[pos] = temp->num / 100 - temp->num / 1000 * 10 + '0';
		pos++;
		store[pos] = temp->num / 10 - temp->num / 100 * 10 + '0';
		pos++;
		store[pos] = temp->num - temp->num / 10 * 10 + '0';
		pos++;
		temp = temp->next;
	}while ( temp != head1);
	int j = e * N;
	while ( j > 0 )
	{
		pos--;
		store[pos+1] = store[pos];
		j--;
	}
	store[pos] = '.';
}

void chang::input ( )
{
	int power ( int, int );
	char get[10];
	char *getnum = new char[10];
	cin.getline(get,20);
	int z=0;					//把输入的数字乘以 10 ^n，使这个数字变成整数
	int po=0;
	int k=0;
	int exp;					//整数部分的位数->小数部分的位数
	N = 0;						//指数
	while ( get[po] != '.' )
	{
		getnum[po] = get[po];
		po++;
	}
	exp = po;
	po++;
	while ( po != 6 )
	{
		getnum[po-1] = get[po];
		po++;
	}
	getnum[po-1]=NULL;
	po--;
	exp = po - exp;
	if ( get[7] >= '0' && get[7] <= '9' )
		N += ( get[7] - '0' ) * 10;
	N += ( get[8] - '0' );
	po = 0;
	while ( getnum[po] != NULL )
		po++;
	po--;
	while ( po != -1 )
	{
		z += ( getnum[po] - 48 ) * power ( 10, k );
		k++;
		po--;
	}
	cout<<"z="<<z<<endl;
	cout<<"N= "<<N<<endl;

	//以下是储存z放进链里面，链头指针是head1
	chang::insert1 ( );
	if ( z >= 10000 )
	{
		head1->num = z % 10000;
		chang::insert1 ( );
		head1->num = z / 10000;
	}
	else
		head1->num = z;
	chang::chengfa ( z );
	chang::tochar ( exp );

}

void chang::insert1 ( )		//头插入
{
	node *temp;
	temp = new node;
	if (head1 == NULL)
	{
		head1 = temp;
		tail1 = temp;
		temp->next = temp;
		temp->back = temp;
	}
	else
	{
		temp->next = head1;
		temp->back = tail1;
		tail1->next = temp;
		head1->back = temp;
		head1 = temp;
	}
}

void chang::chengfa(int c)
{
	node *p;
	int count = 1;
	while ( count != N )
	{
		p = head1;
		do
		{
			p->num *= c;
			p = p->back;
		}while ( p != head1 );
		p = tail1;
		while ( p != head1 )
		{
			if ( p->num >= 10000)
			{
				p->back->num += p->num / 10000;
				p->num %= 10000;
			}
			p = p->back;
		}
		while ( head1->num >= 10000 )
		{
			chang::insert1 ( );
			head1->num = head1->next->num / 10000;
			head1->next->num %= 10000;
		}
		count++;
	}
}

void main ()
{
	chang a;
	a.input();
	cout<<"finished"<<endl;
}

int power ( int x, int y )
{
	int result=1;
	for ( int i = 0; i < y; i++ )
		result *= x;
	return result;
}
