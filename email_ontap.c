#include<stdio.h>
#define MAX_VERTICES 100
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
//  Vo huong:
//	G->A[y][x] = 1; 
} 	
int degree(Graph G, int x){ //Vo huong:
	int count = 0;
	int i;
	for(i=1; i<=G.n; i++){
		if(G.A[i][x] != 0) 
			count += G.A[i][x];
	}
	return count;
}
int degree_out(Graph G, int x){
	int count = 0;
	int i;
	for(i=1; i<=G.n; i++){
		if(G.A[x][i] == 1) ++count;
	}
	return count;
}
//int degree(Graph G, int x){
//	return degree_in(G,x) + degree_out(G,x);
//}
int adjacent(Graph G, int x, int y){
	return (G.A[x][y] == 1);
}
void neighbors(Graph G, int x){
	int i;
	for(i=1; i<=G.n; i++){
		if(G.A[x][i] == 1)
			printf("%d ", i);
	}
}
int main(){
	freopen("dt.txt", "r", stdin);
	Graph G;
	int n;
	scanf("%d",&n);
	init_graph(&G,n);
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d",&G.A[i][j]);
		}
	}

	int max_V= degree(G,1);;
	int max = 1;
	for(i=2; i<=n; i++){
		if(max_V < degree(G,i)){
			max = i;
			max_V = degree(G,i);
		}
	}
	printf("%d has received %d email(s).", max, max_V);
return 0;
}
