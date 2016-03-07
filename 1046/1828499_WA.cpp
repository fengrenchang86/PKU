#include <iostream.h>
#include <math.h>
void main ()
{
	int rgb[16][3] = {{0,0,0},{255,255,255},{0,0,1},{1,1,1},{128,0,0},{0,128,0},{128,128,0},{0,0,128},{126,168,9},{35,86,34},{133,41,193},{128,0,128},{0,128,128,},{128,128,128},{255,0,0},{0,1,0}};
	int i;
	int j;
	int data[20][3] = {{0,0,0},{255,255,255},{253,254,255},{77,79,134},{81,218,0}};
	double min = 9999999;
	double temp;
	int count;
	int pos[5];
//	for ( i = 0; i < 16; i++ )
//		cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
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
			if ( temp < min )
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