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
		new->next=head;
		temp->next=new;
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
	int count=1;
	struct node*temp=head;
	while(temp->next!=head&&count<pos-1){
		temp=temp->next;
		count++;
	}
	if(count<pos-1){
		printf("position%dout of range.\n",pos);
		free(new);
		return;
	}
	new->next=temp->next;
	temp->next=new;
	printf("%d\n",d);
	
}
void display(){
	if(head==NULL){
		printf("list is empty");
		return;
	}
	struct node*temp=head;
	printf("circular\n");
	do{
		printf("%d->",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("back to head\n");
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
		
	
	

	
	


