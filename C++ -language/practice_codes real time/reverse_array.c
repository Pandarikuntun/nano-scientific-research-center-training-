#include<stdio.h>
#define N 99
int main(){
	int arr[N]={[1]=5,[3]=5,[4]=5,[8]=0};	//1=5,3=5, 4=2
	for(int i=0;i<=N;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	for(int i=N;i>=0;i--){
		printf("%d ",arr[i]);
	}
}
