#include <bits/stdc++.h>
using namespace std;
#define  ALL(v)  (v).begin(), (v).end()
#define  RALL(v)  (v).rbegin(), (v).rend()
#define  MASK(i)  (1LL << (i))
#define  BIT(x, i)  (((x) >> (i)) & 1)
#define  __Aespa_Giselle__  signed main()

int ask(int id, int pos) {
    cout << "? " << 6 * id + pos << endl;
    int res; cin >> res;
    return res;
}

void WONDERFUL() {
    int n; cin >> n;
    vector<int> index;
    for(int i = 0; i < n; i++) index.push_back(i);
    vector<int> visited(7, 0), ans;
    for(int pos = 1; pos <= 6; pos++) {
        map<int, int> color;
        for(auto id: index) color[id] = ask(id, pos);
        vector<int> cnt(7, 0);
        for(auto [id, c]: color) cnt[c]++;
        int cur = 0;
        for(int i = 1; i <= 6; i++) if(!visited[i]) {
            if(cur == 0 || cnt[i] < cnt[cur]) {
                cur = i;
            }
        }
        ans.push_back(cur);
        visited[cur] = 1;
        index.clear();
        for(auto [id, c]: color) if(c == cur) index.push_back(id);
    }
    cout << "!";
    for(auto c: ans) cout << ' ' << c;
    cout << endl;
}

__Aespa_Giselle__ {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T1; cin >> T1; while(T1--)
    WONDERFUL();
    return 0;
}
