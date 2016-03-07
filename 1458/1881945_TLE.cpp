#include<stdio.h>
#include<string.h>
char a[501],b[501],c[501][501];
int main()
{freopen("in.txt","r",stdin);
 int i,j,na,nb;
 while(scanf("%s%s",a,b)!=EOF)
 {
  na=strlen(a);nb=strlen(b);
  for(i=0;i<=na;i++)c[i][0]=0;
  for(j=0;j<=nb;j++)c[0][j]=0;
  for(i=1;i<=na;i++)
    for(j=1;j<=nb;j++)
    { if(a[i-1]==b[j-1])c[i][j]=c[i-1][j-1]+1;
      else if(c[i][j-1]>c[i-1][j]) c[i][j]=c[i][j-1];
      else c[i][j]=c[i-1][j];
    }  
  printf("%d\n",int(c[na][nb]));
 }while(1);
}

