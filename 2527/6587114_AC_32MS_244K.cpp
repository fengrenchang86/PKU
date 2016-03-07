#include <iostream>
using namespace std;
int *a, *b;
int sizea, sizeb, sizec;
int main()
{
	a = new int[10010];
	b = new int[10010];
	int i, A, T, k;
	while (scanf("%d %d", &sizea, &sizeb) != EOF)
	{
		if (sizea == -1 && sizeb == -1)
		{
			break;
		}
		for (i = 0; i <= sizea; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 1; i < sizeb; i++)
		{
			b[i] = 0;
		}
		b[0] = 1;
		b[sizeb] = 1;
		while (sizea >= sizeb)
		{
			T = sizea - sizeb;
			A = a[sizea];
			a[T] -= A;
			sizea --;
			while (sizea >= 0 && a[sizea] == 0)
			{
				sizea--;
			}
		}
		if (sizea < 0)
		{
			printf("0\n");
			continue;
		}
		for (i = 0; i <= sizea; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	delete a;
	delete b;
	return 0;
}