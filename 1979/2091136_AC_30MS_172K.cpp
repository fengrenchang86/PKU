#include<iostream>
using namespace std;
int count;
char** a;
struct st
{
	int x;
	int y;
}move[4] = {{0,-1},{0,1},{1,0},{-1,0}};
st queue[600];
int front,rear;
int visited[30][30];

void BFS(int p1,int p2)
{
	int loop;
  int x,y;
  x = p1;
  y = p2;
  st temp1,temp2;
  temp1.x = x;
  temp1.y = y;
  queue[++front] = temp1;
  count = 1;
  visited[x][y] = 1;
  while(front != rear)
  {
	  temp2 = queue[front--];
	 // visited[temp2.x][temp2.y] = 1;  在这里是错的
	  for(loop = 0; loop < 4; loop++)
	  {
		  x = temp2.x + move[loop].x;
		  y = temp2.y + move[loop].y;
		  if(visited[x][y] == 0 && a[x][y] == '.')
		  {
			  count++;
			  temp1.x = x;
			  temp1.y = y;
			  queue[++front] = temp1;
			  visited[x][y] = 1;
		  }
	  }
  }
}

int main()
{
	int col,row;
	int i,j;
	int pos1,pos2;
	
	while(scanf("%d %d",&col,&row) && (col != 0 && row != 0))
	{
	//	if(col == 0 && row == 0)
		//	break;
		if((col == 0 && row != 0) || (row == 0 && col != 0))
		{
			cout<<"0"<<endl;
			continue;
		}
        a = new char*[row + 2];
		
		for(i = 0; i < row + 2; i++)
		{
			a[i] = new char[col+2];
		}
		for(i = 0; i < row + 2; i++)
		{
			a[i][0] = '#';
			a[i][col+1] = '#';
		}
		for(i = 0; i < col + 2; i++)
		{
			a[0][i] = '#';
			a[row + 1][i] = '#';
		}
		for(i = 1; i <= row; i++)
			for(j = 1; j <= col; j++)
			{
               cin>>a[i][j];  
			   if(a[i][j] == '@')
			   {
				   pos1 = i;
                   pos2 = j; 
			   } 
			}

			front = rear = -1;
			memset(visited,0,sizeof(visited));
			memset(queue,0,sizeof(queue));
           BFS(pos1,pos2);
		   cout<<count<<endl;
	}
	return 0;
} 