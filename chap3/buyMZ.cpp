#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a[10];
    int b[10];
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);

    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            cout<<"no"<<endl;
            return -1;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
