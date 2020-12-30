//【完成版】顺序表的插入、删除
#include <stdio.h>
#define MAX 40   //数组最大空间
#define NUM 4   //输入数据的数目

struct array{
    int* data;
    int length;
};
//为顺序表动态分布一个数组空间
void Create(array &L){
    L.data = new int[MAX];
//    if (!L.data) exit(OVERFLOW);  //储存分配失败退出，不知为啥没用。。。
    L.length = 0;
}
//L为引用的顺序表,m为插入位置（m-1为数组下标）；j为插入数据的值
void listInsert(array &L, int m, int j){
    if ((m > L.length + 1) || (m < 1)){
        printf("插入位置错误");
        return ;  
    }
    if (L.length == MAX) {
        printf("数组已满");
        return;
    }
    for (int i = L.length; i > m - 1; i--){
        L.data[i] = L.data[i - 1];
    }
    L.data[m - 1] = j;
    L.length++; //若形参为array L，则这里L.length为副本，最后第一次插入后输出为四个数据而非五个数据；【副本】
}
//L为引用的顺序表,m为删除位置（m-1为数组下标）；不需要列出数据的值j
void listDelete(array &L, int m){
    if ((m > L.length) || (m < 1)){
        printf("删除位置错误");
        return ;  
    }
    for (int i = m - 1; i < L.length; i++){
        L.data[i] = L.data[i + 1];
    }
    L.length--; //若形参为array L，则这里L.length为副本，最后第一次插入后输出为五个数据而非四个数据；【值传递】
}

int main(){
    array L;
    Create(L);
    for(int i = 0; i < NUM; i++){
        scanf("%d",&L.data[i]);
        L.length++;
    }
    listInsert(L, 2, 15);   //测试集，参数分别为某顺序表、插入位置、插入数据值
    for(int i = 0; i < L.length; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    listDelete(L, 2);   //测试集，参数分别为某顺序表、删除位置
    for(int i = 0; i < L.length; i++){
        printf("%d  ",L.data[i]);
    }
    printf("\n");
    getchar();
    return 0;
}