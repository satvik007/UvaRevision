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

int a, b, c;
ll arr[22][22][22];
ll dp[22][22][22][22][22][22];


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> a >> b >> c;
        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= b; j++) {
                for(int k = 1; k <= c; k++) {
                    cin >> arr[i][j][k];
                }
            }
        }
        ll res = -(1LL << 60);
        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= b; j++) {
                for(int k = 1; k <= c; k++) {
                    for(int p = i; p <= a; p++) {
                        for(int q = j; q <= b; q++) {
                            for(int r = k; r <= c; r++) {
                                dp[i][j][k][p][q][r] = dp[i][j][k][p][q][r - 1] + dp[i][j][k][p - 1][q][r] + dp[i][j][k][p][q - 1][r];
                                dp[i][j][k][p][q][r] += arr[p][q][r] - dp[i][j][k][p][q - 1][r - 1] - dp[i][j][k][p - 1][q][r - 1] - dp[i][j][k][p - 1][q - 1][r];
                                dp[i][j][k][p][q][r] += dp[i][j][k][p - 1][q - 1][r - 1];
                                res = max(res, dp[i][j][k][p][q][r]);
                            }
                        }
                    }
                }
            }
        }
        cout << res << "\n";
        if(tc) cout << "\n";
    }

}