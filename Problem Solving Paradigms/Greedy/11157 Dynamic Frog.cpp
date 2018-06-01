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

int n, d;

ii a[110];

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
        cin >> n >> d;
        char type;
        char null;
        int u;
        a[0] = {0, 1};
        for(int i = 1; i <= n; i++) {
            cin >> type >> null >> u;
            if(type == 'B') a[i] = {u, 1};
            else a[i] = {u, 0};
        }
        a[n + 1] = {d, 1};

        int ans = 0;

        for(int i = 0; i <= n; i++) {
            if(a[i + 1].second == 1) {
                ans = max(ans, a[i + 1].first - a[i].first);
            } else if(a[i + 2].second == 1){
                ans = max(ans, a[i + 2].first - a[i].first);
                i++;
            } else {
                ans = max(ans, a[i + 2].first - a[i].first);
                a[i + 2].second = 3;
                i++;
            }
        }

        for(int i = n + 1; i > 0; i--) {
            if(a[i - 1].second == 1 || a[i - 1].second == 0) {
                ans = max(ans, a[i].first - a[i - 1].first);
            } else if(a[i - 2].second == 1 || a[i - 2].second == 0){
                ans = max(ans, a[i].first - a[i - 2].first);
                i--;
            }
        }

        cout << ans << "\n";


    }

}