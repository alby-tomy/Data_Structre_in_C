#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	struct Node *next_address;
};


void printList(struct Node *n){
	while (n != NULL){
		printf(" %d",n->data);
		n = n->next_address;
	}
	printf("\n");
}


int main(){
	struct Node *head = NULL;
	struct Node *first = NULL;
	struct Node *second = NULL;
	struct Node *tail = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	tail = (struct Node*)malloc(sizeof(struct Node));


	head -> data = 1;
	head -> next_address = first;

	first -> data = 2;
	first -> next_address = second;

	second -> data = 3;
	second -> next_address = tail;

	tail -> data = 4;
	tail -> next_address = NULL;

	printList(head);
	return 0;
}
