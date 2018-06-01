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

#define maxn 20010

int n, m;
int a[maxn];
int b[maxn];


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> m, n || m) {
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int j = 0; j < m; j++) cin >> b[j];
        sort(a, a + n);
        sort(b, b + m);
        int k = 0;
        int cnt = 0;
        bool flag = true;
        for(int i = 0; i < m; i++) {
            if(k == n) break;
            if(b[i] >= a[k]) {
                cnt += b[i];
                k++;
            }
        }

        if(k == n) {
            cout << cnt << "\n";
        } else {
            cout << "Loowater is doomed!\n";
        }

    }

}