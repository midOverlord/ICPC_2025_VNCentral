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

struct vertex {
    int x, y, z;
};

void WONDERFUL() {
    int n, t; cin >> n >> t;
    int sum = n * (n + 1) / 2;
    vector<vertex> a;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(i + j + k == 3 * t - sum) a.push_back({i, j, k});
            }
        }
    }
    if(a.size() == 0) return void(cout << -1);
    vector<vector<int>> res;
    for(auto p: a) {
        vector<int> b = {p.x, p.y, p.z};
        vector<int> c;
        int k = (n + 3) / 3;
        for(int i = 1; i <= n; i++) {
            if(i != p.x && i != p.y && i != p.z) c.push_back(i);
        }
        do {
            sort(ALL(c));
            do {
                int e1 = b[0] + b[1], e2 = b[1] + b[2], e3 = b[2] + b[0];
                for(int i = 0; i < k - 2; i++) e1 += c[i];
                for(int i = k - 2; i < 2 * k - 4; i++) e2 += c[i];
                for(int i = 2 * k - 4; i < 3 * k - 6; i++) e3 += c[i];
                if(e1 == t && e2 == t && e3 == t) {
                    vector<int> tmp;
                    tmp.push_back(b[0]);
                    for(int i = 0; i < k - 2; i++) tmp.push_back(c[i]);
                    tmp.push_back(b[1]);
                    for(int i = k - 2; i < 2 * k - 4; i++) tmp.push_back(c[i]);
                    tmp.push_back(b[2]);
                    for(int i = 2 * k - 4; i < 3 * k - 6; i++) tmp.push_back(c[i]);
                    res.push_back(tmp);
                }
            } while(next_permutation(ALL(c)));
        } while(next_permutation(ALL(b)));
    }
    sort(ALL(res));
    if(res.size() == 0) return void(cout << -1);
    for(int i = 0; i < res.size(); i++) {
        for(auto x: res[i]) cout << x << ' '; cout << '\n';
    }
    cout << res.size();
}

__T1_VO_DICH__ {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    WONDERFUL();
    return 0;
}
