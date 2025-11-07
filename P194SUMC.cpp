#include <bits/stdc++.h>
using namespace std;

map<long long, int> prime_factorize(long long n) {
    map<long long, int> factors;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    map<long long, int> factors = prime_factorize(N);
    int steps = 0;

    while (true) {
        bool all_even = true;
        for (auto [p, e] : factors)
            if (e % 2 != 0) { all_even = false; break; }

        if (all_even) {
            // perform sqrt operation
            map<long long, int> new_factors;
            for (auto [p, e] : factors)
                new_factors[p] = e / 2;
            factors = new_factors;
            steps++;
        } else {
            // multiply by minimal x to make exponents even
            for (auto &[p, e] : factors)
                if (e % 2 != 0) e++;
            steps++;
        }

        // check if any exponent is odd now and cannot be reduced further
        bool can_continue = false;
        for (auto [p, e] : factors)
            if (e > 0) can_continue = true;
        if (!can_continue) break;

        bool all_zero_or_even = true;
        for (auto [p, e] : factors)
            if (e % 2 != 0) { all_zero_or_even = false; break; }

        if (!all_zero_or_even) break;
    }

    long long min_value = 1;
    for (auto [p, e] : factors)
        min_value *= pow(p, e);

    cout << min_value << " " << steps << "\n";
    return 0;
}
