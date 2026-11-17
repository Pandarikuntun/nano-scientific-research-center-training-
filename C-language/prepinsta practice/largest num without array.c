#include<stdio.h>
int main(){
int count,max,current;
printf("number of element\n");
scanf("%d",&count);
printf("enter the number1\n");
scanf("%d",&max);
for(int i=1;i<=count;i++){
	printf("enter the number \n");
	scanf("%d",&current);
		if(current>=max){
			max=current;
		}
	}
printf("largest number is %d\n",max);
return 0;
}

