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

#define maxn 50010

int n;
vi a[maxn];
int visited[maxn];
int dp[maxn];
bool flag;
int ind;

int dfs1(int u) {
    if(dp[u]) return dp[u];
    visited[u] = 2;
    int ans = 1;
    for(auto el: a[u]) {
        if(visited[el] == 2) {
            flag = true;
            ind = el;
        } else
            ans += dfs1(el);
    }
    return dp[u] = max(dp[u], ans);
}

void dfs2(int u, int ans) {
    visited[u] = 1;
    for(auto el: a[u]) {
        if(visited[el] == 2) {
            dfs2(el, ans);
        }
    }
    dp[u] = max(dp[u], ans);
}

void dfs3(int u) {
    visited[u] = 1;
    for(auto el: a[u]) {
        if(visited[el] == 2) {
            dfs3(el);
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
    int cas = 1;
    while(tc--) {
        cin >> n;
        for(int i = 0; i <= n; i++) a[i].clear();
        int u, v;
        for(int i = 0; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
        }
        memset(visited, 0, sizeof visited);
        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0) {
                flag = false;
                dfs1(i);
                if(flag) dfs2(ind, dp[ind]);
                dfs3(i);
            }
        }
        cout << "Case " << cas++ << ": ";
        int ans = max_element(dp, dp + n + 1) - dp;
        cout << ans << "\n";

    }


}