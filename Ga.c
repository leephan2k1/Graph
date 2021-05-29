#include<stdio.h>
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
int isEmpty(List L){
	return L.last == 0;
}
void make_null_list(List *L){
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
	int A[MAX][MAX];
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
	List L;
	make_null_list(&L);
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->m; j++){
			//Co huong: G->A[i][j] == -1
			if(G->A[x][j] == 1 && G->A[i][j] == -1 && x != i) append(i, &L);
		}
	}
	return L;
}
int adjacent(Graph *G, int u, int v){
	int e;
	for(e=1; e<=G->m; e++){
		//Co huong:  G->A[v][e] == -1
		if(G->A[u][e] == 1 && G->A[v][e] == 1) return 1;
	}
	return 0;
}
int color[MAX];
int fail;
void colorize(Graph *G, int x, int c){
	if(color[x] == -1){
		color[x] = c;
		List L = neighbors(G, x);
		int j;
		for(j=0; j<L.last; j++){
			int y = L.Elements[j];
			colorize(G, y, !c);
		}
	}else
		if(color[x] != c)
			fail = 1;
}
int is_bigraph(Graph *G){
	int j;
	for(j=1; j<=G->n; j++)
		color[j] = -1;
	colorize(G, 1, 0);
	return !fail;
}
int main(){
	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n,m);
	int i,j,u,v,w;
	for(j=1; j<=m; j++){
		scanf("%d%d",&u, &v);
		add_edge(&G,j,u,v);
	}

	
	int A = 0, B = 0;
	if (is_bigraph(&G)) {
		int i;
		for (i = 1; i <= G.n; i++) {
			if (color[i] == 0) {
				A++;
				printf("%d ", i);
			}
		}
		printf("\n");
		for (i = 1; i <= G.n; i++) {
			if (color[i]) {
				B++;
				printf("%d ", i);
			}
		}
	//	printf("%d %d", B, A);
	}
	else
	printf("-1 -1");
return 0;
}
