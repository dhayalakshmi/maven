#include<stdio.h>
int m=100;
int q[100];
int f=-1,r=-1;
void enqueue(int v){
	if((r+1)<=m){
		if(f==-1){
		f=r=0;
	    }
        else{
		  r++;
    	}
	    q[r]=v;
	    printf("element inserted:%d\n",v);
	}
	else{
		printf("is full\n");
	}
}
void dequeue(){
	if(f!=-1){
		printf("deleted:%d\n",q[f]);
		if(f>r){
			f=r=-1;
		}
		f++;
	}
	else{
		printf("the queue is empty\n");
	}
}
void display(){
	if(f!=-1){
		for(int i=f;i<=r;i++){
		printf("elements:%d\n",q[i]);
		}
	}
	else{
	    printf("the queue is empty\n");
	}
}
int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	display();
	dequeue();
	display();
	return 0;
}

