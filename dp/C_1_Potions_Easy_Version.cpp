// https://codeforces.com/contest/1526/problem/C1
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // dp[i][k] = maximum health after considering first i potions
    // and taking exactly k potions.
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {

            // Option 1: Ignore the current potion
            if (dp[i - 1][k] != -1)
                dp[i][k] = max(dp[i][k], dp[i - 1][k]);

            // Option 2: Drink the current potion
            if (k > 0 && dp[i - 1][k - 1] != -1) {
                long long health = dp[i - 1][k - 1] + a[i];

                if (health >= 0)
                    dp[i][k] = max(dp[i][k], health);
            }
        }
    }

    int ans = 0;

    for (int k = n; k >= 0; k--) {
        if (dp[n][k] != -1) {
            ans = k;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}