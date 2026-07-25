#include<stdio.h>
#define m 5
int q[m];
int f=-1,r=-1;
int isfull(){
	return f==(r+1)%m;
}
void enqueue(int v){
	if(isfull()){
		printf("is full");
	}
	else{
		if(f==-1){
		f=r=0;
		}
	    else{
		  r=(r+1)%m;;
	    }
	    q[r]=v;
	    printf("element inserted:%d\n",v);
	}
}
void dequeue(){
	if(f!=-1){
		printf("deleted:%d\n",q[f]);
		if(f==r){
			f=r=-1;
		}
		f=(f+1)%m;
	}
	else{
		printf("the queue is empty\n");
    } 
}
void display(){
	if(f!=-1){
		int i=f;
		while(1){
			printf("element:%d\n",q[i]);
			if(i==r)break;
			i=(i+1)%m;
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
	enqueue(50);
	enqueue(60);
	display();
	dequeue();
	display();
	return 0;
}

