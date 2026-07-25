#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node*next;
};
struct node*f=NULL;
struct node*r=NULL;
struct node*create(int v){
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->d=v;
	new->next=NULL;
	return new;
}
void enqueue(int v){
	struct node*new=create(v);
	if(f==NULL){
		r=f=new;
	}
	r->next=new;
	r=new;	
}
void dequeue(){
	if(f==NULL){
		printf("queue is empty\n");
	}
	struct node*temp=f;
	f=temp->next;
	free(temp);	
}
void display(){
	if(f==NULL){
		printf("queue is empty\n");
	}
	struct node*temp=f;
	while(temp!=NULL){
		printf("display:%d\n",temp->d);
		temp=temp->next;
	}
}
int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	display();
	dequeue();
	display();	
}
