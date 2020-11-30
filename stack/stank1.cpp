#include<cstdio>
#include <stdlib.h>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    for(int i=1;i<6;i++){
        st.push(i);
    }
    printf("TOP==%d",st.top());
    getchar(); 
    return 0;
}

