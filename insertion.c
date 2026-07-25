#include<stdio.h>
void insert(int a[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=a[i];
		for(j=i-1;j>=0;j--){
			if(a[j]>temp){
				a[j+1]=a[j];
			}
			else{
				break;
			}
		}
		a[j+1]=temp;
		printf("pass:%d",i);
		for(j=0;j<n;j++){
			printf("%d",a[j]);
		}
		printf("\n");
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
	printf("heap sort\n");
	insert(a,n);
	for(int k=0;k<n;k++){
		printf("%d",a[k]);
	}
	printf("\n");
	return 0;	
}
		
