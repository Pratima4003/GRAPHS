#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"tree.h"

//stack node
typedef struct Node{
	node data;
	struct Node* next1;
}Node;

//stack
typedef Node *stack;

//init stack
void initStack(stack *S){
	*S = NULL;
	return;
}

//push function in Stack
void pushStack(stack *S, node n){
	Node*nn;
	nn = (Node*)malloc(sizeof(Node));
	if(nn == NULL)
		return;
	nn->data = n;
	nn->next1 = NULL;
	if(*S == NULL){
		*S = nn;
		return;
	}
	Node*p = *S;
	while(p->next1){
		p = p->next1;
	}
	p->next1 = nn;
	return;
}

//pop function in Stack
node *pop(stack *S){
	node *temp;
	initT(&temp);
	Node*p = *S;
	if(p == NULL){
		free(*S);
		return temp;
	}
	if((*S)->next1 == NULL){
		temp = p->data;
		free(*S);
		return temp;
	}
	temp = p->data;
	*S = p->next1;
	free(p);
	return temp;
}

//peek function in Stack
node peekStack(stack S){
	return (S->data);
}


