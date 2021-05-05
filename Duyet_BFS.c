#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100
#define MAX 100
typedef struct{
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];
}Graph;

//QUEUE
typedef int ElementType;
typedef struct{
	ElementType Elements[MAX];
	int Front, Rear;
}Queue;
void make_Queue(Queue *Q){
	Q->Front = Q->Rear = -1;
}
int isEmpty(Queue Q){
	return Q.Front == -1;
}
int getFront(Queue Q){
	return Q.Elements[Q.Front];
}
int isFull(Queue Q){
	return ((Q.Rear - Q.Front+1) % MAX) == 0;
}
void enQueue(ElementType data, Queue *Q){
	if(isFull(*Q)){
		return;
	}else{
		if(Q->Front == -1) ++Q->Front;
		Q->Rear = (Q->Rear + 1) % MAX;
		Q->Elements[Q->Rear] = data;
	}
}
void deQueue(Queue *Q){
	if(!isEmpty(*Q)){
		if(Q->Front == Q->Rear) make_Queue(&(*Q));
		else{
			Q->Front = (Q->Front + 1)% MAX;
		}
	}
}
// LIST
typedef int Position;
typedef struct{
	ElementType Elements[MAX];
	Position last;	
}List;
int fullList(List L){ //Day tra ve 1
	return L.last == MAX;
}
void makenullList(List *L){
	L->last = 0;
}
void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->Elements[L->last++] = x;
	}
}
// GRAPH
void init_graph(Graph *G, int n, int m){
	int i,j;
	G->n = n;
	G->m = m;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->m; j++){
			G->A[i][j] = 0;
		}
	}
}
void add_edge(Graph* G, int e, int x, int y) {
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}
List neighbors(Graph *G, int x){
	int i,j;
	List res;
	makenullList(&res);
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->m; j++){
			if(G->A[x][j] == 1 && G->A[i][j] == 1 && x != i) append(i, &res);
		}
	}
	return res;
}
void breath_first_search(Graph *G){
	Queue Q;
	make_Queue(&Q);
	int mark[G->n+1];
	int i;
	//Khoi tao mang danh dau
	for(i=1; i<= G->n; i++){
		mark[i] = 0;
	}
	//Duyet dinh 1
	enQueue(1, &Q);
	printf("1\n");
	mark[1] = 1;
	//Duyet cac dinh con lai
	while(!isEmpty(Q)){
		int x = getFront(Q);
		deQueue(&Q);
		List L;
		L = neighbors(&(*G), x);
		for(i=0; i<L.last; i++){
			int y = L.Elements[i];
			if(mark[y] == 0){ //Duyet cac dinh chua duyet
				printf("%d\n",y);
				mark[y] = 1;
				enQueue(y, &Q);
			}
		}
		//Duyet cac dinh con lai trong do thi khong lien thong
		if(isEmpty(Q)){
			for(i=1; i<= G->n; i++){
				if(mark[i] == 0){
					enQueue(i, &Q);
					printf("%d\n", i);
					mark[i] = 1;
					break;
				}
			}
		}
		
	}

	
	
}
int main(){
//	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n,m);
	int j,e,v;
	for(j=1; j<=m; j++){
		scanf("%d%d",&e, &v);
		add_edge(&G,j,e,v);
	}
//	print(G);
	breath_first_search(&G);	
	return 0;
}
