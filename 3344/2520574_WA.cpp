#include <iostream>
using namespace std;
char board[1010][1010];
int px,py,dir;
int n;
void move ( int num )
{
	if ( num == 0 )
		return;
	char ta,tb;
	int k;
	if ( dir == 0 )
	{
		if ( px == 0 )
			return;
		else if ( px == 1 )
		{
			board[px][py] = '.';
			px--;
			return;
		}
		while ( num > 0 )
		{
			k = px-1;
			ta = board[k][py];
			tb = ta;
			board[px][py] = '.';
			px--;
			k = px-1;
			while ( k >= 0 && board[k][py] != '.' )
			{
				tb = board[k][py];
				board[k][py] = ta;
				ta = tb;
				k--;
			}
			if ( board[k][py] == '.' )
				board[k][py] = ta;
			if ( k < 0 )
				break;
			num--;
		}
	}
	else if ( dir == 1 )
	{
		if ( py == 0 )
			return;
		else if ( py == 1 )
		{
			board[px][py] = '.';
			py--;
			return;
		}
		while ( num > 0 )
		{
			k = py-1;
			ta = board[px][k];
			tb = ta;
			board[px][py] = '.';
			py--;
			k = py-1;
			while ( k >= 0 && board[px][k] != '.' )
			{
				tb = board[px][k];
				board[px][k] = ta;
				ta = tb;
				k--;
			}
			if ( board[px][k] == '.' )
				board[px][k] = ta;
			if ( k < 0 )
				break;
			num--;
		}
	}
	else if ( dir == 2 )
	{
		if ( px == n-1 )
			return;
		else if ( px == n-2 )
		{
			board[px][py] = '.';
			px++;
			return;
		}
		while ( num > 0 )
		{
			k = px+1;
			ta = board[k][py];
			tb = ta;
			board[px][py] = '.';
			px++;
			k = px+1;
			while ( k< n && board[k][py] != '.' )
			{
				tb = board[k][py];
				board[k][py] = ta;
				ta = tb;
				k++;
			}
			if ( board[k][py] == '.' )
				board[k][py] = ta;
			if ( k == n )
				break;
			num--;
		}
	}
	else if ( dir == 3 )
	{
		if ( py == n-1 )
			return;
		else if ( py == n-2 )
		{
			board[px][py] = '.';
			py++;
			return;
		}
		while ( num > 0 )
		{
			k = py+1;
			ta = board[px][k];
			tb = ta;
			board[px][py] = '.';
			py++;
			k = py+1;
			while ( k < n && board[px][k] != '.' )
			{
				tb = board[px][k];
				board[px][k] = ta;
				ta = tb;
				k++;
			}
			if ( board[px][k] == '.' )
				board[px][k] = ta;
			if ( k == n )
				break;
			num--;
		}
	}
}
void turn ( int d )
{
	dir += d;
	dir %= 4;
}
int main ()
{
	int i,j,d;
	char ch[50];
	while ( cin.getline(board[0],1010,'\n') && !(board[0][0] == '-' && board[0][1] == '-') )
	{
		px = -1;
		py = -1;
		n = strlen(board[0]);
		for ( i = 1; i < n; i++ )
			cin.getline(board[i],1010,'\n');
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				if ( board[i][j] == '>' )
				{
					dir = 3;
					px = i;
					py = j;
					break;
				}
				else if ( board[i][j] == '<' )
				{
					dir = 1;
					px = i;
					py = j;
					break;
				}
				else if ( board[i][j] == '^' )
				{
					dir = 0;
					px = i;
					py = j;
					break;
				}
				else if ( board[i][j] == 'v' )
				{
					dir = 2;
					px = i;
					py = j;
					break;
				}
			}
			if ( px != -1 )
				break;
		}
		while ( cin.getline(ch,1010,'\n') && ch[0] != '#' )
		{
			if ( ch[0] == 'm' )
			{
				i = 0;
				while ( ch[i] > '9' || ch[i] < '0' )
					i++;
				d = 0;
				while ( ch[i] >= '0' && ch[i] <= '9' && i < n )
				{
					d *= 10;
					d += (ch[i]-'0');
					i++;
				}
				move(d);
			}
			else
			{
				i = 0;
				while ( ch[i] != ' ' )
					i++;
				i++;
				if ( ch[i] == 'r' )
					d = 3;
				else if ( ch[i] == 'l' )
					d = 1;
				else
					d = 2;
				turn(d);
			}
		}
		if ( dir == 0 )
			board[px][py] = '^';
		else if ( dir == 1 )
			board[px][py] = '<';
		else if ( dir == 2 )
			board[px][py] = '>';
		else
			board[px][py] = 'v';
		for ( i = 0; i < n; i++ )
			printf("%s\n",board[i]);
		printf("\n");
	}
	return 0;
}