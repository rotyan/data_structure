//顺序表的插入、删除
//【自己的改进写法】但是需要考虑插入或删除时数组空间已经满了怎么办
#include <stdio.h>
#define NUM 4

struct array{
    int data[NUM + 1];
    int length; //善用这玩意啊
}L;

void listInsert(array &L, int j, int m){   //i为插入元素,m为插入位置（m-1为数组下标）,n为顺序表长度
    if (m > L.length -1 || m < 0)
    printf("插入位置错误");
    return ;
//    if (L.length == NUM) return;
    for (int i = L.length; i > m - 1; i--){
        L.data[i] = L.data[i - 1];
    }
    L.data[m - 1] = j;
}

void listDelete(array &L, int j, int m){   //i为删除元素,m为删除位置（m-1为数组下标）,n为顺序表长度
    if (m > L.length -1 || m < 0)
    printf("删除位置错误");
    return ;
    for (int i = m - 1; i < L.length; i++){
        L.data[i] = L.data[i + 1];
    }
    L.length--;
}

int main(){
    int n;
    L.length = 0; 
    for(int i = 0; i < NUM; i++){
        scanf("%d",&L.data[i]);
        L.length++;
    }
    listInsert(L, 2, 2);
    for(int i = 0; i < L.length + 1; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    listDelete(L, 2, 2);
    for(int i = 0; i < L.length + 1; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    getchar();
    return 0;
}