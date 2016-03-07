#include <iostream.h>
void main ( )
{
	int S;
	int T;
	int M;
	int ca;
	int cb;
	int id;
	int i;
	int tot;
	int count = 0;
	int *save = new int[];
	int c = 1;
	do
	{
	cin>>S>>T>>M;
	if ( S == 0 && T == 0 && M == 0 )
		break;
	int *school = new int[S];
	for ( i = 0; i < S; i++ )
		school[i] = 0;
	for ( i = 0; i < S; i++ )
	{
		cin >> id >> ca >> cb;
		school[id - 1] = ca + cb;
	}
	for ( i = 0; i < T; i++ )
	{
		cin >> id >> tot;
		if ( tot >= M )
		school[id - 1]++;
	}

	for ( i = 0; i < S; i++ )
	{
		if ( school[i] > 3 )
			school[i] = 3;
		count += school[i];
	}
	save [c - 1] = count;
	c++;
//	cout<<count;
	delete school;
	}while ( S != 0 || T != 0 || M != 0 );
	save [c - 1] = -1;
	for ( i = 0; save[i] != -1; i++)
		cout<<"Case "<<i+1<<": "<<save[i]<<endl;
}