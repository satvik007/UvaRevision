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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n;
    while(cin >> n) {
        vector <string> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector <ii> first;
        vector <ii> second;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == '1') first.push_back({i, j});
                else if(a[i][j] == '3') second.push_back({i, j});
            }
        }

        int ans = 0;

        for(auto u: first) {
            int cur = INF;
            for(auto v: second) {
                cur = min(cur, abs(u.first - v.first) + abs(u.second - v.second));
            }
            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }


}