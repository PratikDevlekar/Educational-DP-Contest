#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define sz(x) (int)x.size()
#define all(v) (v).begin(), (v).end()

#define hell2 998244353
int mod = 1e9 + 7;


void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    if (dp[n][m] == 0) {
        return;
    }
    else {
        int i = n, j = m;
        string ans;
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                ans += s[i - 1];
                i--; j--;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
        reverse(all(ans));
        cout << ans;
    }
}


signed main() {
    cin.tie(NULL);
    auto start = high_resolution_clock::now();
    IOS;
    int t = 1;
    // seive();
    // fac[0] = 1; fac[1] = 1;
    // rep(i, 2, 300005)fac[i] = (fac[i - 1] * i) % hell;
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
    cerr << "Time taken : " << duration.count() / 1000000.0 << " seconds" << "\n";
    return 0;
}