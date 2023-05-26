#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//stack node
typedef struct stack{
	int *A;
	int s;
	int top;
}stack;

//functions
void initS(stack *S);
void pushS(stack *S, int n);
int popS(stack *S);
int peekS(stack S);
int isEmptyS(stack S);
