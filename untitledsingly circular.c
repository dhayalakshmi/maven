#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head=NULL;
struct node*create(int d){
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=d;
	new->next=NULL;
	return new;
}
void insert(int d){
	struct node*new=create(d);
	if(head==NULL){
		head=new;
		new->next=head;
	}
	else{
		struct node*temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=new;
		new->next=head;
		head=new;
	}
	printf("%d\n",d);
}
void insertend(int d){
	struct node*new=create(d);
	if(head==NULL){
		head=new;
		new->next=head;
	}
	else{
		struct node*temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=new;
		new->next=head;
	}
}
void insertpos(int d,int pos){
	struct node*new=create(d);
	if(head==NULL){
		head=new;
		new->next=head;
	}
	if(pos<1){
		printf("position is invalid");
	}
	int count=0;
	struct node*temp=head;
	while(temp->next!=head&&count<pos){
		temp=temp->next;
		count++;
	}
	new->next=temp->next;
	temp->next=new;
	printf("%d\n",d);
	
}
void display(){
	struct node*temp=head;
	while(temp!=head){
		printf("display:%d",temp->data);
		temp=temp->next;
		}
}
		
int main(){
	insert(20);
	insert(30);
	insert(50);
	insertend(90);
	insertpos(55,2);
	display();
	return 0;
}
		
	
	

	
	

