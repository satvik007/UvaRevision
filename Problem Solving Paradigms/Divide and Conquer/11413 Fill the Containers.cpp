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

#define maxn 1010

int n, m;
int a[maxn];

bool solve(int mid) {
    int cnt = 1;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(cur + a[i] <= mid) {
            cur += a[i];
        } else {
            cur = a[i];
            cnt++;
        }
    }
    return cnt <= m;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> m) {
        int lo = 0;
        int hi = 0;
        int mid;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            hi += a[i];
            lo = max(lo, a[i]);
        }
        int ans = hi;
        while(lo <= hi) {
            mid = (lo + hi) / 2;
            if(solve(mid)) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }

        cout << ans << "\n";

    }

}