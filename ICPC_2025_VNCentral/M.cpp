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

const int MAXN = 105;

int n;
pair<int, int> a[MAXN];

int f(int ax, int ay, int bx, int by) {
    return abs(ax - bx) + abs(ay - by);
}

void WONDERFUL() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].st >> a[i].nd;
    int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
    long long ans = LLONG_MAX;
    for(int x = 0; x < MASK(n); x++) {
        vector<int> pa, pb;
        for(int i = 0; i < n; i++) {
            if(BIT(x, i)) pa.push_back(i);
            else pb.push_back(i);
        }
        long long resA = 1e9;
        do {
            long long cur = 0, cnt = 0;
            pair<int, int> pre = {xa, ya};
            for(int i = 0; i < pa.size(); i++) {
                cur = cur + cnt * f(pre.st, pre.nd, a[pa[i]].st, a[pa[i]].nd);
                pre = a[pa[i]]; cnt++;
            }
            cur += cnt * f(pre.st, pre.nd, xa, ya);
            resA = min(resA, cur);
        } while(next_permutation(ALL(pa)));
        long long resB = 1e9;
        do {
            long long cur = 0, cnt = 0;
            pair<int, int> pre = {xb, yb};
            for(int i = 0; i < pb.size(); i++) {
                cur = cur + cnt * f(pre.st, pre.nd, a[pb[i]].st, a[pb[i]].nd);
                pre = a[pb[i]];
                cnt++;
            }
            cur += cnt * f(pre.st, pre.nd, xb, yb);
            resB = min(resB, cur);
        } while(next_permutation(ALL(pb)));
        ans = min(ans, resA + resB);
    }
    cout << ans;
}

__T1_VO_DICH__ {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    WONDERFUL();
    return 0;
}
