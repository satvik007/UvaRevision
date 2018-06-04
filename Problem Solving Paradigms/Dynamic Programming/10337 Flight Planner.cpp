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

int a[1010][11];
int dp[1010][11];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        n /= 100;
        for(int i = 9; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                cin >> a[j][i];
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 10; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 30 - a[i][j]);
                if(j) dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + 20 - a[i][j]);
                if(j < 9) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]  + 60 - a[i][j]);
            }
        }
        cout << dp[n][0] << "\n\n";
    }

}