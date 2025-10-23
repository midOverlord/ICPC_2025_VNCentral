#include <bits/stdc++.h>
using namespace std;
#define  ALL(v)  (v).begin(), (v).end()
#define  RALL(v)  (v).rbegin(), (v).rend()
#define  MASK(i)  (1LL << (i))
#define  BIT(x, i)  (((x) >> (i)) & 1)
#define  __T1_VO_DICH__  signed main()

string a[] = {"-", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

void WONDERFUL() {
    string str; cin >> str;
    if(str[0] >= '0' && str[0] <= '9') {
        int cur = 0;
        cur += (str[0] - '0');
        if(str.size() > 1) cur = cur * 10 + (str[1] - '0');
        cout << a[cur];
    } else {
        for(int i = 1; i <= 20; i++) {
            if(a[i].size() == str.size()) {
                int cnt = 0;
                for(int j = 0; j < str.size(); j++) if(a[i][j] != str[j]) cnt++;
                if(cnt <= 1) return void(cout << i);
            }
        }
    }
}

__T1_VO_DICH__ {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    WONDERFUL();
    return 0;
}
