#include<stdio.h>
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
	G->m++;
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;

}
int deg_out(Graph *G, int x, int *xe){
	int j;
	int deg = 0;
	for(j=1; j<=G->m;j++)
		if(G->edges[j].u == x){
			 deg++;
		}
	return deg;
}
int deg_in(Graph *G, int x){
	int j;
	int deg = 0;
	for(j=1; j<=G->m;j++)
		if(G->edges[j].v == x){
			 deg++;
		}
	return deg;
}
List neighbors(Graph *G, int x){
	int i;
	List L;
	make_null_list(&L);
	for(i=1; i<= G->m; i++){
		if(G->edges[i].u == x){
			append(G->edges[i].v, &L);
		}
	}
	return L;
}
int main(){

return 0;
}

