#include <iostream.h>
#include <math.h>
void main ()
{
	int rgb[16][3] ;
	int i;
	int j;
	int data[100][3] ;
	double min = 9999999;
	double temp;
	int count;
	int pos[50];
	for ( i = 0; i < 16; i++ )
		cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
	for ( i = 0; i < 16; i++ )
	{
		cin>>data[i][0]>>data[i][1]>>data[i][2];
		if ( data[i][0] == -1 && data[i][1] == -1 && data[i][2] == -1 )
			break;
	}
	count = i;
	for ( i = 0; i < count; i++ )
	{
		min = 9999999;
		for ( j = 0; j < 16; j++ )
		{
			temp = ( rgb[j][0] - data[i][0] ) * ( rgb[j][0] - data[i][0] )
				+ ( rgb[j][1] - data[i][1] ) * ( rgb[j][1] - data[i][1] )
				+ ( rgb[j][2] - data[i][2] ) * ( rgb[j][2] - data[i][2] );
			temp = sqrt ( temp );
			if ( min - temp >= 0.0000001 )
			{
				min = temp;
				pos[i] = j;
			}
		}
	}
	for ( i = 0; i < count; i++ )
		cout<<"("<<data[i][0]<<','<<data[i][1]<<','<<data[i][2]<<") maps to ("<<
		rgb[pos[i]][0]<<','<<rgb[pos[i]][1]<<','<<rgb[pos[i]][2]<<")"<<endl;

}