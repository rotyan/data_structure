//顺序表的插入、删除
#include <stdio.h>
#define NUM 5

struct array{
    int data[NUM + 1];
    int length;
}L;

void insert(int i, int m, int n){   //i为插入元素,m为插入位置（m-1为数组下标）,n为顺序表长度
    for (int i = n; i > m - 1; i--){
        L.data[i] = L.data[i - 1];
    }
    L.data[m - 1] = i;
}

void listDelete(int i, int m, int n){   //i为删除元素,m为删除位置（m-1为数组下标）,n为顺序表长度
    for (int i = n; i > m - 1; i--){
        L.data[i] = L.data[i - 1];
    }
}

int main(){
    int n;
    L.length = 0; 
    for(int i = 0; i < NUM; i++){
        scanf("%d",&L.data[i]);
    }
    insert(2, 2, NUM);
    for(int i = 0; i < NUM; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    listDelete(2, 2, NUM);
    for(int i = 0; i < NUM; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    getchar();
    return 0;
}