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

ll a[110][110];
ll dp[110][110][110][110];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    ll res = - (1LL << 60);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int p = i; p <= n; p++) {
                for(int q = j; q <= n; q++) {
                    dp[i][j][p][q] = dp[i][j][p - 1][q] + dp[i][j][p][q - 1] - dp[i][j][p - 1][q - 1] + a[p][q];
                    res = max(res, dp[i][j][p][q]);
                }
            }
        }
    }

    cout << res << "\n";


}