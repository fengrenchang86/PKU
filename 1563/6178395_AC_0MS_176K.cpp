#include <iostream>
using namespace std;
int H, U, D, F;
int main()
{
	int i;
	double nCanClimb, nSub;	
	double dCurPos;
	while (scanf("%d %d %d %d", &H, &U, &D, &F) != EOF)
	{
		if (H == 0)
		{
			break;
		}
		nSub = (double)U * (double)F / double(100.0);
		nCanClimb = U;
		dCurPos = 0.0;
		for (i = 1; ; i++)
		{
			if (nCanClimb > 0)
			{
				dCurPos += nCanClimb;
				nCanClimb -= nSub;
			}
			if (dCurPos > H)
			{
				printf("success on day %d\n", i);
				break;
			}
			dCurPos -= (double)D;
			if (dCurPos < 0.0)
			{
				printf("failure on day %d\n", i);
				break;
			}
		}
	}
	return 0;
}