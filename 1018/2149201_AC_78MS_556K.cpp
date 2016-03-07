#include <iostream>
#include <fstream>
using namespace std;
int number[120];
struct dev
{
	int band;
	int price;
	int maxpos;
}a[120][120];
int cmp ( const void*a, const void *b )
{
	dev *c = (dev*)a;
	dev *d = (dev*)b;
	if ( c->band != d->band )
		return d->band - c->band;
	else
		return c->price - d->price;
}
struct node
{
	int key;
	node *next;
	node(){next=NULL;}
};
node *head = NULL;
void insert ( int x )
{
	if ( head == NULL )
	{
		head = new node;
		head->key = x;
		head->next = NULL;
	}
	else
	{
		node *temp = new node;
		temp->key = x;
		node *p = head;
		if ( head->key < x )
		{
			temp->next = head;
			head = temp;
			return;
		}
		if ( head->key == x )
			return;
		while ( p->next != NULL)
		{
			if ( p->next->key >= x )
				p = p->next;
			else
				break;
		}
		if ( p->key == x )
			return;
		temp->next = p->next;
		p->next = temp;
	}
}
int min ( int row, int bandwidth )
{
	int j = 0;
	while ( j < number[row] )
	{
		if ( a[row][j].band < bandwidth )
			break;
		j++;
	}
	if ( j == 0 )
		return -1;
	j--;
	return a[row][a[row][j].maxpos].price;
}
int main ()
{
	fstream fin("in.txt");
	int tcase,it;
	cin>>tcase;
	int n,i,j;
	int pos;
	int B,P;
	double ans;
	for ( it = 0; it < tcase; it++ )
	{
		head = NULL;
		cin>>n;
		for ( i = 0; i < n; i++ )
		{
			cin>>number[i];
			for ( j = 0; j < number[i]; j++ )
				cin>>a[i][j].band>>a[i][j].price;
			qsort(a[i],number[i],sizeof(a[i][0]),cmp);
//			cout<<i<<" :"<<endl;
//			for ( j = 0; j < number[i]; j++ )
//				cout<<j<<" "<<a[i][j].band<<" "<<a[i][j].price<<endl;
//			cout<<endl;
			pos = 0;
			a[i][0].maxpos = pos;
			insert(a[i][0].band);
//			cout<<a[i][0].band<<" "<<a[i][0].price<<" "<<a[i][a[i][0].maxpos].price<<endl;
			for ( j = 1; j < number[i]; j++ )
			{
				insert(a[i][j].band);
				if ( a[i][j].price < a[i][pos].price )
					pos = j;
				a[i][j].maxpos = pos;
//				cout<<a[i][j].band<<" "<<a[i][j].price<<" "<<a[i][a[i][j].maxpos].price<<endl;
			}
		}
/*		while ( head != NULL )
		{
			cout<<head->key<<endl;
			head = head->next;
		}
*/
		ans = 0;
		node *p = head;
		while ( p != NULL )
		{
			B = p->key;
			P = 0;
			for ( j = 0; j < n; j++ )
			{
				pos = min(j,B);
				if ( pos == -1 )
					break;
				P += pos;
			}
			p = p->next;		
			if ( pos == -1 )
				continue;
			if ( 1.0*B/P > ans )
				ans = 1.0*B/P;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}