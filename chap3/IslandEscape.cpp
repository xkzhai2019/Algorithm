#include <iostream>
using namespace std;
int main(){
    int m,s,t;
    cin>>m>>s>>t;
    int dis = 0;
    // 按秒循环
    for(int i=1;i<=t && dis<s ;i++){
        if(m>=10){// 魔法值够闪现，立刻闪
            dis += 60;
            m -= 10;
        }else{// 魔法值不够闪，看剩余时间和剩余距离
            if(m<2 && (t-i+1 <= 6 || s-dis <= 102) 
                || m<6 && (t-i+1 <= 2 || s-dis <= 34)
                || m<10 && (t-i+1 <=1 || s-dis <= 17))
                dis += 17;
            else{
                m += 4; // 原地休息，回复魔法值
            }
        }
        if(dis>=s){
            cout<<"Yes: "<<i<<"s"<<endl;
            break;
        }
    }
    if(dis<s){
        cout<< "No: "<<dis<<endl;
    }
    return 0;
}
