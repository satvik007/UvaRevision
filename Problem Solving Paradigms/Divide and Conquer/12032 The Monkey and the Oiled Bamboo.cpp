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
int a[maxn];

bool solve(int mid) {
    if(a[0] == mid) mid--;
    else if(a[0] > mid) return false;

    for(int i = 0; i < n - 1; i++) {
        if(a[i + 1] - a[i] == mid) mid--;
        else if(a[i + 1] - a[i] > mid) return false;
    }
}


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;
    int cas = 1;

    while(tc--) {
        cout << "Case " << cas++ << ": ";

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int lo = 1;
        int mid;
        int hi = a[n - 1];
        int ans = hi;

        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(solve(mid)) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";

    }

}