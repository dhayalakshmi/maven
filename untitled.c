#include<stdio.h>
#define MAX 5;
int s[MAX];
int top=-1;
void push(int v){
	if(top>=MAX-1){
		printf("stack is full");
		return;
	}
	st[++top]=v;
	printf("%d is pushed\n",v);
}
int pop(){
	if(top==-1){
		printf("stack is empty");
		return;
	}
	return st[top--];
}
int peek(){
	if(top==-1){
		printf("stack is empty");
		return;
	}
	return st[top];
}
void display(){
	if(top==-1){
		printf("stack is empty");
		return;
	}
	for (int i=top;i>=0;i--){
		printf("stack element",st[i]);
	}
}
void search(int v){
	if(top==-1){
		printf("stack is empty");
		return;
	}
	for (int i=top;i>=0;i--){
		if(v==st[i]){
			printf("found\n");
			printf("%d found at postion %d\n",v,top-i+1);
		}
	}
	printf("not found");
}
int main(){
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	display();
	pop();
	display();
	printf("top element:%d",peek());
	search(20);
	search(30);
	return 0;
}
	
	
	
