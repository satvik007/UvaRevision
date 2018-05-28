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
typedef pair <ll, ll> ii;

const int INF = 1 << 30;

string a;

ii solve(ll u, ll d, ll f, ll s, ll l, ll r, int ind) {
    if(ind == a.size()) {
        return {f, s};
    } else {
        if(a[ind] == 'L')
            return solve(u, d, u + f, d + s, f, s, ind + 1);
        else
            return solve(f, s, f + l, s + r, l, r, ind + 1);
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
        cin >> a;

        ii ans = solve(0, 1, 1, 1, 1, 0, 0);

        cout << ans.first << "/" << ans.second << "\n";
    }

}