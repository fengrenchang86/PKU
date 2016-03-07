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
    int i;
    for(i=loc;i>0;i--)
        if(visited[i]==0) break;
    if(i==0) return;
    val += parts[i];
    visited[i]=1;
    if(val == minLen){
        counter++;
        DFS(0,num);
        counter--;
        val-=parts[i];
        visited[i]=0;
        DFS(val,i-1);
    }else if(val < minLen){
        DFS(val,i);
        val -= parts[i];
        visited[i]=0;
        DFS(val,i-1);
    }else{
        val -= parts[i];
        visited[i]=0;
        DFS(val,i-1);
    }
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