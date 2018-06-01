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

#define maxn 10010

int n;
int a[maxn];


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;
    while(cin >> n, n) {
        if(cas != 1) cout << "\n"; cas++;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int k = 0;
        int cnt = 0;
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] == last) {
                cnt++;
            } else {
                last = a[i];
                cnt = 1;
            }
            k = max(k, cnt);
        }
        cout << k << "\n";
        for(int i = 0; i < k; i++) {
            for(int j = i; j < n; j += k) {
                if(i != j) cout << " ";
                cout << a[j];
            }
            cout << "\n";
        }
    }


}