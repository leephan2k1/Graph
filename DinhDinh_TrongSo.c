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
			printf("%d  ", G.A[i][j]);
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
int main(){
	
	return 0;
}
