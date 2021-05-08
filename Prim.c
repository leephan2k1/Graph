#include <stdio.h>
#define MAX 100
#define INF 9999999
typedef struct{
	int n;
	int A[MAX][MAX];
}Graph;

void init_graph(Graph *G, int n){
	int i,j;
	G->n = n;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++)
			G->A[i][j]=-1;
	}
}
void add_edge(Graph *G, int u, int v, int w){
	G->A[u][v] = w;
}
int pi[MAX];
int p[MAX];
int mark[MAX];
int sum_w = 0;

void prim(Graph *G, Graph *T, int x){
	init_graph(T,G->n);
	int u,v,i;
	for(u=1; u<=G->n; u++){
		pi[u] = INF;
	}
	
	pi[x] = 0;
	
	for(u=1; u<=G->n; u++){
		if(G->A[x][u] != -1){
			pi[u] = G->A[x][u];
			p[u] = x;
		}
	}
	
	for(u=1; u<=G->n; u++){
		mark[u] = 0;
	}
	mark[x] = 1;
	

	
	for(i=1; i<G->n; i++){
		int min = INF;
		int min_u;
		for(u=1; u<=G->n; u++){
			if(mark[u] == 0){
				if(min > pi[u]){
					min = pi[u];
					min_u = u;
				}
			}
		}
		u = min_u;
		mark[min_u] = 1;
		
		add_edge(T, min_u, p[min_u], min);
		sum_w += min;
		
		for(v=1; v<=G->n; v++){
			if(G->A[u][v] != -1 && mark[v] == 0){
				if(pi[v] > G->A[u][v]){
					pi[v] = G->A[u][v];
					p[v] = u;
				}
			}
		}
	}
	
}
int main(){
	Graph G;
	int n,m,u,v,w,i,j;
	freopen("dt.txt", "r", stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	
	for(i=1; i<=m; i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G, u, v, w);
	}
	
	Graph T;
	prim(&G,&T,1);
	printf("%d\n", sum_w);
	for(i=1; i<=T.n; i++){
		for(j=1; j<=T.n; j++){
			if(T.A[i][j] != -1){
				printf("%d %d ",j,i);
				printf("%d\n", T.A[i][j]);
			}
		}
	}
	return 0;
}

