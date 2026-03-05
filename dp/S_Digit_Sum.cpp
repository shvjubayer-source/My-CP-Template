// https://atcoder.jp/contests/dp/tasks/dp_s
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

string K;
int D;

// dp[pos][sum_mod][tight]
long long dp[10005][105][2];

long long digitDP(int pos, int sum_mod, int tight) {

    // If all digits processed
    if (pos == K.size()) {
        return (sum_mod == 0);  // valid if divisible by D
    }

    // If already computed
    if (dp[pos][sum_mod][tight] != -1)
        return dp[pos][sum_mod][tight];

    long long ans = 0;

    int limit = (tight ? K[pos] - '0' : 9);

    for (int d = 0; d <= limit; d++) {
        int new_tight = (tight && (d == limit));
        int new_sum_mod = (sum_mod + d) % D;

        ans = (ans + digitDP(pos + 1, new_sum_mod, new_tight)) % MOD;
    }

    return dp[pos][sum_mod][tight] = ans;
}

int main() {
    cin >> K >> D;

    memset(dp, -1, sizeof(dp));

    long long result = digitDP(0, 0, 1);

    // subtract 1 to exclude number 0
    result = (result - 1 + MOD) % MOD;

    cout << result << endl;

    return 0;
}