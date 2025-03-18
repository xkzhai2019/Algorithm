#include <iostream>
using namespace std;
int main(){
    int m,s,t;
    cin>>m>>s>>t;
    int dis = 0;
    // 按秒循环
    int i = 0;
    for(i=1;i<=t && dis< s;i++){
        if(m<2){
            if(t-i+1<=6 || s-dis<=102){
                dis += 17;
            }else{
                m += 4;
            }
        }else if(m<6){
            if(t-i+1 <= 2 || s-dis<=34){
                dis += 17;
            }else{
                m += 4;
            }
        }else if(m<10){
            if(t-i+1<=1 || s-dis<=17){
                dis += 17;
            }else{
                m += 4;
            }
        }else{// 魔法值够闪，直接闪
            dis += 60;
            m -= 10;
        }
    }
    if(dis>=s){
        cout<<"Yes"<<endl<<i-1<<endl;
    }   
    if(dis<s){
        cout<< "No"<<endl<<dis<<endl;
    }   
    return 0;
}
