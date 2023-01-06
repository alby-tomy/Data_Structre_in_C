#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next_add;
};

void insert_at_begingin(struct node **head, int data_para){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = data_para;
	new_node -> next_add = *head;

	*head = new_node;
}

void insert_at_end(struct node **head, int data_para){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = data_para;
	new_node -> next_add = NULL;
	if(*head==NULL){
		*head = new_node;
		return;
	}

	//find the last node
	struct node *ptr = *head;
	while(ptr->next_add !=NULL){
		ptr = ptr->next_add;
	}

	ptr->next_add = new_node;
}

void insert_after(struct node *prev_node, int data_input){
	if(prev_node == NULL){
		printf("\nThe given previous node cannot be NULL\n");
		return;
	}

	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = data_input;
	new_node -> next_add = prev_node -> next_add;
	prev_node -> next_add = new_node;
}

void delete_node(struct node **head, int key){
	struct node *temp = *head, *prev;
	if(temp != NULL && temp->data == key){
		*head = temp->next_add;
		free(temp);
		return;
	}

	//searching for key
	while(temp != NULL && temp->data != key){
		prev = temp;
		temp = temp->next_add;
	}

	if(temp == NULL) return;

	prev ->next_add = temp->next_add;
	free(temp);
}

int main(){
	struct node *head = NULL;

	printf("\nEnter a series of integers, followed by a non-integer character : \n");
	int data;
	while(scanf("%d", &data)==1){
		insert_at_end(&head,data);
	}

	//printing linked list
	struct node *ptr = head;
	printf("\n");
	while(ptr != NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next_add;
	}

	printf("\n[*] Select from the optios : \n");
	printf("\n\t[1] Insert in the begining");
	printf("\n\t[2] Insert at the end");
	printf("\n\t[3] Insert after a node");
	printf("\n\t[4] Delete a node");
	printf("\n[*] Enter your choice : ");
	int options;
	scanf("%d",&options);

	switch(options){
		case 1:
			int data_in;
			printf("Enter the value to insert at begining : ");
			scanf("%d",&data_in);
			insert_at_begingin(&head, data_in);
			break;

		case 2:
			int data_end;
			printf("Enter the value at end :");
			scanf("%d",&data_end);
			insert_at_end(&head, data_end);
			break;
		default :
			printf("invalid input...");
			break;
	}
	printf("\nEnter the data value of node to delete : ");
	scanf("%d",&data);

	delete_node(&head, data);

	//printing out the node
	ptr = head;
	printf("\nupdated data\n");
	while(ptr != NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next_add;
	}
	printf("\n");
	return 0;
}
