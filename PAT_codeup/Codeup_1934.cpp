//scanf输入数组时候不加取地址符&会崩溃（程序停止工作）
#include <stdio.h>

//题目：输入1<=n<=200 ，然后输入n个不同的值，在输入x，求所在数组下标。若无则输出-1  
/*
分析：【1】for scanf（"%d"，&a【i】）；【2】遍历a【i】比较x==a【i】，printf i或者-1.
*/

int main() {
    int n;
    scanf("%d",&n);
    int a[n]={};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
		//    scanf("%d",a[i]);	//【1】scanf输入数组时候不加取地址符&会崩溃（程序停止工作） 
    }
    int x,j=0;
		//	int x,a=0; 	// 【2】定义普通变量量名不能和数组名相同 
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if(a[i]==x){
            printf("%d",i); //      else printf("-1");
            j++;
        }
      }
      //若遍历之后数组无此值，则输出-1
    if(!j) printf("-1");
		//if(j) printf("-1");	【3】技巧if(！i)是if(i==0);if(i)是if(i!=0); 
	return 0;
}
