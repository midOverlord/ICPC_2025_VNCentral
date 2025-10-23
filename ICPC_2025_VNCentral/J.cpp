#include <bits/stdc++.h>
using namespace std;
#define  st  first 
#define  nd  second
#define  ALL(v)  (v).begin(), (v).end()
#define  RALL(v)  (v).rbegin(), (v).rend()
#define  MASK(i)  (1LL << (i))
#define  BIT(x, i)  (((x) >> (i)) & 1)
#define  __T1_VO_DICH__  signed main()

const int MAXN = 1e2 + 5;

int n, m, visited[5][MAXN][MAXN];
pair<int, int> s, d;
char a[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool valid(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void WONDERFUL() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') s = {i, j};
            else if(a[i][j] == 'D') d = {i, j};
        }
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({3, s});
    visited[3][s.st][s.nd] = 1;
    while(q.size()) {
        int hp = q.front().st, u = q.front().nd.st, v = q.front().nd.nd; q.pop();
        if(u == d.st && v == d.nd) return void(cout << visited[hp][u][v] - 1 << '\n');
        for(int i = 0; i < 4; i++) {
            int x = u + dx[i], y = v + dy[i];
            if(valid(x, y)) {
                int _hp = hp - (a[x][y] == '+');
                if(!visited[_hp][x][y] && _hp > 0) {
                    q.push({_hp, {x, y}});
                    visited[_hp][x][y] = visited[hp][u][v] + 1;
                }
            }
        }
    }
    cout << -1;
}

__T1_VO_DICH__ {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    WONDERFUL();
    return 0;
}
