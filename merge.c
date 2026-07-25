#include<stdio.h>
void merge(int a[],int lb,int m,int ub,int n){
	int i=lb;int k=lb,j=m+1;
	int b[n];
	while(i<=m&&j<=ub){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
		}else{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=m){
		b[k]=a[i];
		i++;
		k++;
	}

    while(j<=ub){
		b[k]=a[j];
		j++;
		k++;
	}
	for(int i=lb;i<=ub;i++){
		a[i]=b[i];
	}
	printf("merge");
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
void mergesort(int a[],int lb,int ub,int n){
	if(lb<ub){
		int m=(lb+ub)/2;
		mergesort(a,lb,m-1,n);
		mergesort(a,m+1,ub,n);
		merge(a,lb,m,ub,n);
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
	printf("merge sort\n");
	mergesort(a,0,n-1,n);
	for(int k=0;k<n;k++){
		printf("%d",a[k]);
	}
	printf("\n");
	return 0;
}


		
	

