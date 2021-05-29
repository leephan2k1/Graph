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
void makenullList(List *L){
	L->last = 0;
}
void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->Elements[L->last++] = x;
	}
}
typedef struct {
	int u,v;
	int x,w;
}Edge;
typedef struct{
	int n,m;
	Edge edges[MAX];
}Graph;
void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}
void add_edge(Graph *G, int u, int v, int w){
	G->m++;
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
}
void print(Graph G){
	int e;
	for(e=1; e<=G.m; e++){
		if(G.edges[e].u < G.edges[e].v)
			printf("%d %d %d\n", G.edges[e].u, G.edges[e].v, G.edges[e].w);
		else
			printf("%d %d %d\n", G.edges[e].v, G.edges[e].u, G.edges[e].w);
		
	}
}
void swap(Edge *u, Edge *v){
	Edge temp = *u;
	*u = *v;
	*v = temp;
}
void bubble_sort(Graph *G){
	int i,j;
	for(i=1; i<=G->m; i++){
		for(j=G->m; j>=i+1; j--){
			//So sanh trong so
			if(G->edges[j].w < G->edges[j-1].w){
				swap(&G->edges[j], &G->edges[j-1]);
			//So sanh dinh u neu trong so bang nhau
			}else if(G->edges[j].w == G->edges[j-1].w){
				if(G->edges[j].u < G->edges[j-1].u){
					swap(&G->edges[j], &G->edges[j-1]);
				}
			//So sanh dinh v neu dinh u bang nhau
			}else if(G->edges[j].u == G->edges[j-1].u){
				if(G->edges[j].v < G->edges[j-1].v){
					swap(&G->edges[j], &G->edges[j-1]);
				}
			}
		}
	}
	
}
int parent[MAX];
int sum_w = 0;
int findRoot(int u){
	if(parent[u] == u)
		return u;
	return findRoot(parent[u]);
}
void Kruskal(Graph *G, Graph *T){
	init_graph(T, G->n);
	int e,u;
	for(u=1; u<=G->n; u++)
		parent[u] = u;
	for(e=1; e<= G->m; e++){
		    u = G->edges[e].u;
		int v = G->edges[e].v;
		int w = G->edges[e].w;
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		if(root_u != root_v){
			add_edge(T,u,v,w);
			parent[root_v] = root_u;
			sum_w += w;
		}
	}
}
List neighbors(Graph *G, int x){
	int i,j;
	List L;
	makenullList(&L);
	for(i=1; i<= G->n; i++){
		for(j=1; j<= G->m; j++){
			if(G->edges[j].u == x)
				append(G->edges[j].v, &L);
		}
	}
	return L;
}
void visit(Graph *G, int mark[], int v){
	if(mark[v] == 1) return;
	else{
	//	printf("%d\n", v);
		mark[v] = 1;
	}
	List L = neighbors(G, v);
	int i;
	//Duyet cac dinh ke cua v
	for(i=0; i<L.last; i++){
		visit(G, mark, L.Elements[i]);
	}
}
int mark[MAX];
void DFS(Graph *G, int x){
	int i;
	//Khoi tao mang danh dau
	for(i=1; i<=G->n; i++){
		mark[i] = 0;
	}
	visit(G, mark, x);
	
}
int main(){
	freopen("dt.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, w, e, x;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 1; e <= m; e++) {
		scanf("%d%d%d%d", &u, &v, &x, &w);
		w = x*w;
		add_edge(&G, u, v, w);
	}
	DFS(&G, 1);
	int flag = 1;
	for(e=1; e<=n; e++){
		if(mark[e] == 0){
			flag = 0;
			break;
		}
	}
	if(flag == 1){	
		bubble_sort(&G);
		Graph T;
		Kruskal(&G,&T);
	
		printf("%d\n", sum_w);
	}else
		printf("KHONG CO LOI GIAI");
//	print(T);
return 0;
}
