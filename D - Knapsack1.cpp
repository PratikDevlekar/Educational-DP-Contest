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
    for (int i = 0; i < n; i++) {
        int w, v; cin >> w >> v;
        val[i] = {w, v};
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= W; i++) {
            if (i - val[k - 1].ff >= 0) {
                dp[k][i] = max(dp[k - 1][i], dp[k - 1][i - val[k - 1].ff] + val[k - 1].ss);
            }
            else {
                dp[k][i] = dp[k - 1][i];
            }
        }
    }
    cout << dp[n][W];

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
