#include<stdio.h>
#define MAX 100
#define MAX_VERTICES 100
#define MAX_EDGES 100
//LIST
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[MAX];
	Position last;	
}List;
void makenullList(List *L){
	L->last = 0;
}
int fullList(List L){
	return L.last == MAX;
}
void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->Elements[L->last++] = x;
	}
}
//GRAPH
typedef struct{
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];
}Graph;
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
void print(Graph G){
	int i,j;
	for(i=1; i<= G.n; i++){
		for(j=1; j<=G.m; j++){
			printf("%d ", G.A[i][j]);
		}
		printf("\n");
	}
}
//STACK
#define MAX_ELEMENTS 100 
typedef struct {
    int data[MAX_ELEMENTS]; 
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
void Deep_first_search(Graph *G){
	int i, mark[G->n+1];
	Stack S;
	make_null_stack(&S);
	//Khoi tao
	for(i=1; i<= G->n; i++){
		mark[i] = 0;
	}
	push(&S,1);
	//Duyet
	while(!empty(&S)){
		int x = top(&S); pop(&S);
		if(empty(&S)){
			for(i=1; i<= G->n; i++){
				if(mark[i] == 0 ){
					 push(&S,i);
					 break;
				}
			}
		}
		if(mark[x] != 0) continue;	
		printf("%d\n", x);
		mark[x] = 1;
		List L = neighbors(&(*G), x);
		for(i=0; i<L.last; i++){
			push(&S, L.Elements[i]);
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
	Deep_first_search(&G);
return 0;
}

