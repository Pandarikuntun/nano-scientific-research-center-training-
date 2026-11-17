#include<stdio.h>
int main(){
	int num,i;
	scanf("%d",&num);
	printf("prime factores of num :");
	for(i=2;num>1;i++){
		
		while(num%i==0){
			printf("%d ",i);
			num=num/i;
		}
	
	}
	return 0;
}
