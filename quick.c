#include<stdio.h>
void swap(int *a,int *b){
	int bt=*a;
	*a=*b;
	*b=bt;
}
int part(int a[],int lb,int ub){
	int p=a[lb];
	int s=lb;int e=ub;
	while(s<e){
		while(a[s]<=p &&s<ub){
			s++;
		}
		while(a[e]>p){
			e--;
		}
		if(s<e){
			swap(&a[s],&a[e]);
		}
	}swap(&a[lb],&a[e]);
	return e;
}
void quick(int a[],int lb,int ub){
	if(lb<ub){
		int l=part(a,lb,ub);
		quick(a,lb,l-1);
		quick(a,l+1,ub);
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
	printf("quick sort\n");
	quick(a,0,n-1);
	printf("after sort");
	for(int k=0;k<n;k++){
		printf("%d",a[k]);
	}
	printf("\n");
	return 0;	
}
		
	
