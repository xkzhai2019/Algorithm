// 高精度数 * 单精度数
#include <iostream>

int main(){
    std::string s1,s2;
    int b;
    std::cin>>s1>>b;
    int a[100] = {0};
    for(int i=0;i<s1.size();i++){ a[s1.size()-(i+1)] = s1[i] - '0'; }
    for(int i=0; i<s1.size(); i++){ // 从左向右相乘
        a[i] = a[i]*b;
    }

    // 计算单精度整数b的长度
    int b_len = 0;
    while(b!=0){
        b /= 10;
        b_len++;
    }
    // 向右进位
    for(int i=0; i<s1.size()+b_len; i++){
        a[i+1] += a[i]/10;
        a[i] = a[i] % 10;
    }
    // 寻找逆序的下标
    int index = 0;
    for(int i=s1.size()+b_len-1;i>=0;i--){
        if(a[i]!=0){
            index = i;
            break;
        }
    }
    // 逆序输出
    for(int i=index;i>=0;i--){
        std::cout<<a[i];
    }
    return 0;
}
