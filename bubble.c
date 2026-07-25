#include<stdio.h>
void bubble(int a[],int n){
	int i,j,temp;
	int pass=1;
	int flag;
	for(i=0;i<n-1;i++){
		flag=0;
		printf("pass:%d",i+1);
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[i];
				a[i]=a[j+1];
				a[j+1]=temp;
				flag=1;
				printf("Interation:%d",j+1);
			}
		for(j=0;j<n;j++){
			printf("%d",a[j]);
			}
		}
	    if(flag==0){
		return;
	}
	}
}
int main(){
	int n;
	printf("enter number of element:");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("bubble sort\n");
	bubble(a,n);
	for(int k=0;k<n;k++){
		printf("%d",a[k]);
	}
	printf("\n");
	return 0;	
}
		
		
