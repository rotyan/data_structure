#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = 0 - sum;
    } 
    int array[10];
    int len = 0;
    if (!sum) array[len++] == 0; //sum为0时特殊处理
    //将sum存入数组array[]中，低位对应低位
    while (sum) {
        array[len++] = sum % 10;        
        sum /= 10;
    }
    for (int i = len - 1; i >= 0; i--){
        printf("%d", array[i]);
        if (i % 3 == 0) printf(",");
    }
    // for (int i = 0; i < 10; i++){
    //     array[i] = (sum % 10) ;
    // }
    // while (sum > 999) {
    //     for (int i = 9; i >= 0; i--){
    //         while (array[i]){
    //             printf("%d", sizeof(array[i]));
    //         }
    //     }
    // }
    return 0;
}