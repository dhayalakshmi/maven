#include<stdio.h>
void swap(int a[],int x,int y){
	int t=a[x];
	a[x]=a[y];
	a[y]=t;
}
void heapify(int a[],int n,int i){
	int l=i*2+1;
	int r=i*2+2;
	int m=i;
	while(l<n&&a[l]>a[m]){
		m=l;
	}
	while(r<n&&a[r]>a[m]){
		m=r;
	}
	if(m!=i){
		swap(a,i,m);
		heapify(a,n,m);
	}
}
void heap(int a[],int n){
	int pass=1;
	for(int i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	printf("max heap");
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
	for(int i=n-1;i>0;i--){
		swap(a,0,i);
		heapify(a,i,0);
	}
	printf("%d\n",pass++);
	for(int k=0;k<n;k++){
		printf("%d",a[k]);
	}
	printf("\n");
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
	heap(a,n);
	for(int k=0;k<n;k++){
		printf("%d",a[k]);
	}
	printf("\n");
	return 0;
}



	
