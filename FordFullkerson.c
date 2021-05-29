#include<stdio.h>
#define MAX 100
#define INF 9999999
typedef int ElementType;
typedef struct{
	int Elements[MAX];
	int Front, Rear;
}Queue;
void init_queue(Queue *Q){
	Q->Front = 0;
	Q->Rear = -1;
}
int isEmpty(Queue *Q){
	return Q->Front > Q->Rear;
}
void enQueue(ElementType data, Queue *Q){
	Q->Rear++;
	Q->Elements[Q->Rear] = data;
}
void deQueue(Queue *Q){
	Q->Front++;
}
ElementType top(Queue *Q){
	return Q->Elements[Q->Front];
}
typedef struct{
	int C[MAX][MAX];
	int F[MAX][MAX];
	int n;
}Graph;
void init_graph(Graph *G, int n){
	int e,v;
	G->n = n;
	for(e=1; e<=G->n; e++){
		for(v=1; v<=G->n; v++){
			G->C[e][v] = 0;
		}
	}
}
typedef struct{
	int dir; //Nhan~
	int pre; //Dinh truoc do
	int sigma; //luong tang luong
}Label;

Label labels[MAX]; // Khai bao nhan~

void init_flow(Graph *G){
	int u,v;
	for(u=1; u<=G->n; u++)
		for(v=1; v<=G->n; v++)
			G->F[u][v] = 0;
}
int min(int a, int b){
	return a<b?a:b;
}
int FordFullkerson(Graph *G, int s, int t){
	init_flow(G);
	Queue Q;
	int u,v;
	int sum_flow = 0;
	do{
	//Buoc 1:
		//Xoa tat ca cac nhan
		for(u=1; u<=G->n; u++)
			labels[u].dir = 0;
		//Gan nhan s
		labels[s].dir = 1;
		labels[s].pre = s;
		labels[s].sigma = INF;
		//Khoi tao queue, dua s vao queue
		init_queue(&Q);
		enQueue(s, &Q);
	//Buoc 2,3: gan nhan cho cac dinh
		int found = 0;
		while(!isEmpty(&Q)){
			//Lay ra 1 dinh trong queue, xoa dinh
			int x = top(&Q); deQueue(&Q);
			for(v=1; v<=G->n; v++){
				//xet nhan dinh ke voi x, cung thuan
				if(labels[v].dir == 0 && G->C[x][v] != 0 && G->F[x][v] < G->C[x][v]){
					labels[v].dir = 1;
					labels[v].pre = x;
					labels[v].sigma = min(labels[x].sigma, G->C[x][v] - G->F[x][v]);
					enQueue(v, &Q);
				}
				//Cung nghich
				if(labels[v].dir == 0 && G->C[v][x] != 0 && G->F[v][x] > 0){
					labels[v].dir = -1;
					labels[v].pre = x;
					labels[v].sigma = min(labels[x].sigma, G->F[x][v]);
					enQueue(v, &Q);
				}	
			}
			if(labels[t].dir != 0){
				found = 1;
				break;
			}
		}
	//Buoc 4,5,6: tang luong
		if(found == 1){
			int x = t;
			int sigma = labels[t].sigma;
			sum_flow += sigma; //luong tang them
			
			while(x != s){
				int u = labels[x].pre;
				if(labels[x].dir > 0)
					G->F[u][x] += sigma;
				else
					G->F[x][u] -= sigma;
				x = u;
			}
		}else
			break;
	}while(1);
	return sum_flow;
}

void print(Graph *G){
	int e,v;
	for(e=1; e<=G->n; e++){
		for(v=1; v<=G->n; v++){
			if(G->C[e][v] != 0)
				printf("%d %d %d\n", e, v, G->C[e][v]);
		}
	}
}
int main(){
	Graph G;
	freopen("dt.txt", "r", stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	init_graph(&G, n);
	int e,u,v,c;
	for(e=1; e<=m; e++){
		scanf("%d%d%d", &u, &v, &c);
		G.C[u][v] = c;
	}
//	print(&G);
	int max_flow = FordFullkerson(&G, 1, n);
	printf("Max flow: %d\n", max_flow);
	printf("X0: ");
	for(e=1; e<=n; e++){
		if(labels[e].dir != 0) printf("%d ",e);
	}
	printf("\nY0: ");
	for(e=1; e<=n; e++){
		if(labels[e].dir == 0) printf("%d ",e);
	}
return 0;
}

