#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
	float data; 
	struct Node* next; 
}; 

struct Node *bucket[10];
 
void sortedInsert(struct Node**, struct Node*); 

void insertionSort(struct Node **head_ref) 
{ 
	struct Node *sorted = NULL; 

	struct Node *current = *head_ref; 
	while (current != NULL) 
	{ 
		struct Node *next = current->next; 

		sortedInsert(&sorted, current); 

		current = next; 
	} 

	*head_ref = sorted; 
} 

void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{ 
	struct Node* current; 
	if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
	{ 
		new_node->next = *head_ref; 
		*head_ref = new_node; 
	} 
	else
	{ 
		current = *head_ref; 
		while (current->next!=NULL && current->next->data < new_node->data) 
		{ 
			current = current->next; 
		} 
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 

void printList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while(temp != NULL) 
	{ 
		printf("%f ", temp->data); 
		temp = temp->next; 
	} 
} 



struct Node *newNode(float f)
{
	struct Node *n = new Node;
	n->data = f;
	n->next = NULL; 

	return n;
}

void add_element(float f)
{
	int b = f * 10;
	struct Node *p = bucket[b];
	struct Node *q = p->next;
	p->next = newNode(f);
	p->next->next = q;
}


int main() 
{ 
	srand(5);
	for(int i = 0; i < 10; i++)
		bucket[i] = newNode(0);
		
	
	for(int i = 0; i < 200; i++)
	{
		unsigned int b = rand();
		b = b % 100;
		add_element((float)b/100);
	}
		
	for(int i = 0; i < 10; i++)
	{
		struct Node *p = bucket[i];
		p = p->next;
		insertionSort(&p);
		while(p != NULL)
		{
			printf("%f ", p->data);
			p = p->next;
		}
		printf("\n");
	}
	
	
} 



