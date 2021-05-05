#include<stdio.h>
//STACK
#define MAX 100 
typedef struct {
    int data[MAX]; 
    int size;
}Stack;

void make_null_stack(Stack* S){ 
    S->size = 0;
}
void push(Stack* S, int x){ 
    S->data[S->size] = x;
    S->size++;
}
int top(Stack* S) {
    return S->data[S->size - 1];
}
void pop(Stack* S) { 
    S->size--;
}
int empty(Stack* S) { 
    return S->size == 0;
}
int main(){
	Stack S;
	make_null_stack(&S);
	push(&S,2);
	push(&S,3);
	while(!empty(&S)){
		printf("%d ", top(&S));
		pop(&S);
	}
return 0;
}

