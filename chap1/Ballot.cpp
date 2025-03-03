#include <iostream>

int main(){
    int n = 3;
    int m = 9;
    int a[] = {1,3,5};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    if(a[i]+a[j]+a[k]+a[l]==m){
                        std::cout<<"Yes"<<std::endl;
                        return 0;
                    }
                }
            }
        }
    }
    std::cout<<"No"<<std::endl;
    return 0;
}
