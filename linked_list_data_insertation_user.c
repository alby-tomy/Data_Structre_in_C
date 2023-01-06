#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};

void insert_at_end(struct node **head, int data){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = data;
	new_node -> next = NULL;

	if(*head == NULL){
		*head = new_node;
		return;
	}

	struct node *ptr = *head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}

	ptr->next = new_node;
}

int main(){
	struct node *head = NULL;

	printf("Enter a series of integers, followed by by a non-integer character : ");
	int data;
	while(scanf("%d",&data)==1){
		insert_at_end(&head, data);
	}


	struct node *ptr = head;
	while(ptr != NULL){
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	}
	return 0;
}
