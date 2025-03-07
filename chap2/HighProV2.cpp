// 高精度数 * 高精度数
#include <iostream>

int main(){
    std::string s1,s2;
    std::cin>>s1;
    std::cin>>s2;
    int a[100], b[100], c[100] = {0};
    for(int i=0;i<s1.size();i++){ a[s1.size()-(i+1)] = s1[i] - '0'; }
    for(int i=0;i<s2.size();i++){ b[s2.size()-(i+1)] = s2[i] - '0'; }

    for(int i=0;i<s2.size();i++){
        for(int j=0;j<s1.size();j++){
            c[j+i] = c[j+i] + a[j] * b[i];
            c[j+i+1] += c[j+i] / 10;
            c[j+i] = c[j+i] % 10;
        }
    }
    // 寻找逆序的下标
    int index = 0;
    for(int i=s1.size()+s2.size();i>=0;i--){
        if(c[i]!=0){
            index = i;
            break;
        }
    }
    // 逆序输出
    for(int i=index;i>=0;i--){
        std::cout<<c[i];
    }
    return 0;
}
