#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
typedef int ElementType;
typedef struct{
	int Elements[MAX];
	int Front, Rear;
}Queue;
void init_queue(Queue *Q){
	Q->Front = 0;
	Q->Rear = -1;
}
int isEmpty(Queue *Q){
	return Q->Front > Q->Rear;
}
void enQueue(ElementType data, Queue *Q){
	Q->Rear++;
	Q->Elements[Q->Rear] = data;
}
void deQueue(Queue *Q){
	Q->Front++;
}
void printQueue(Queue *Q){
	int i = Q->Front;
	for(;i<=Q->Rear; i++){
		printf("%d ", Q->Elements[i]);
	}
	printf("\n");
}
int main(){
	Queue Q;
	init_queue(&Q);
	enQueue(2, &Q);
	enQueue(3, &Q);
	printQueue(&Q);
	deQueue(&Q);
	printQueue(&Q);
	deQueue(&Q);
	printf("%d %d", Q.Front, Q.Rear);
return 0;
}

