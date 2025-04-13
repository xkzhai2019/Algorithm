#include <bits/stdc++.h>
using namespace std;

vector<int> b; // 在全局范围内声明b数组

void judge(int k) {
    int x = 0;
    for (int i = 0; i <= k; ++i) {
        x = (x * 10 + b[i]) % 13;
    }
    if (x == 0) {
        for (int i = 0; i <= k; ++i)
            cout << b[i];
        cout << endl;
    }
}

void search(int k) {
    if (k >= n) return;

    for (int i = 0; i < max_size; ++i) {
        if (a[i] > 0 && !used[i]) {
            used[i] = true;
            b[k] = a[i];
            a[i]--;
            judge(k);
            a[i]++;
            used[i] = false;
            search(k + 1);
            b[k] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a;
    vector<bool> used;
    int n = 0;

    for (int i = 0; i <4; ++i) {
        cin >> a[i];
        n++;
    }

    vector<int> b(n, 0);
    vector<bool> used(b.size(), false);

    search(0);
}

