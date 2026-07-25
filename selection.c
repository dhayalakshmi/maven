#include<stdio.h>
void selection(int a[],int n){
	int i,j,temp,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
			if(min!=i){
				temp=a[i];
				a[i]=a[min];
				a[min]=temp;
			}
		}
		printf("interation:%d\n",i+1);
		for(j=0;j<n;j++){
			printf("%d",a[j]);
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
	printf("selection sort\n");
	selection(a,n);
	for(int k=0;k<n;k++){
		printf("%d",a[k]);
	}
	printf("\n");
	return 0;	
}

		
