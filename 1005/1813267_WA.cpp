#include<iostream.h>
#define  PI 3.14
void main()
{
	int n;
	float max[10];
	int ans[10];
	float x;
	float y;
	cin>>n;
	for ( int i = 0; i < n; i++ )
	{
		cin>>x;
		cin>>y;
		max[i] = x > y ? x:y;
		ans[i] = PI * max[i] * max[i] /100;
		ans[i]++;
	}
	for ( int j = 1; j <= n; j++ )
	{
		cout<<"Property "<<j<<": This property will begin eroding in year "<<ans[j-1]<<'.'<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	
}