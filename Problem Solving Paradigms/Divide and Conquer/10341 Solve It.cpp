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

// p ∗ e −x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x 2 + u = 0

int p, q, r, s, t, u;

double f(double x) {
    return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(4);

    while(cin >> p >> q >> r >> s >> t >> u) {
        double lo = 0;
        double hi = 1;
        double mid;
        while(hi - lo > 1e-7) {
            mid = (lo + hi) / 2;
            if(f(mid) < 0) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        if(abs(f(lo)) < 1e-5)
            cout << lo << "\n";
        else
            cout << "No solution\n";
    }

}