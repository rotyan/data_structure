#include <cstdio>

int main() {
    int a, b;
    scanf("&d &d", &a, &b);
    int sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = 0 - sum;
    } 
    int array[10];
    for (int i = 0; i < 10; i++){
        array[i] = (sum % 10) ;
    }
    while (sum > 999) {
        for (int i = 9; i >= 0; i--){
            while (array[i])    printf("%d", array[i]);
        }
    }
    return 0;
}