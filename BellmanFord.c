#include<stdio.h>
#define MAX 500
#define NO_EDGE 0
#define INFINITY 2147483640
typedef struct {
	int u,v;
	int w;
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
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}
int pi[MAX];
int p[MAX];
void BellmanFord(Graph *G, int s){
	int i, j, it;
	for(i=1; i<= G->n; i++){
		pi[i] = INFINITY;
	}
	pi[s] = 0;
	p[s] = -1;
	
	for(it = 1; it < G->n; it++){
		for(j=0; j < G->m; j++){
			int u = G->edges[j].u;
			int v = G->edges[j].v;
			int w = G->edges[j].w;
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	for(i=1; i<= G->n; i++){
        printf("pi[%d] = %d, p[%d] = %d\n",i, pi[i],i,p[i]);
	}
		
}
void print(Graph G){
	int i;
	for(i=0; i<G.m; i++){
		printf("%d %d %d\n", G.edges[i].u, G.edges[i].v, G.edges[i].w);
	}
}
int main(){
//	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n);
	int i,j,u,v,w;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(&G,u,v,w);
		}
	}
	BellmanFord(&G,1);
	return 0;
}
