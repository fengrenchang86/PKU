#include<iostream.h>
void main()
{
	float sum=0;
	float input;
	for ( int i=0; i<12; i++)
	{
		cin>>input;
		sum += input;
	}
	sum = sum/12;
	cout<<'$'<<sum;
}