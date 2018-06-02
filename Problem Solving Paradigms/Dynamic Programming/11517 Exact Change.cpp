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

int a[110];
int dp[maxn];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        int n, m;

        cin >> m >> n;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < maxn; i++) {
            dp[i] = INF;
        }

        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            for(int j = m; j >= 0; j--) {
                dp[j + a[i]] = min(dp[j + a[i]], dp[j] + 1);
            }
        }

        for(int i = m; ; i++) {
            if(dp[i] < INF) {
                cout << i << " " << dp[i] << "\n";
                break;
            }
        }

    }

}