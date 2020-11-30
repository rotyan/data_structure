#include<cstdio>
#include<stack>
using namespace std;

void clear(){
  //  TOP==-1;
}

int main(){
    stack<int> st;
    for(int i=1;i<6;i++){
        st.push(i);
    }
    clear();
    printf("TOP==%d",st.top());
    getchar(); 
    return 0;
}

