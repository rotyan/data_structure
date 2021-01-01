// 冒泡排序和快速排序
#include<cstdio>
#define MAX 5

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
//冒泡排序的顺序表写法
void bubbleSort(array &L) {
    for (int i = 1; i < L.length; i++){   //进行length - 1躺
        for (int j = 0; j < L.length - i; j++) {  //每趟交换length - i次
        // 第i趟时a[0]直到a[length - i - 1]都分别与它们下一个树进行比较
            if (L.data[j] > L.data[j + 1]) {  //向右冒泡大的值
            int temp = L.data[j + 1];
            L.data[j + 1] = L.data[j];
            L.data[j] = temp; 
            }
        }
    }
}
// 对区间进行划分
int Partition(int A[], int left, int right) {
    int temp = A[left];
    while (left < right) {
        while (left < right && A[right] >= temp) right--;
        A[left] = A[right];
        while (left < right && A[left] < temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}
// 快速排序
void quickSort(int A[], int left, int right) {
    if (left < right) {
        //将[left,right]按照A[left]一分为二
        int key = Partition(A, left, right); //数组传递实参时候只需传入数组名即可
        quickSort(A, left, key - 1);
        quickSort(A, key + 1, right);
    }
}

int main() {
    array L;
    Create(L);
    // for (int i = 0; i < MAX; i++) {
    //     scanf("%d  ",&L.data[i]);
    //     L.length++;
    // }
    // bubbleSort(L);
    // for (int i = 0; i < MAX; i++) {
    //     printf("%d  ",L.data[i]);
    // }
    getchar();
    return 0;
}