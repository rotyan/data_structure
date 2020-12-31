//顺序表的插入、删除
#include <stdio.h>
#define MAX 40   //数组最大空间
#define NUM 4   //输入数据的数目

struct array{
    int* data;
    int length;
};

void Create(array &L) {
    L.data = new int[MAX];
    if (!L.data) {  //自行拓展
        printf("储存分配失败！");
        return;
    } 
    L.length = 0;
}

void arrayInsert(array &L, int n, int m) {
    if (m < 1 || m > L.length + 1) {    //插入位置判断两个；错+1
        printf("ERROR1");
        return;
    }
    if (MAX == L.length) {   //L.length = MAX第一次，错误；建议写作【MAX == L.lengt】；错+1
        printf("数组已满");
        return;
    }
    for (int i = L.length; i > m - 1; i--) {    //循环终止条件；错+1
        L.data[i] = L.data[i - 1];
    }
    L.data[m - 1] = n;
    L.length++;
}

void arrayDelete(array &L, int m) {
    if (m < 1 || m > L.length) {    //删除位置判断两个错+1
        printf("ERROR1");
        return;
    }
    for (int i = m - 1; i < L.length; i++) {    //循环终止条件；错+1
        L.data[i] = L.data[i + 1]; 
    }
    L.length--;
}

int main() {
    array L; 
    Create(L);
    for (int i = 0; i < NUM; i++) {
        scanf("%d",&L.data[i]);
        L.length++;
    }
    arrayInsert(L,200,2);
    for (int i = 0; i < L.length; i++) {
        printf("%d  ",L.data[i]);
    }
    arrayDelete(L,2);
    for (int i = 0; i < L.length; i++) {
        printf("%d  ",L.data[i]);
    }
    getchar();
    return 0;
}