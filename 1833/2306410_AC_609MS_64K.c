#include <stdio.h>
void main()
{
	int test,num,counter,i,j,k,temp;
	int input[1030]={0};
	scanf("%d",&test);
	while(test>0){
		scanf("%d%d",&num,&counter);
		for(i=0;i<num;i++)scanf("%d",&input[i]);
		if(num==1)printf("1\n");
		else {
			while(counter>0){
				for(j=num-1;j>=1;j--)if(input[j]>input[j-1])break;
				if(j==0){
					counter--;
					for(i=0,j=num-1;i<j;i++,j--){
						temp=input[i];
						input[i]=input[j];
						input[j]=temp;
					}
				}
				else {
					counter--;
					for(i=num-1;i>=j;i--)if(input[i]>input[j-1])break;
					temp=input[j-1];
					input[j-1]=input[i];
					input[i]=temp;
					for(i=j,k=num-1;i<k;i++,k--){
						temp=input[i];
						input[i]=input[k];
						input[k]=temp;
					}
				}
			}
			for(i=0;i<num;i++)printf("%d%c",input[i],i<num-1?' ':'\n');
		}
		test--;
	}
}
