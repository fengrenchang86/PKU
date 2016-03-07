#include<iostream>
using namespace std;
#define nNum 1000100
__int64 nUP[nNum];
__int64 nDown[nNum];
__int64 nMid[nNum];
__int64 chang[nNum];
__int64 hui[2][nNum];
int nBeginX, nBeginY, nEndX, nEndY, nN;
int LoveHH(int hui, int chang)
{
	return hui < chang ? hui:chang;
}
void Input()
{
	int i;
	scanf("%d%d%d%d", &nBeginX, &nBeginY, &nEndX, &nEndY);
	for(i = 1; i <= nN; i++)
		scanf("%d",&nUP[i]);
	for(i = 0; i <= nN; i++)
		scanf("%d",&nMid[i]);
	for(i = 1; i <= nN; i++)
		scanf("%d",&nDown[i]);
}
void MissHH()
{
	int i;
	for(i = 1; i <= nN; i++)
		nMid[i] = LoveHH(nMid[i], nMid[i-1] + nUP[i] + nDown[i]);
	for(i = nN-1; i >= 1; i--)
		nMid[i] = LoveHH(nMid[i], nMid[i+1] + nUP[i] + nDown[i]);
	hui[nBeginX][nBeginY] = 0;
	hui[!nBeginX][nBeginY] = nMid[nBeginY];
	if(nEndY > nBeginY)
	{
		for(i = nBeginY+1; i <= nEndY; i++)
		{
			hui[0][i] = LoveHH(hui[0][i-1] + nUP[i], hui[1][i-1] + nDown[i] + nMid[i]);
			hui[1][i] = LoveHH(hui[1][i-1] + nDown[i], hui[0][i-1] + nUP[i] + nMid[i]);
		}
	}
	else
	{
		for(i = nBeginY-1; i >= nEndY; i--)
		{
			hui[0][i] = LoveHH(hui[0][i+1] + nUP[i+1], hui[1][i+1] + nDown[i+1] + nMid[i]);
			hui[1][i] = LoveHH(hui[1][i+1] + nDown[i+1], hui[0][i+1] + nUP[i+1] + nMid[i]);
		}
	}
	printf("%I64d\n",hui[nEndX][nEndY]);
}
int main ()
{
	while(scanf("%d",&nN)!=EOF)
	{
		if(!nN)
			break;
		Input();
		MissHH();
	}
	return 0;
}