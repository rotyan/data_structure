#include <cstdio>
#include <cstring>
#define INF (1<<30)-1
const double pi2 = 3.243;

int main() { 
    int i = INF;
    int a[5] = {};
    char b = 15555;
    char str[10][10][10];
    long long int x = 1231321412141412LL;
    int *p = a, *q = a;
    char* p2 = &b;
    // static int test;
    printf("%d\n", sizeof(q));
    printf("%d\n", sizeof(p2));
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof*a);
    printf("%d\n", sizeof &a[0]);
    printf("%d\n", sizeof(a[0]));
    printf("%d\n", strlen(p2));
    printf("%d\n", sizeof str);
	return 0;
}
