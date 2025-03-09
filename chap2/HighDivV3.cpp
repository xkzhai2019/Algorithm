#include <iostream>
#include <cstring>

// 偏移拷贝数组
void cpyArr(int x[], int y[], int offset){
    for(int i=1; i<=x[0]; i++){
        y[i+offset] = x[i];
    }
    y[0] = x[0] + offset;
}

// 数组比较大小
bool compArr(int x[], int y[]){
    for(int i=1;i<=x[0];i++){
        if(x[i]>y[i]){
            return true;
        }
        if(x[i] < y[i]){
            return false;
        }
    }
    return true;
}

// 数组相减
void sub(int x[], int y[]){
    for(int i=x[0];i>=1;i--){
        if(x[i] < y[i]){
            x[i] = x[i] + 10;
            x[i-1] = x[i-1] - 1;
        }
        x[i] = x[i] - y[i];
    }
}

int main(){
    std::string s1,s2;
    std::cin>>s1;
    std::cin>>s2;
    int a[250],b[250],c[250]={0}; //被除数、除数、商
    a[0] = s1.size();
    b[0] = s2.size();
    for(int i=1;i<=a[0];i++){ a[i] = s1[i-1] - '0';}
    for(int i=1;i<=b[0];i++){ b[i] = s2[i-1] - '0';}
    c[0] = a[0] - b[0] + 1;
    int t[500] = {0}; // 除数临时数组
    // 循环计算商
    for(int i=1; i<=c[0];i++){
        memset(t,0,sizeof(t));
        cpyArr(b,t,i-1);
        a[0] = t[0];
        while(compArr(a,t)){//a 数组 >= t数组
            // a数组 = a数组 - t数组
            sub(a,t);
            c[i]++;
        }
    }
    // 输出商
    int index = 1;
    for(int i=1;i<=c[0];i++){
        if(c[i]!=0){
            index = i;
            break;
        }
    }
    std::cout<<"商为：";
    for(int i=index;i<=c[0];i++){
        std::cout<<c[i];
    }
    //输出余数
    index = 1;
    for(int i=1;i<=a[0];i++){
        if(a[i]!=0){
            index = i;
            break;
        }
    }
    std::cout<<"，余数为";
    for(int i=index;i<=a[0];i++){
        std::cout<<a[i];
    }
    
    return 0;
}
