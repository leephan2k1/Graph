#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100
#define MAX 100
// LIST
typedef int Position;
typedef int ElementType;
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
int degree(Graph *G, int x){
	int i, deg = 0;
	for(i=1; i<=G->m; i++){
		if(G->A[x][i] == 1) ++deg;
	}
	return deg;
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
int visit(Graph *G, int mark[], int v, int parent){
	mark[v] = 1;
	List L = neighbors(&(*G), v);
	int i;
	//Duyet cac dinh ke cua v
	for(i=0; i<L.last; i++){
		if(mark[L.Elements[i]] == 0){
			if(visit(&(*G), mark, L.Elements[i], v)) return 1;
		}
		else if(L.Elements[i] != parent) return 1;	
	}
	return 0;
}
int is_cycle(Graph *G){
	int mark[G->n+1];
	int i;
	//Khoi tao mang danh dau
	for(i=1; i<=G->n; i++){
		mark[i] = 0;
	}

	for(i=1; i<=G->n; i++){
		if(mark[i] == 0){
			if(visit(&(*G), mark, i, 0)) return 1;
		}
	}
	return 0;
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
	if(is_cycle(&G)) printf("YES");
	else printf("NO");
return 0;
}
