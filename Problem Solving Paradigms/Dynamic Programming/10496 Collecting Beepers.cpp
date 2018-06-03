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
int k;
int x[12];
int y[12];
int dist[12][12];
int dp[12][1 << 12];

int solve(int u, int mask) {
    if(mask == (1 << k) - 1) return dist[u][0];
    if(dp[u][mask] != -1) return dp[u][mask];
    int ans = INF;
    for(int i = 1; i < k; i++) {
        if(!(mask & (1 << i))) {
            int cur = solve(i, mask | (1 << i)) + dist[u][i];
            ans = min(ans, cur);
        }
    }
    return dp[u][mask] = ans;
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

        cin >> x[0] >> y[0];
        cin >> k;

        for(int i = 1; i <= k; i++) {
            cin >> x[i] >> y[i];
        }

        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= k; j++) {
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }

        k++;
        memset(dp, -1, sizeof dp);

        int ans = solve(0, 1);

        cout << "The shortest path has length " << ans << "\n";
    }

}