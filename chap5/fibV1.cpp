#include <iostream>
#include <cassert>
using namespace std;
int number;
// 递归计算斐波那契数列
int fib(int n){
    number++;
    assert(n>=1);
    if(n==1 || n==2){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin>>n;
    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();
    cout<<"fib("<<n<<")="<<res<<endl;
    cout<<"time:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"call fib(): "<<number<<" times."<<endl;
    return 0;
}
