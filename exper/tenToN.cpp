//用栈实现十进制转n进制
#include <cstdio>
#include <stack> 
using namespace std;

//p进制转10进制
int nTo10(int x, int p){    //两个参数分别为当前p进制和该进制下的值x
    int y = 0, product = 1;
    while(x){
        y += (x % 10) * product; 
        x /= 10;
        product *= p;   //根据书上改进
    }
    return y;
}

//10进制转p进制
int TenToN(int x, int p){    //两个参数分别为目标p进制和该进制下的值x
    stack<int> st;
    int MAX = 0,y = 0;  //
    while(x){
        st.push(x % p);
        x /= p;
        MAX++;
    }
    int a[MAX];
    for(int i=0; i < MAX; i++){
        while(st.empty()){
            a[i] = st.top();
            st.pop();
        }
        y = y * 10 + a[i];
    }
    return y;
}

int main(){
    printf("%d",TenToN(11，2));
    //？？？
    return 0;
}
