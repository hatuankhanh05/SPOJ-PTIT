#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    int cnt[3] = {};
    for (int &x : a) {
        if (x == 25) {
            cnt[0] += 1;
        } else if (x == 50) {
            if (cnt[0]) {
                cnt[0] -= 1;
                cnt[1] += 1;
            } else {
                cout << "NO";
                return;
            }
        } else {
            if (cnt[1] && cnt[0]) {
                cnt[1] -= 1;
                cnt[0] -= 1;
                cnt[2] += 1;
            } else if (cnt[0] >= 3) {
                cnt[0] -= 3;
                cnt[2] += 1;
            } else {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc += 1) {
        solve();
    }
}