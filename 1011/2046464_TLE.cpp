
#include <iostream>
using namespace std;
int flag = 0;
int lay = 0;
int Qsort( int t[], int start, int end )
{
	int i;
	t[0] = t[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && t[up] <= t[0] )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[up] > t[0] )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[down] >= t[0] )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[down] < t[0] )
		{
			t[up] = t[down];
			i = 0;
			up--;
		}
	}
	t[down] = t[0];
	return down;
}
void qs ( int t[], int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(t,start,end);
		qs ( t,start,mid-1);
		qs ( t,mid+1,end);
	}
}
int f ( int a[], int l[], int &t, int sum, int position, int max, int n )
{
	if ( t == sum )
	{
		lay ++;
		position = 1;
		while ( l[position] == 0 )
			position++;
		if ( position > n )
			return 0;
		int p = 0;
		f ( a,l, p, sum , position, max-sum,n);
		lay--;
		if ( max-sum == sum )
		{
			flag = 1;
			return 1;
		}
		if ( lay == 0 )
		{
			flag = -1;
			return 0;
		}
	}
	else
	{
		if ( position > n )
			return 0;
		int pos = position;
		while ( a[pos] + t > sum || l[pos] == 1 )
			pos++;
		if ( pos > n )
			return 0;
		position = pos;
		t+=a[position];
		if ( t <= sum )
		{
			if (a[position] != a[position-1])
			{
				l[position] = 1;
				f(a,l,t,sum,position+1,max,n);
			}
			else if (l[position-1] == 1)
			{
				l[position] = 1;
				f(a,l,t,sum,position+1,max,n);
			}
		}
		if ( flag == 1 || flag == -1)
			return 1;
		l[position] = 0;
		if ( t != sum )
		{
			t -= a[position];
			f(a,l,t,sum,position+1,max,n);
		}
		else
			t -= a[position];
	}
	
	return 1;
}
int main ()
{
	int n,i,j;
	int sum;
	int m;
	int d[100];
	int l[100];
	while ( scanf("%d",&n) && n!=0 )
	{
		for ( i = 1; i <= n; i++ )
			l[i] = 0;
		sum = 0;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&d[i]);
			if ( d[i] > 50 )
			{
				i--;
				n--;
				continue;
			}
			sum += d[i];
		}
		if ( n == 1 )
		{
			cout<<d[1]<<endl;
			continue;
		}
		qs(d,1,n);
		d[0] = -1;
		l[0] = 1;
		for ( i = d[1]; i<=(sum+1)/2; i++ )
		{
			if ( sum%i==0)
			{
				int q = 0;
				f(d,l,q,i,1,sum,n);
				if ( flag == 1 )
					break;
			}
		}
		if ( flag == 1 )
			cout<<i<<endl;
		else
			cout<<sum<<endl;
		flag = 0;
	}
	return 1;
}
/*
#include <stdlib.h>
#include <stdio.h>
int parts[100];
int visited[100];
int num,minLen,sum,counter;
bool exist;
void DFS(int val,int loc){ //al为搜到的木棍的和，loc为从哪个顶点开始搜。
    if(counter*minLen == sum){ 
       exist=true;
       return;
    }
	if ( exist == true )
		return ;
    int i;
    for(i=loc;i>0;i--)
        if(visited[i]==0) break;
    if(i==0) return;
    val += parts[i];
    visited[i]=1;
    if(val == minLen){
        counter++;
        DFS(0,num);
		if ( exist == true )
			return;
        counter--;
        val-=parts[i];
        visited[i]=0;
        DFS(val,i-1);
		if ( exist == true )
			return;
    }else if(val < minLen){
        DFS(val,i);
		if ( exist == true )
			return;
        val -= parts[i];
        visited[i]=0;
        DFS(val,i-1);
    }else{
        val -= parts[i];
        visited[i]=0;
        DFS(val,i-1);
    }
	if ( exist == true )
			return;
}
int cmp(const void* x,const void *y){
    return *((int*)x)-*((int*)y);
}
int main(){
    scanf("%d",&num);
    while(num!=0){
        int tmp;
        minLen=sum=0;
        for(int i=1;i<=num;i++){
            scanf("%d",&tmp);               
            parts[i] = tmp;
            if(minLen<tmp) minLen=tmp;
            sum += tmp;
        }
        qsort(parts,num+1,sizeof(int),cmp);
        exist=false;
        counter=0;
        for(;minLen<=sum;minLen++){
            if(sum%minLen!=0) continue;
            for(int r=1;r<=num;r++) visited[r]=0;       //init    
            DFS(0,num);
            if(exist) break;
        }
        printf("%d\n",minLen);
        scanf("%d",&num);
    }
    //system("pause");
    return 0;
}  
*/