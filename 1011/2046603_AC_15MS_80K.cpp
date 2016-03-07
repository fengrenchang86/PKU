
#include <iostream>
//#include <fstream>
using namespace std;
int flag = 0;
int lay = 0;
int l[100];
int a[100];
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
int f ( int t, int sum, int position, int max, int n )
{
	if ( t == sum )
	{
		if ( max-sum == sum )
		{
			flag = 1;
			return 1;
		}
		position = 1;
		while ( l[position] == 1 && position <= n )
			position++;
		if ( position > n )
			return 0;
		l[position] = 1;
		f ( a[position], sum , position+1, max-sum,n);
		l[position] = 0;
	if ( max-sum == sum )
		flag = 1;
	//	if ( flag == 1 )
	//		return 1;
	/*	if ( lay == 0 )
		{
			flag = -1;
			return 0;
		}*/
	}
	else
	{
		int pos = position;
		while ( a[pos] + t > sum || l[pos] == 1 )
		{
			pos++;
			if ( pos > n )
				break;
		}
		if ( pos > n )
			return 0;
		position = pos;
		t+=a[position];
			if (a[position] != a[position-1])
			{
				l[position] = 1;
				f(t,sum,position+1,max,n);
				l[position] = 0;
			}
			else if (l[position-1] == 1)
			{
				l[position] = 1;
				f(t,sum,position+1,max,n);
				l[position] = 0;
			}
		if ( flag == 1 )
			return 1;
		
		if ( t != sum )
		{
			l[position] = 0;
			t -= a[position];
			f(t,sum,position+1,max,n);
		}
	}
	
	return 1;
}
int main ()
{
//	ofstream fop ("out.txt");
	int n,i;
	int sum;
	while ( scanf("%d",&n) && n!=0 )
	{
		for ( i = 1; i <= n; i++ )
			l[i] = 0;
		sum = 0;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&a[i]);
			if ( a[i] > 50 )
			{
				i--;
				n--;
				continue;
			}
			sum += a[i];
		}
		if ( n == 1 )
		{
	//		fop<<a[1]<<endl;
	//		flush(cout);
			cout<<a[1]<<endl;
			continue;
		}
		qs(a,1,n);
		a[0] = -1;
		for ( i = 1; i < 100; i++ )
			l[i] = 0;
		l[0] = 1;
		for ( i = a[1]; i<=(sum+1)/2; i++ )
		{
			if ( sum%i==0)
			{
				f(0,i,1,sum,n);
				if ( flag == 1 )
					break;
			}
		}
		if ( flag == 1 )
	//		fop<<i<<endl;
			cout<<i<<endl;
		else
//			fop<<sum<<endl;
			cout<<sum<<endl;
//		flush(cout);
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