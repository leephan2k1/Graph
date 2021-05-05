#include<stdio.h>
#define MAX_VERTICES 500
#define NO_EDGE -1
#define INFINITY 2147483640
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
			G->A[i][j] = NO_EDGE;
		}
	}
}
void add_edge(Graph *G, int x, int y, int w){
	G->A[x][y] = w;
} 	
void print(Graph G){
	int i,j;
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++){
			printf("%d	 ", G.A[i][j]);
		}
		printf("\n");
	}
}
int adjacent(Graph G, int x, int y){
	return (G.A[x][y] != NO_EDGE);
}
void neighbors(Graph G, int x){
	int i;
	for(i=1; i<=G.n; i++){
		if(G.A[x][i] != NO_EDGE)
			printf("%d ", i);
	}
}
int mark[MAX_VERTICES];
int pi[MAX_VERTICES];
int p[MAX_VERTICES];
void Dijkstra(Graph *G, int u, int v){
	//Khoi tao
	int i,j,it;
	for(i=1; i<= G->n; i++){
		pi[i] = INFINITY;
		mark[i] = 0;
	}
	pi[u] = 0;
	p[u] = -1;
	
	for(it=1; it<G->n; it++){
		int min_pi = INFINITY;
		for(j=1; j<=G->n; j++)
			if(mark[j] == 0 && pi[j] < min_pi){
				min_pi = pi[j];
				i=j;
			}
//		printf("%d %d\n",pi[i], i);
		mark[i] = 1;
		//Cap nhat dinh ke
		for(j=1; j<=G->n; j++){
			if(G->A[i][j] != NO_EDGE && mark[j] == 0){
				if(pi[i] + G->A[i][j] < pi[j]){
					pi[j] = pi[i] + G->A[i][j];
					p[j] = i;
				}
			}
		}
			
		
	}
	if(pi[v] == INFINITY) printf("-1");
	else printf("%d", pi[v]);
//	for(i=1; i<= G->n; i++){
//		printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);
//	}
}
int main(){
//	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n);
	int j,u,v,w;
	for(j=1; j<=m; j++){
		scanf("%d%d%d",&u, &v, &w);
		add_edge(&G,u,v,w);
	}
//	print(G);
	Dijkstra(&G,1,n);
	return 0;
}
