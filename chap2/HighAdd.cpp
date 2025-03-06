#include <iostream>

int main(){
    //std::string s1 = "1111111111111111111111";
    //std::string s2 = "22222222222222222222";
    std::string s1;
    std::string s2;
    std::cin>>s1;
    std::cin>>s2;
    int a1[100] = {0};
    int a2[100] = {0};
    int a3[100] = {0};
    for(int i=0;i<s1.size();i++){
        a1[s1.size()-(i+1)] = s1[i] - '0';
    }
    for(int i=0;i<s2.size();i++){
        a2[s2.size()-(i+1)] = s2[i] - '0';
    }
    int len = s1.size() > s2.size() ? s1.size(): s2.size();
    for(int i=0;i<len;i++){
        a3[i] = a1[i] + a2[i];
    }
    for(int i=0;i<len;i++){
        if(a3[i]>=10){
            a3[i+1] += a3[i]/10;
            a3[i] = a3[i] % 10;
        }
    }
    if(a3[len]!=0) len++;
    for(int i=len-1;i>=0;i--){
        std::cout<<a3[i];
    }   
    std::cout<<std::endl;
    return 0;
}
