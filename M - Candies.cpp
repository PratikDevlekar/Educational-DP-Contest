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
// bool check = false;
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};

//DP
// int dp[400005];
vector<vector<int>> dp(3005, vector<int> (3005, -1));
vector<int> val(3005);
int ansdeque(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return val[i];
    else {
        dp[i][j] = max(val[i] - ansdeque(i + 1, j), val[j] - ansdeque(i, j - 1));
        return dp[i][j];
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << ansdeque(0, n - 1);
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