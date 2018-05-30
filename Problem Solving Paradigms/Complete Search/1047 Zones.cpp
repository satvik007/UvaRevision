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

int n, k;
int m;

int cust[22];
vi com[12];
int cost[12];
vi ans;
int max1;

void solve(int u, int v, vi cur) {
    if(v == k) {
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            cnt += cust[cur[i]];
        }
        for(int i = 0; i < m; i++) {
            int val = 0;
            for(int j = 0; j < com[i].size(); j++) {
                if(find(cur.begin(), cur.end(), com[i][j]) != cur.end()) val++;
            }
            if(val) cnt -= (val - 1) * cost[i];
        }
        if(cnt > max1) {
            max1 = cnt;
            ans = cur;
        }
        return;
    }
    if(u >= n) return;
    cur.push_back(u);
    solve(u + 1, v + 1, cur);
    cur.pop_back();
    solve(u + 1, v, cur);

}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;

    while(cin >> n >> k, n || k) {
        for(int i = 0; i < n; i++) cin >> cust[i];
        cin >> m;

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u;
            com[i].resize(u);
            for(int j = 0; j < u; j++) {
                cin >> v;
                com[i][j] = v - 1;
            }
            cin >> cost[i];
        }
        max1 = -1;
        ans.resize(k);
        vi emp;
        solve(0, 0, emp);

        cout << "Case Number  " << cas++ << "\n" <<
                "Number of Customers: " << max1 << "\n" <<
                "Locations recommended:";

        for(auto el: ans) cout << " " << el + 1; cout << "\n\n";

    }

}