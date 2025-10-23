#include <bits/stdc++.h>
using namespace std;
#define  st  first 
#define  nd  second
#define  int  long long
#define  ALL(v)  (v).begin(), (v).end()
#define  RALL(v)  (v).rbegin(), (v).rend()
#define  MASK(i)  (1LL << (i))
#define  BIT(x, i)  (((x) >> (i)) & 1)
#define  __T1_VO_DICH__  signed main()

const int MAXN = 2e5 + 5;

int n, m, speed, s, t, g[MAXN];
vector<pair<int, long double>> a[MAXN];
long double dist[MAXN];

void WONDERFUL() {
    cin >> n >> m >> speed;
    for(int i = 1; i <= m; i++) {
        int u, v;
        long double d;
        cin >> u >> v >> d;
        a[u].push_back({v, d / speed});
        a[v].push_back({u, d / speed}); 
    }
    cin >> s >> t;
    for(int i = 1; i <= n; i++) {
        dist[i] = LDBL_MAX;
        g[i] = a[i].size();
    }
    priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(pq.size()) {
        long double time = pq.top().st;
        int u = pq.top().nd; pq.pop();
        if(time > dist[u]) continue;
        int x = g[u];
        if(u == s) x = 0;
        for(auto p: a[u]) {
            int v = p.st;
            long double w = p.nd;
            if(dist[u] + w + max(0LL, x - 2) < dist[v]) {
                dist[v] = dist[u] + w + max(0LL, x - 2);
                pq.push({dist[v], v});
            }
        }
    }
    cout << fixed << setprecision(6) << dist[t];
}

__T1_VO_DICH__ {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    WONDERFUL();
    return 0;
}
