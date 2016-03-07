#include <iostream>
using namespace std;
int main()
{
    char a[600],b[600];
    int i,j;
    while(cin>>a>>b)
    {
       int n=strlen(a),m=strlen(b),l[505][505]={0};
       for(i=0;i<n;i++)
           for(j=0;j<m;j++)
           {
              if (a[i]==b[j])
                   l[i+1][j+1]=l[i][j]+1;
              else  if(l[i][j+1]>l[i+1][j])
                       l[i+1][j+1]=l[i][j+1];
                    else  l[i+1][j+1]=l[i+1][j];
           }  
        cout<<l[n][m]<<endl;           
    }
    return 0;
}