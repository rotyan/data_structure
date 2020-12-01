#include <cstdio>

struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}  //哈？这个剧本不一样啊
}pt[10];

int main(){
    int num = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++){
            pt[num++] = Point(i,j);
        }
    }
    for(int i = 0; i < num; i++){
        printf("pt[iii]==[%d,%d]\n",pt[i].x,pt[i].y);
    }
    getchar();   
    return 0;
}

