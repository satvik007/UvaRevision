#define BZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;

#define maxn 100010

int n, m;
ii f, s;
ii a[20];
bool flag;

void solve(int mask, int last, int cnt) {
    if(cnt == n) {
        if(s.first == last) flag = true;
        return;
    }
    for(int i = 0; i < m; i++) {
        if(!(mask & (1 << i))) {
            if(a[i].first == last) {
                solve(mask | (1 << i), a[i].second, cnt + 1);
            }
            if(a[i].second == last) {
                solve(mask | (1 << i), a[i].first, cnt + 1);
            }
        }
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n, n) {
        cin >> m;
        cin >> f.first >> f.second;
        cin >> s.first >> s.second;
        for(int i = 0; i < m; i++) {
            cin >> a[i].first >> a[i].second;
        }
        flag = false;
        solve(0, f.second, 0);
        cout << (flag ? "YES\n": "NO\n");
    }

}