#include<iostream>
using namespace std;
int main()
{   

	char a[400];
	char b[400];
	while(cin>>a>>b)
	{
	 int L[400][400];

    int i,j;
     for(i = 0; a[i]; i++)
		 for(j = 0; b[j]; j++)
		 {
			 if(i == 0 || j ==0 )
			 {
				 if(a[i] == b[j])
					 L[i][j] = 1;
				 else
				 {
					 if(i == 0 && j != 0)
					 {
						 L[i][j] = L[i][j-1];
					 }
					 else if(i != 0 && j == 0)
					 {
						 L[i][j] = L[i - 1][j];
					 }
					 else
					 {
						 L[i][j] = 0;
					 }
				 }

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
