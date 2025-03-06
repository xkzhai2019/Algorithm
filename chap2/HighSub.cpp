#include <iostream>

int main(){
    std::string s1, s2;
    std::cin>>s1;
    std::cin>>s2;
    char flag = '+';
    if(s1.size()<s2.size() || s1.size()==s2.size() && s1<s2){
        swap(s1,s2);
        flag = '-';
    }
    int a1[100], a2[100], a3[100] = {0};
    for(int i=0;i<s1.size();i++){ a1[s1.size()-(i+1)] = s1[i] - '0'; }
    for(int i=0;i<s2.size();i++){ a2[s2.size()-(i+1)] = s2[i] - '0'; }
    
    for(int i=0; i<s1.size(); i++){
        if(a1[i] < a2[i]){
            a1[i] += 10;
            a1[i+1] = a1[i+1] - 1;
        }
        a3[i] = a1[i] - a2[i]; 
    }
    if(flag=='-'){
        std::cout<<flag;
    }
    // 寻找倒序的下标
    int index = 0;
    for(int i=s1.size()-1;i>=0;i--){
        if(a3[i]!=0){
            index = i;
            break;
        }
    }
    // 倒序输出
    for(int i=index;i>=0;i--){
        std::cout<<a3[i];
    }
    return 0;
}
