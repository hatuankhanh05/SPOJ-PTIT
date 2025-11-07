#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    vector<int> neg, pos;
    for(int x : a) {
        if(x < 0) neg.push_back(x);
        else pos.push_back(x);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    ll res = 0;
    if(neg.size() < 1) {
        for(int &x : pos) {
            res += x;
        }
        if(k % 2 != 0) {
            res -= *pos.begin() * 2;
        }
    } else {
        if(k > neg.size()) {
            k -= neg.size();
            for(int &x : neg) {
                res += -x;
            }
            for(int &x : pos) {
                res += x;
            }
            int mn1 = -neg.back();
            int mn2 = *pos.begin();
            if(k % 2 != 0) {
                res -= min(mn1, mn2) * 2;
            }
        } else {
            for(int i = 0; i < k; i += 1) {
                res += (-neg[i]);
            }
            for(int i = k; i < neg.size(); i += 1) {
                res += neg[i];
            }
            for(int &x : pos) {
                res += x;
            }
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}