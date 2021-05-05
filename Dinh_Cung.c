#include<stdio.h>
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
// GRAPH
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
    G->A[y][e] = -1;
    //Co huong: G->A[y][e] = -1;
}
List neighbors(Graph *G, int x){
	int i,j;
	List res;
	makenullList(&res);
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->m; j++){
			//Co huong: G->A[i][j] == -1
			if(G->A[x][j] == 1 && G->A[i][j] == -1 && x != i) append(i, &res);
		}
	}
	return res;
}
int adjacent(Graph *G, int u, int v){
	int e;
	for(e=1; e<=G->m; e++){
		//Co huong:  G->A[v][e] == -1
		if(G->A[u][e] == 1 && G->A[v][e] == 1) return 1;
	}
	return 0;
}
int main(){
	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n,m);
	int j,e,v;
	for(j=1; j<=m; j++){
		scanf("%d%d",&e, &v);
		add_edge(&G,j,e,v);
	}
//	printf("%d ", adjacent(&G,3,1));
//	List L = neighbors(&G, 2);
//	for(j=0; j<L.last; j++) printf("%d ", L.Elements[j]);
return 0;
}

