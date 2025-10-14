#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll merge(int *a, int *b, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    ll ans = 0;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= right) b[k++] = a[j++];
    for (int idx = left; idx <= right; idx += 1) {
        a[idx] = b[idx];
    }
    return ans;
}

ll mergeSortAndCount(int *a, int *b, int left, int right) {
    if (left >= right) return 0;
    int mid = (left + right) >> 1;
    ll ans = 0;
    ans += mergeSortAndCount(a, b, left, mid);
    ans += mergeSortAndCount(a, b, mid + 1, right);
    ans += merge(a, b, left, mid, right);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    int b[n];
    ll cntInversions = mergeSortAndCount(a, b, 0, n - 1);
    int ryzeParity = n % 2;
    int missFortuneParity = 1;
    int invParity = cntInversions % 2;
    bool hasAdjacentIdentical = 0;  
    for (int i = 1; i < n; i += 1) {
        if (a[i] == a[i - 1]) {
            hasAdjacentIdentical = 1;
            break;
        }
    }
    if (ryzeParity == invParity || hasAdjacentIdentical) {
        cout << "Ryze can\n";
    } else {
        cout << "Ryze can't\n";
    }
    if (missFortuneParity == invParity || hasAdjacentIdentical) {
        cout << "Miss Fortune can";
    } else {
        cout << "Miss Fortune can't";
    }
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