#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"stack.h"
#define MAX 100

//init stack
void initS(stack *S){
	S->A = (int*)malloc(sizeof(int) * MAX);
	S->s = MAX;
	S->top = -1;
	return;
}

//push function in Stack
void pushS(stack *S, int n){
	if(!S)
	  return;
	if(S->top == -1){
	  S->A[++S->top] = n;
	  return;
	}
	S->A[++S->top] = n;
	return;
}

//pop function in Stack
int popS(stack *S){
	int e = INT_MIN;
	if(S->top == -1)
		return e;
        e = S->A[S->top--];
	return e;
}

//peek function in Stack
int peekS(stack S){
        if(S.top == -1)
          return INT_MIN;
	return (S.A[S.top]);
}

//it returns whether the stack is empty
int isEmptyS(stack S){
  return (S.top == -1);
}

//main function
/*int main(){
  stack S;
  initS(&S);
  pushS(&S, 12);
  pushS(&S, 13);
  pushS(&S, 15);
  printf("%d\n", popS(&S));
  printf("%d\n", peekS(S));
  return 0;
}*/

