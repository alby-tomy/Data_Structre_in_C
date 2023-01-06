#include<stdio.h>

struct Node{
	int data;
	struct Node *next_address;
};

int main(){
	struct node *head = malloc(sizeof(struct node));
	head -> data = 45;
	head -> next_address = NULL;

	struct node *current = malloc(sizeof(struct node));
	current->data = 30;
	current->next_address = NULL;
	head->next_address = current;

	struct node *current = malloc(sizeof(struct node));
	current->data = 23;
	current->next_address = NULL;
	head -> next_address->next_address = current;
	return 0;
}


