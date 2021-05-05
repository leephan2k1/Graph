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
int isEmpty(List L){
	return L.last == 0;
}
void make_null_list(List *L){
	L->last = 0;
}
void append(ElementType x, List *L){
	if(!fullList(*L)){
		L->Elements[L->last++] = x;
	}
}
int main(){
return 0;
}

