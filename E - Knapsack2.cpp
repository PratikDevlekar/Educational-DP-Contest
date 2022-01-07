#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(v) (v).begin(), (v).end()
#define fl fflush(stdout)
int mod = 1e9 + 7;

void solve() {
    int n, W; cin >> n >> W;
    vector<pair<int, int>> val(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int w, v; cin >> w >> v;
        val[i] = {w, v};
        sum += v;
    }
    vector<vector<int>> dp(n + 1, vector<int>( sum + 1, INT_MAX));
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - val[i - 1].ss >= 0) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - val[i - 1].ss] + val[i - 1].ff);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i] <= W) {ans = max(ans, i);}
    }
    cout << ans;

}
signed main() {
    auto start = high_resolution_clock::now();
    IOS;
    int t = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    // cin >> t;
    int i = 1;
    while (t--) {
        // cout << "CASE #" << i << ": ";
        solve();
        cout << endl;
        i++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken:" << duration.count() / 1000000.0 << " seconds" << "\n";
    return 0;
}
