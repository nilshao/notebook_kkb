#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ERROR 0
#define OK 1
typedef struct Vector {
    int size,length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector -> size = size;
    vector -> length = 0;
    vector -> data = (int *)malloc(sizeof(int) * size);
}
int insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
        return ERROR;
        //expand(vector);
    }
    for (int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

void expand(Vector *vector){
    int *old_data = vector->data;
    vector->size = vector->size*2;
    vector->data = (int *)malloc(sizeof(int)*vector->size);  
    for(int i=0;i<vector->length;i++){
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int delete_node(Vector *vector, int index) {
    if (index < 0 || index >= vector->length) {
        return ERROR;
    }
    for (int i=index+1; i < vector->length; ++i) {
        vector->data[i-1] = vector->data[i];
    }
    vector->length--;
    return OK;
}
void print(Vector *vector) {
    for(int i=0;i<vector->length;++i){
        if(i>0){
            printf(" ");
        }
        printf("%d",vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
    free(vector->data);
    free(vector);
}
void move(Vector *vector, int loc){
    int l = vector->length;
    for(int i=0;i<loc;++i){
        insert(vector,vector->length,vector->data[i]);
    }
    for(int i = loc;i<vector->length;++i){
        vector->data[i-loc] = vector->data[i];
    }
    for(int i=0;i<loc;++i){
        delete_node(vector,vector->length-1);
    }
    return ;
}
int main() {
    Vector *c = (Vector *)malloc(sizeof(Vector));
    Vector *e = (Vector *)malloc(sizeof(Vector));

    init(c, 20);
    init(e, 20);

    int m,x;
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        int c_val,e_val;
        scanf("%d%d",&c_val,&e_val);
        insert(c,i,c_val);
        insert(e,i,e_val);
    }
    scanf("%d",&x);
    int res = 0;
    for(int i=0;i<m;++i){
        res += pow(x,e->data[i])*c->data[i];
    }
    printf("%d\n",res);

    clear(c);
    clear(e);
    return 0;
}