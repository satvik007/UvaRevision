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

int n;
int a[2010];
int dp1[2010];
int dp2[2010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
                else dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = max(dp1[i] + dp2[i] + 1, ans);
        }

        cout << ans << "\n";
    }

}