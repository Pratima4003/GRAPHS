#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"queue.h"

/** FUNCTIONS **/

//initialize the queue
void initQ(queue *Q){
	Q->front = NULL;
	Q->rear = NULL;
	Q->count = 0;
	return;
}

//check whether the Queue is empty
int isEmpty(queue Q){
        return (Q.front == NULL || Q.rear == NULL);
}


//add an element to the queue
void enQ(queue *Q, int k){
	node*nn;
	nn = (node*)malloc(sizeof(node));
	if(!nn)
		return;
	nn->data = k;
	nn->next = NULL;
	if(isEmpty(*Q)){
		Q->front = nn;
		Q->rear = nn;
		Q->count++;
		return;
	}
	Q->rear->next = nn;
	Q->rear = nn;
	Q->count++;
	return;
}

//remove an element from the queue
int deQ(queue *Q){
	int e = INT_MIN;
	if(isEmpty(*Q))
		return e;
	node*p = Q->front;
	Q->front = p->next;
	e = p->data;
	Q->count--;
	free(p);
	return e; 
}
