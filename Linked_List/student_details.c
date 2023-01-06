#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student_details{
	char *student_name;	
	int student_age;
	int student_class;
	struct student_details *next_add;
};


void insert_at_end(struct student_details **head, char *name, int age, int class)
{
	struct student_details *new_student_node = (struct student_details*)malloc(sizeof(struct student_details));
	

	//set the datats for new nodes
	new_student_node -> student_name = (char*)malloc(strlen(name)+1);
	strcpy(new_student_node -> student_name,name);
	new_student_node -> student_age = age;
	new_student_node -> student_class = class;
	
	//set the next pointer for the new node to NULL
	new_student_node -> next_add = NULL;


	if(*head == NULL){
		*head = new_student_node;
		return;
	}
	else{

		struct student_details *ptr = *head;
		while(ptr -> next_add != NULL)
		{
			ptr = ptr -> next_add;
		}

		ptr -> next_add = new_student_node;
	}
}

int main(){
	struct student_details *head = NULL;
	int size;
	printf("Enter the number of nodes to insert : ");
	scanf("%d",&size);

	for(int i=0;i<size;i++){
		int age,class;
		char name[100];

		printf("\nEnter the name of the student : ");
                scanf("%s",name);

		printf("Class studying : ");
		scanf("%d",&class);
		
		printf("Age of the student : ");
		scanf("%d",&age);
		
		printf("\n");
		
		insert_at_end(&head, name, age, class);
	}

	struct student_details *ptr = head;
	printf("\nDetails of the Stdent Entered");
	printf("\n\tName\t||\tClass\t||\tAge\n\n");
	printf("-------------------------------------------------\n");
	while(ptr != NULL){
		printf("\t%s",ptr->student_name);
		printf("\t||\t%d",ptr->student_class);
		printf("\t||\t%d",ptr->student_age);
		ptr = ptr->next_add;
		printf("\n");
	}
	printf("\n");
	return 0;
}
