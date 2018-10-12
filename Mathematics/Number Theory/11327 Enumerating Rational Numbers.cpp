// lose small or win big.
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

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    function <int(int)> phi = [&](int n) {
        int res = n;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                while(n % i == 0) {
                    n /= i;
                }
                res -= res / i;
            }
        }
        if(n != 1)
            res -= res / n;
        return res;
    };

    const int mm = 200010;
    vi a(mm);

    for(int i = 1; i < mm; i++) {
        a[i] = phi(i);
    }

    vector <ll> b(mm);
    b[1] = 2;
    for(int i = 2; i < mm; i++) {
        b[i] = b[i - 1] + a[i];
    }

    ll n;

    while(cin >> n, n) {
        if(n <= 2) {
            cout << n - 1 << "/1\n";
            continue;
        }
        auto iter = lower_bound(b.begin(), b.end(), n) - b.begin();
        int v = n - b[iter - 1];
        for(int i = 1; i < iter; i++) {
            if(__gcd(iter, (ll)i) == 1) {
                if(v == 1) {
                    cout << i << "/" << iter << "\n";
                    break;
                }
                v--;
            }
        }
    }



}