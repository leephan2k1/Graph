#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX 100
//Queue
typedef int ElementType;
typedef struct{
	ElementType Elements[MAX];
	int Front, Rear;
}Queue;
void init_queue(Queue *Q){
	Q->Front = 0;
	Q->Rear = -1;
}
int top(Queue *Q){
	return Q->Elements[Q->Front];
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
// LIST
typedef int Position;
typedef int ElementType;
typedef struct{
	ElementType Elements[MAX];
	Position last;	
}List;

int fullList(List L){
	return L.last == MAX;
}
void makenullList(List *L){
	L->last = 0;
}
void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->Elements[++L->last] = x;
	}
}
//Graph
typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph *G, int n){
	int i,j;
	G->n = n;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++){
			G->A[i][j] = 0;
		}
	}
}
List neighbors(Graph *G, int x){
	List L;
	makenullList(&L);
	int i;
	for(i=1; i<= G->n; i++){
		if(G->A[x][i] == 1)
			append(i,&L);
	}
	return L;
}
void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
//	G->A[y][x] = 1; 
} 	
void topo_sort(Graph *G){
	int d[MAX_VERTICES];
	int mark[MAX_VERTICES];
	int x,u;
	for(u=1; u <= G->n; u++){
		d[u] = 0;
		mark[u] = 0;
	}
		
	for(x=1; x <= G->n; x++){
		for(u=1; u <= G->n; u++){
			if(G->A[x][u] != 0) 
			    d[u]++;
		}
	}
	
	Queue Q;
	init_queue(&Q);
	for(u=1; u <= G->n; u++) 
		if(d[u] == 0){
			enQueue(u, &Q);
			mark[u] = 1;
		}
	
	List L;
	makenullList(&L);
	
	while(!isEmpty(&Q)){
		int v = top(&Q); deQueue(&Q);
		append(v, &L);
		List L2 = neighbors(G, v);
		for(x=1; x<= L2.last; x++){
			int y = L2.Elements[x];
			if(mark[y] == 0){
				d[y]--;
				if(d[y] == 0){
					enQueue(y,&Q);
					mark[y] = 1;
				}
			}
		}	
	}
	
	for(x=1; x<= L.last; x++)
		printf("%d ", L.Elements[x]);

}
int main(){
//	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n);
	int j,u,v;
	for(j=1; j<=m; j++){
		scanf("%d%d",&u, &v);
		add_edge(&G,u,v);
	}
	topo_sort(&G);

return 0;
}

