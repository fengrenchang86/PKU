#include<iostream>
using namespace std;
int main()
{   

	char temp1[800];
	char temp2[800];
	while(scanf("%s %s",temp1,temp2) != EOF)
	{
     char a[800];
	 char b[800];
	
	 int L[800][800];
	int n,m;
	n = m = 0;

    int i,j;
	i = 1;
	j  = 1;
	while(temp1[i] != '\0' && temp2[i] != '\0') 
	{
		a[j] =temp1[i];
		b[j] = temp2[i];
          i++;
		  j++;
		  
	}
	n = m = j - 1;
	if(temp1[i] != '\0')
	{
	while(temp1[i] != '\0')
	{
		a[j] = temp1[i];
		i++;
		j++;
		n++;
	}
	}
	else
	{
	while(temp2[i] != '\0')
	{
		b[j] = temp1[i];
		i++;
		j++;
		m++;
	}
	}



	
	for(i = 0; i <= n; i++)
	{
        L[i][0] = 0;
	}
    for(i; i <= m; i++)
	{
       L[0][i] = 0;
	}
     for(i = 1; i < n; i++)
		 for(j = 1; j <m; j++)
		 {
			 if(a[i] == b[j])
				 L[i][j] = L[i-1][j-1] + 1;
			 else
				 L[i][j] = L[i][j-1] > L[i-1][j] ? L[i][j-1] : L[i-1][j];
		 }
		 cout<<L[n][m]<<endl;
	}
	return 0;
}