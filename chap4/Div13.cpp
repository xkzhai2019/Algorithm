#include<bits/stdc++.h>
using namespace std;

int a[100], hashOption[110],n;
//int hashState[100];
int b[100];

void judge(int k) {
    int x = 0;
    for (int i = 0; i <= k; i++) {
        x = (x * 10 + b[i])%13;
    }
    if (x == 0) {
        for (int i = 0; i <= k; i++)
            cout << b[i];
        cout << endl;
    }
}

void dfs_search(int k) {
    if (k == n)
        return;
    
    for (int i = 0; i < n; i++){
        if (hashOption[i]){
            if (k == 0 && a[i] == 0)
                continue;
            b[k] = a[i];
            /*
            if(hashState[a[i]]){
                continue;
            }
            hashState[a[i]] = true;
            */
            hashOption[i]=false;
            judge(k);
            dfs_search(k+1);
            hashOption[i]=true;
        }
    }
}

int main() {
    cin>>n;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    // memset(hashState,0,sizeof(hashState));
    memset(hashOption,1,sizeof(hashOption));
    memset(b,0,sizeof(b));
    dfs_search(0);
    
}
