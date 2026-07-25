#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node*next;
};
struct node*top=NULL;
struct node*create(int v){
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->d=v;
	new->next=NULL;
	return new;
}
void push(int v){
	struct node*new=create(v);
	new->next=top;
	top=new;
}
void pop(){
	if(top==NULL){
		printf("is empty");
	}
	struct node*temp=top;
	top=top->next;
	free(temp);
}
void peek(){
	if(top==NULL){
		printf("is empty");
	}
	printf("top element:%d\n",top->d);
}
void display(){
	if(top==NULL){
		printf("is empty");
	}
	struct node*temp=top;
	while(temp!=NULL){
		printf("display:%d\n",temp->d);
		temp=temp->next;
	}
}
int main(){
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	display();
	pop();
	display();
	peek();
	return 0;
	
}
