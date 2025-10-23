#include <bits/stdc++.h>
using namespace std;
#define  ALL(v)  (v).begin(), (v).end()
#define  RALL(v)  (v).rbegin(), (v).rend()
#define  MASK(i)  (1LL << (i))
#define  BIT(x, i)  (((x) >> (i)) & 1)
#define  __Aespa_Giselle__  signed main()

const int MAXN = 1e5 + 5;
const int MAX_BIT = 26;

int n, a[MAXN], f[MAXN];
vector<pair<int, int>> adj[MAXN];

void dfs(int u, int par) {
    for(auto [v, w]: adj[u]) if(v != par) {
        f[v] = f[u] ^ w;
        dfs(v, u);
    }
}

void WONDERFUL() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, -1);
    long long ans = 0;
    for(int i = 0; i < MAX_BIT; i++) {
        int cnt = 0;
        for(int u = 1; u <= n; u++) cnt += BIT(f[u], i);
        ans += MASK(i) * cnt * (n - cnt); 
    }
    cout << ans;
}

__Aespa_Giselle__ {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ///int T; cin >> T; while(T--)
    WONDERFUL();
    return 0;
}
