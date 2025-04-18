#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[10];
bool hashOption[11];

void dfs(int k) {
    if (k == n) {
        for (int i = 0; i < k; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (hashOption[i]) {
            a[k] = i;
            hashOption[i] = false;
            dfs(k + 1);
            hashOption[i] = true;
        }
}

void dfs_init() {
    memset(hashOption, 1, sizeof(hashOption));
    memset(a, 0, sizeof(a));
    dfs(0);
}

int main() {
    cin >> n;
    dfs_init();
}
