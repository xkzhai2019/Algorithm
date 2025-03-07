#include <iostream>
int main(){
    std::string s;
    int b;
    std::cin>>s>>b;
    int a[100],c[100]; // 被除数与商
    for(int i=0;i<s.size();i++){
        a[i] = s[i] - '0';
    }
    int t = 0;
    for(int i=0;i<s.size();i++){
        t = t*10 + a[i];
        if(t>=b){
            c[i] = t/b;
            t = t%b;
        }else{
            c[i] = t/b;            
        }
    }
    // 逆序输出
    int index = 0;
    for(int i=0;i<s.size();i++){
        if(c[i]!=0){
            index = i;
            break;
        }
    }
    for(int i=index;i<s.size();i++){
        std::cout<<c[i];
    }
    std::cout<<" "<<t<<std::endl;
    return 0;
}
