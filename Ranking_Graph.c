#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define MAX 100
// LIST
typedef int Position;
typedef int ElementType;
typedef struct{
	ElementType Elements[MAX];
	Position last;	
}List;

int fullList(List L){
	return L.last == MAX;
}
void makenullList(List *L){
	L->last = 0;
}
void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->Elements[++L->last] = x;
	}
}
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
			G->A[i][j] = 0;
		}
	}
}
void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
//	G->A[y][x] = 1; 
} 	
int rank[MAX_VERTICES];
void ranking(Graph *G){
	int d[MAX_VERTICES];
	int x,u;
	for(u=1; u <= G->n; u++) 
		d[u] = 0;
	for(x=1; x <= G->n; x++){
		for(u=1; u <= G->n; u++){
			if(G->A[x][u] != 0) d[u]++;
		}
	}
	List L1, L2;
	makenullList(&L1);
	
	for(u=1; u <= G->n; u++) 
		if(d[u] == 0) 
			append(u, &L1);
			
	int k = 0, i;
	while(L1.last > 0){
		makenullList(&L2);
		for(i=1; i <= L1.last; i++){
			int y = L1.Elements[i];
			rank[y] = k;
			int v;
			for(v=1; v<= G->n; v++){
				if(G->A[y][v] != 0){
					d[v]--;
					if(d[v] == 0) append(v, &L2);
				}
			}
		}
		L1 = L2;
		k++;
	}
	
	for(i=1; i<=G->n; i++)
		printf("%d ", rank[i]);
	
	
}
int main(){
//	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n);
	int j,u,v;
	for(j=1; j<=m; j++){
		scanf("%d%d",&u, &v);
		add_edge(&G,u,v);
	}
	ranking(&G);

return 0;
}

