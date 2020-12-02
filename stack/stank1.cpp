#include<cstdio>
#include <stdlib.h>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    for(int i=1;i<6;i++){
        st.push(i);
    }
    int x;
    scanf("%d",&x);
    printf("TOP==%d\n%d",st.top(),x);
    getchar(); 
    return 0;
}



