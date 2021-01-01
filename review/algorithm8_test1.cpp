// 冒泡排序和快速排序
#include<cstdio>
#define MAX 5

struct array{
    int* data;
    int length;
};

void Create(array &L) {     //要加引用；错+1
    L.data = new int[MAX];
    // if (!L.data) return(OVERFLOW);
    L.length = 0;   //漏+1
}

void bubbleSort(array &L) {
    for (int i = 1; i < L.length; i++) {    //进行L.length-1趟
        for (int j = 0; j < L.length - i; j++) {    //每次令a[0]到a[L.length - i - 1]分别与下一个数向右冒泡
            if (L.data[j] > L.data[j + 1]){
                int temp = L.data[j + 1];
                L.data[j + 1] = L.data[j];
                L.data[j] = temp;
            }
        }
    }
}

int Qsort(int a[], int left, int right) {   //单趟比较过程
    int temp = a[left];
    while (left < right) {
        while (left < right && a[right] >= temp)    right--;    //错+1
        a[left] = a[right];
        while (left < right && a[left] < temp)  left++;
        a[right] = a[left];
    }
    a[left] = temp;     //漏+1
    return left;
}

void quickSort(int a[], int left, int right) {
    if (left < right) {
        int key = Qsort(a, left, right);
        quickSort(a, left, key - 1);
        quickSort(a, key + 1, right);
    }
}