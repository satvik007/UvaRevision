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
int a[10][10];
int ans;

void solve(int u, int mask, int cur) {
    if(mask == (1 << n) - 1) {
        ans = min(ans, cur);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i))) {
            solve(u + 1, mask | (1 << i), cur + a[u][i]);
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
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        ans = INF;

        solve(0, 0, 0);

        cout << ans << "\n";

    }


}