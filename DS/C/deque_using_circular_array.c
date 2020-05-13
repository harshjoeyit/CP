#include<stdio.h>
#include<stdlib.h>

struct deque
{
	int *arr;
	int front;
	int rear;
};

typedef struct deque DQ;


int is_full(DQ *dq)
{
	return ( (dq->rear + 1) % 10 == dq->front );
	
}

int is_empty(DQ *dq)
{
	return (dq->front == -1);
}


void push_front(DQ *dq, int val)
{
	if(! is_full(dq))
	{
		if(dq->front == -1)
		{
			dq->front = 0;
			dq->rear = 0;
		} 
		else
			dq->front = (dq->front - 1 + 10) % 10;

	//printf("front-> %d ", dq->front);
	//printf("rear-> %d\n", dq->rear);	
		dq->arr[dq->front] = val;
	}
	else
		printf("Full \n");
}


void push_back(DQ *dq, int val)
{
	if(! is_full(dq))
	{
		if(dq->front == -1)
		{
			dq->front = 0;
			dq->rear = 0;
		} 
		else
			dq->rear = (dq->rear + 1) % 10;

	//printf("front-> %d ", dq->front);
	//printf("rear-> %d\n", dq->rear);	
		dq->arr[dq->rear] = val;
	}
	else
		printf("Full \n");
}

int front_val(DQ *dq)
{
	if(! is_empty(dq))
		return dq->arr[dq->front];	
	return -1;
}

int rear_val(DQ *dq)
{
	if(! is_empty(dq))
		return dq->arr[dq->rear];
	return -1;
}



void pop_front(DQ *dq)
{
	if(! is_empty(dq))
	{
		if(dq->front == dq->rear)
			dq->front = dq->rear = -1;
		else
			dq->front = (dq->front + 1) % 10;
	}
	else
		printf("Empty \n");	
}


void pop_back(DQ *dq)
{
	if(! is_empty(dq))
	{
		if(dq->front == dq->rear)
			dq->front = dq->rear = -1;
		else	
			dq->rear = (dq->rear -1 + 10) % 10;
	}
	else
		printf("Empty \n");	
}



void display(DQ *dq)
{
	if(dq->front == -1)
	{
		printf("Empty\n");
		return;
	}

	int i = dq->front;
	while(i != (dq->rear + 1) % 10)
	{
		printf("%d ", dq->arr[i]);
		i = (i+1)%10;

	}
	printf("\n");
}


int main()
{
	DQ *dq = (DQ *)malloc(sizeof(DQ));
	dq->arr = (int *)calloc(10, sizeof(int));
	dq->front = dq->rear = -1;

	display(dq);
	push_back(dq, 10);
	display(dq);
	push_front(dq, 20);
	display(dq);
	push_front(dq, 30);
	display(dq);

	printf("f - %d ", dq->front);
	printf("r - %d\n", dq->rear);

	printf("fv - %d ", front_val(dq));
	printf("rv - %d\n", rear_val(dq));

	pop_back(dq);
	printf("rv - %d ", rear_val(dq));
	pop_front(dq);
	printf("fv - %d\n", front_val(dq));
	
	pop_front(dq);
	printf("rv - %d ", rear_val(dq));
	pop_front(dq);
	printf("fv - %d\n", front_val(dq));

	display(dq);
	push_back(dq, 10);
	display(dq);
	push_front(dq, 20);
	display(dq);
	push_front(dq, 30);
	display(dq);

	printf("f - %d ", dq->front);
	printf("r - %d\n", dq->rear);
	
}
