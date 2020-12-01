//数组中数据取最大值，引入第三方变量-1进行遍历
#include <stdio.h>

/*
    首行给参赛人数（不超过10^5），之后n行每行给出学校编号和比赛成绩，最后输出最高成绩的学校编号和成绩
*/   

/*
    分析；循环数组获得学校编号str1和比赛成绩str2，if str1==str1,total+=str2，if total []MAX,printf. 
    更正：获取学校编号用散列（数组进行预处理）school[ID]，比赛成绩直接用预处理过的数组进行记分school[ID]+=score,遍历if school[ID]>MAX MAX=school[ID] num=ID;
  答案思路：「1」输入参赛数目；「2」循环输入学校编号和学校成绩，同时对学校成绩求和；「3」遍历学校，求最大值，记录最大值学校的编号；「4」输出。
*/
int school[10001]={0};//【1】注意数组过大（10w）要定义在主函数之外；【2】数组赋值直接用{}或{0}，全为0；
int main(){
    int n,ID,score;    
    //    int n,ID,score,school[];//【3】数组定义时下标最好有数字
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&ID,&score);     
        //   scanf("%d%d",ID,score);//【4】scanf数据格式后要用变量地址（加&）
        school[ID]+=score;        
        //    school[ID]=score;//*【5】学校总分直接求和，因为后边只有区最大值操作
    }
    int MAX=-1,num;
    for(int i=1;i<=n;i++){      
        //      for(int i=0;i<100000;i++){  //*【6】注意题目，写明了学校编号是从一开始的"连续"编号
        if(school[i]>MAX){     
            //  if(school[ID]>MAX){ //*同【6】，【7】这个对数组取大小的方法可以学习：首先输入MAX变量为-1（避免数据均为0），然后从ａ【0】开始遍历比较，谁大则送入MAX中更新数据。
            MAX=school[i];
            num=i;
        }
    }
    printf("%d %d",num,MAX);  
    //    printf("%d %d",&num,&MAX);//【8】printf输出时数据格式后是变量名（不加&）
    return 0;
}
