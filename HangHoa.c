#include<stdio.h>
#define MAX 100
typedef struct {
	int u,v,c,f;
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
void add_edge(Graph *G, int u, int v, int c, int f){
	G->m++;
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].c = c;
	G->edges[G->m].f = f;
}
int deg_out(Graph *G, int x, int *xe){
	int j;
	int deg = 0;
	for(j=1; j<=G->m;j++)
		if(G->edges[j].u == x){
			 deg++;
			 *xe += G->edges[j].f; 
		}
	return deg;
}
int deg_in(Graph *G, int x, int *xe){
	int j;
	int deg = 0;
	for(j=1; j<=G->m;j++)
		if(G->edges[j].v == x){
			 deg++;
			 *xe += G->edges[j].f;
		}
	return deg;
}

int main(){
//	freopen("dt.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, c, f, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 1; e <= m; e++) {
		scanf("%d%d%d%d", &u, &v, &c, &f);
		add_edge(&G, u, v, c, f);
	}
	int xe_vao = 0, xe_ra = 0;
	int dinh_phat;
	int dinh_thu;
	for(u=1; u<=n; u++){
		int x = deg_out(&G,u,&xe_ra);
		int y = deg_in(&G,u,&xe_vao);
		if(x == 0) dinh_thu = u;
		if(y == 0) dinh_phat = u;
	}
	xe_vao = 0;
	xe_ra = 0;
	int x = deg_in(&G, dinh_thu, &xe_vao);
	int y = deg_out(&G, dinh_phat, &xe_ra);
	if(xe_vao == xe_ra) printf("TOT");
	else printf("MAT HANG");
return 0;
}
