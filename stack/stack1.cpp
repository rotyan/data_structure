#include<cstdio>
#include<stack>
using namespace std;



int main(){
    stack<int> st;
    for(int i=1;i<6;i++){
        st.push(i);
    }
//    clear();
    printf("TOP==%d",st.top());
    getchar(); 
    return 0;
}

