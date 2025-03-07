#include <iostream>
int main(){
    int a,b,n;
    std::cin>>a>>b>>n;
    std::cout<<a/b<<".";
    int t = a%b;
    for(int i=0;i<n;i++){
        t = t*10;
        std::cout<<t/b;
        t = t%b;
    }
    std::cout<<std::endl;
    return 0;
}
