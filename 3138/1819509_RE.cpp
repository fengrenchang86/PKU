#include <iostream.h>
void main ( )
{
	int *S = new int[];
	int *T = new int[];
	int *M = new int[];
	int *ca = new int[];
	int *cb = new int[];
	int *id = new int[];
	int *Id = new int[];
	int i = 0;
	int j = 0;
	int k = 0;
	int *tot = new int[];
	int count = 0;
	int *save = new int[];
	int c = 1;
	do
	{
	cin>>S[i]>>T[i]>>M[i];
	if ( S[i] == 0 && T[i] == 0 && M[i] == 0 )
		break;
	int *school = new int[S[i]];
	for ( j = 0; j < S[i]; j++ )
		cin>>id[j]>>ca[j]>>cb[j];
	for ( j = 0; j < T[i]; j++ )
		cin >> Id[j] >> tot[j];
	for ( j = 0; j < S[i]; j++ )
		school[j] = 0;
	for ( j = 0; j < S[i]; j++ )
		school[id[j] - 1] = ca[j] + cb[j];
	for ( j = 0; j < T[i]; j++ )
	{
		if ( tot[j] >= M[i] )
			school[Id[j] - 1]++;
	}
	for ( j = 0; j < S[i]; j++ )
	{
		if ( school[j] > 3 )
			school[j] =3;
		count += school[j];
	}
	save[i] = count;
	save[i+1] = -1;
	count = 0;
	i++;
	}while ( 1 );
	for ( i = 0; save[i] != -1; i++)
		cout<<"Case "<<i+1<<": "<<save[i]<<endl;
}