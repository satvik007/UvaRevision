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

int n, m;
int a[10010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n) {
        for(int i = 0; i < n; i++) cin >> a[i];
        cin >> m;
        sort(a, a + n);
        int f, s;
        for(int i = 0; i < n; i++) {
            if(binary_search(a + i + 1, a + n, m - a[i])) {
                f = a[i];
                s = m - a[i];
            }
        }

        cout << "Peter should buy books whose prices are " << f << " and " << s << ".\n\n";
    }

}