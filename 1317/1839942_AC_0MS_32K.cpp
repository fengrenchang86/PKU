#include <iostream.h>
void main ()
{
	char list[29] = {"_abcdefghijklmnopqrstuvwxyz."};
	int plaincode[100];
	int ciphercode[100];
	char plaintext[100];
	char ciphertext[100];
	int n;
	int i;
	int key;
	while ( cin>>key && key!=0 && cin>>ciphertext)
	{
		for ( i = 0; ciphertext[i] != NULL; i++ )
		{
			if ( ciphertext[i] == '_' )
				ciphercode[i] = 0;
			else if ( ciphertext[i] == '.' )
				ciphercode[i] = 27;
			else
				ciphercode[i] = ciphertext[i] - 'a' +1;
		}
		n = i;
		for ( i = 0; i < n; i++ )
		{
			plaincode[(key*i)%n] = (ciphercode[i] +i)%28;
		}
		for ( i = 0; i < n; i++ )
		{
			plaintext[i] = list[plaincode[i]];
			cout<<plaintext[i];
		}
		cout<<endl;
		
	}
	

}