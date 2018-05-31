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

int a[110][110];
int n, m;

vi ans;

void solve(int u, vi cur) {
    if(cur.size() > ans.size()) ans = cur;
    for(int i = u; i <= n; i++) {
        bool flag = true;
        for(auto el: cur) {
            if(a[el][i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cur.push_back(i);
            solve(i + 1, cur);
            cur.pop_back();
        }
    }
}


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) a[i][j] = 0;
        }

        int u, v;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
        }
        ans.clear();
        vi cur;
        solve(1, cur);

        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++) {
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";

    }

}