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
    int n; cin >> n;
    int val[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    int dp[n];
    dp[0] = 0, dp[1] = abs(val[1] - val[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(val[i] - val[i - 1]), dp[i - 2] + abs(val[i] - val[i - 2]));
    }
    cout << dp[n - 1];
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
