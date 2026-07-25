#include<stdio.h>
void shell(int a[],int n){
	int g,i,j,k,temp;
	for(g=n/2;g>0;g=g/2){
		printf("gap:%d,interation",g,i+1);
		for(i=g;i<n;i++){
			temp=a[i];
			for(j=i-g;j>0;j=j-g){
				if(a[j]>temp){
					a[j]=
