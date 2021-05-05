#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100
#define MAX_ELEMENTS 100 
//LIST
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[MAX_ELEMENTS];
	Position last;	
}List;
void makenullList(List *L){
	L->last = 0;
}
int fullList(List L){
	return L.last == MAX_ELEMENTS;
}
void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->Elements[L->last++] = x;
	}
}
//STACK
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
//Graph
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
//Bac ra
int degree_out(Graph *G, int x){
	int i, deg = 0;
	for(i=1; i<=G->m; i++){
		if(G->A[x][i] == 1) ++deg;
	}
	return deg;
}
//Bac vao
int degree_in(Graph *G, int x){
	int i, deg = 0;
	for(i=1; i<=G->m; i++){
		if(G->A[x][i] == -1) ++deg;
	}
	return deg;
}
//Tong bac
int degree(Graph *G, int x){
	return degree_out(G,x) + degree_in(G,x);
}
void add_edge(Graph* G, int e, int x, int y) {
	G->A[x][e] = 1;
   	G->A[y][e] = -1;
}
List neighbors(Graph *G, int x){
	int i,j;
	List res;
	makenullList(&res);
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->m; j++){
			if(G->A[x][j] == 1 && G->A[i][j] == -1 && x != i) append(i, &res);
		}
	}
	return res;
}
void print(Graph *G){
	int i,j;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->m; j++){
			printf(" %d  ", G->A[i][j]);
		}
		printf("\n");
	}
}

int num[MAX_VERTICES];
int on_stack[MAX_VERTICES];
int min_num[MAX_VERTICES];
int k = 1;
Stack S;
int count = 0;

int min(int x, int y){
	return (x<y)?x:y;
}
void tarjan(Graph *G, int x){
	num[x] = min_num[x] = k;
	++k;
	push(&S, x);
	on_stack[x] = 1;
	
	List L = neighbors(G, x);
	int i;
	
	for(i=0; i<L.last; i++){
		int y = L.Elements[i];
		if(num[y] < 0){
			tarjan(G, y);
			min_num[x] = min(min_num[x], min_num[y]);
		}else if(on_stack[y] == 1){
			min_num[x] = min(min_num[x], num[y]);
		}
	}
	
	if(num[x] == min_num[x]) ++count;
	
}
void bpltm(Graph *G){
	int i;
	for(i=1; i<= G->n; i++){
		num[i] = -1;
		on_stack[i] = 0;
	}
	make_null_stack(&S);
	for(i=1; i<= G->n; i++){
		if(num[i] == -1)
			tarjan(G,i);
	}
	printf("%d", count);
	
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
	bpltm(&G);
return 0;
}

