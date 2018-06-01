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

int n, m, k;
int a[110][110];
ll dp[110][110];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;
    int cas = 1;

    while(tc--) {
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        int area = 0;
        ll max1 = 0;

        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int p = i; p <= n; p++) {
                    for(int q = j; q <= m; q++) {
                        ll cur = dp[p][q] - dp[i - 1][q] - dp[p][j - 1] + dp[i - 1][j - 1];
                        if(cur <= k) {
                            int ar = (p - i + 1) * (q - j + 1);
                            if(ar > area) area = ar, max1 = cur;
                            else if(ar == area) max1 = min(max1, cur);
                        }
                    }
                }
            }
        }

        cout << "Case #" << cas++ << ": " << area << " " << max1 << "\n";


    }


}