#include<iostream.h>
#include<math.h>
#define  PI 3.14
void main()
{
	int n;
	float max[10];
	int ans[10];
	float r;
	float x;
	float y;
	cin>>n;
	for ( int i = 0; i < n; i++ )
	{
		cin>>x;
		cin>>y;
		r = sqrt (x*x+y*y);
		max[i] = x > y ? x:y;
		ans[i] = PI * r * r /100;
		ans[i]++;
	}
	for ( int j = 1; j <= n; j++ )
	{
		cout<<"Property "<<j<<": This property will begin eroding in year "<<ans[j-1]<<'.'<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	
}