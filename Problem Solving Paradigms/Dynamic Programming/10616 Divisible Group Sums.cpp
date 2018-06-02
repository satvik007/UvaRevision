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

int n, q;
int a[210];
int dp[204][12][22];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;

    while(cin >> n >> q, n || q) {
        cout << "SET " << cas++ << ":\n";
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int d, m;
        int que = 1;
        while(q--) {
            cout << "QUERY " << que++ << ": ";
            cin >> d >> m;
            memset(dp, 0, sizeof dp);
            dp[0][0][0] = 1;

            for(int i = 1; i <= n; i++) {
                for(int j = 0; j <= m; j++) {
                    for(int k = 0; k < d; k++) {
                        dp[i][j][k] += dp[i - 1][j][k];
                        if(j) dp[i][j][k] += dp[i - 1][j - 1][((k - a[i]) % d + d) % d];
                    }
                }
            }
            cout << dp[n][m][0] << "\n";
        }

    }

}