//顺序表的插入、删除
#include <stdio.h>
#define MAX 50   //数组最大空间
#define NUM 4   //输入数据的数目

struct array{
    int* data;
    int length;
};

void Create(array &L){
    L.data = new int[MAX];
//    if (!L.data) exit(OVERFLOW);  //储存分配失败退出，不知为啥没用。。。
    L.length = 0;
}

void listInsert(array &L, int j, int m){   //i为插入元素,m为插入位置（m-1为数组下标）,n为顺序表长度
    if (m > L.length + 1 || m < 1)
    printf("插入位置错误");
    return ;
    if (L.length == MAX) 
    printf("数组已满");
    return;
    for (int i = L.length; i > m - 1; i--){
        L.data[i] = L.data[i - 1];
    }
    L.data[m - 1] = j;
    L.length++;
}

void listDelete(array &L, int j, int m){   //i为删除元素,m为删除位置（m-1为数组下标）,n为顺序表长度
    if (m > L.length || m < 1)
    printf("删除位置错误");
    return ;
    for (int i = m - 1; i < L.length; i++){
        L.data[i] = L.data[i + 1];
    }
    L.length--;
}

int main(){
    array L;
    Create(L);
    for(int i = 0; i < NUM; i++){
        scanf("%d",&L.data[i]);
        L.length++;
    }
    listInsert(L, 2, 2);
    for(int i = 0; i < L.length; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    listDelete(L, 2, 2);
    for(int i = 0; i < L.length; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    getchar();
    return 0;
}