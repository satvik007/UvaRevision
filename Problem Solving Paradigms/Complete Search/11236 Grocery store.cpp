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

    cout << fixed << setprecision(2);

    for(int i = 1; i <= 125; i++) {
        for(int j = i; i + 3 * j <= 2000 && i * j * j * j <= 2000000000; j++) {
            for(int k = j; i + j + 2 * k <= 2000 && i * j * k * k <= 2000000000; k++) {
                ll a = i + j + k;
                ll b = (ll)i * j * k;
                if(b > 1000000 && a * 1000000 % (b - 1000000) == 0 && a * b / (b - 1000000) <= 2000 && a * 1000000 / (b - 1000000) >= k) {
                    cout << i / 100.0 << " " << j / 100.0 << " " << k / 100.0 << " " << a * 10000.0 / (b - 1000000) << "\n";
                }
            }
        }
    }


}