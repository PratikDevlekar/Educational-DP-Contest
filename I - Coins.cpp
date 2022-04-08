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
int mod = 1e9 + 7;

// Graph box
// int u, v;
// vector<int> adj[400005];
// vector<vector<int>> mat(501, vector<int>(501, 0));
// vector<vector<int>> vis(501, vector<int>(501, 0));
// bool vis[400005];
// int dp[400005];
// bool check = false;
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};

void solve() {
    int n; cin >> n;
    vector<double> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        double x; cin >> x;
        for (int j = i + 1; j >= 0; j--) {
            if (j == 0)
                dp[j] = dp[j] * (1 - x);
            else
                dp[j] =  dp[j - 1] * x + dp[j] * (1 - x);
        }
    }
    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
        ans += dp[i];
    }
    cout << setprecision(10) << ans;
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