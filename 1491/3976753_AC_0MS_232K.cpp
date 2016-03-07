#include<iostream>
#include<math.h>
using namespace std;
int a[100];
int n;
int X, Y;
int MeetHH(int x, int y)
{
	if(x%y == 0)
		return y;
	else
		return MeetHH(y, x%y);
}
void MissHH()
{
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	X = n * (n-1) / 2;
}
void LoveHH()
{
	int i, j;
	Y = 0;
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if(MeetHH(a[i], a[j]) == 1)
				Y++;
		}
	}
	if(Y == 0)
	{
		printf("No estimate for this data set.\n");
		return;
	}
	double HH = 6.0*double(X)/(double)Y;
	HH = sqrt(HH);
	printf("%.6lf\n", HH);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		MissHH();
		LoveHH();
	}
	return 0;
}