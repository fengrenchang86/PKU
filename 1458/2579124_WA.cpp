#include<iostream>
using namespace std;
int main()
{   

	char a[800];
	char b[800];
	while(cin>>a>>b)
	{
	 int L[800][800];

    int i,j;
L[0][0] = 0;
     for(i = 0; a[i]; i++)
		 for(j = 0; b[j]; j++)
		 {
			 if(i == 0 || j ==0 )
			 {
				 if(a[i] == b[j])
					 L[i][j] = 1;
				 else
					 L[i][j] = L[0][0];
				 continue;
			 }
			 if(a[i] == b[j])
				 L[i][j] = L[i-1][j-1] + 1;
			 else
				 L[i][j] = L[i][j-1] > L[i-1][j] ? L[i][j-1] : L[i-1][j];
		 }
		 cout<<L[i-1][j-1]<<endl;
	}
	return 0;
}