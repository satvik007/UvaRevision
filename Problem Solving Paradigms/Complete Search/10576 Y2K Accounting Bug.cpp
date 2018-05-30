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

int s, d;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int r;

    while (cin >> s >> d) {
        if (d > 4*s) {
            r = 10*s - 2*d;
        } else if (2*d > 3*s) {
            r = 8*s - 4*d;
        } else if (3*d > 2*s) {
            r = 6*s - 6*d;
        } else if (4*d > s) {
            r = 3*s - 9*d;
        } else {
            r = -12 * d;
        }
        if (r >= 0) {
            cout << r << "\n";
        } else {
            cout << "Deficit\n";
        }
    }

}