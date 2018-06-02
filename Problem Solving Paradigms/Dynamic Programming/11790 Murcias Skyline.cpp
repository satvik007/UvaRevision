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

int n;
int dp1[10000];
int dp2[10000];
int a[10000];
int b[10000];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;
    int cas = 1;

    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            dp1[i] = dp2[i] = b[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[i] > a[j]) {
                    dp1[i] = max(dp1[i], dp1[j] + b[i]);
                }
                if(a[i] < a[j]) {
                    dp2[i] = max(dp2[i], dp2[j] + b[i]);
                }
            }
        }

        int a1 = *max_element(dp1, dp1 + n);
        int a2 = *max_element(dp2, dp2 + n);

        if(a1 >= a2)
            cout << "Case " << cas++ << ". Increasing (" << a1 << "). Decreasing (" << a2 << ").\n";
        else
            cout << "Case " << cas++ << ". Decreasing (" << a2 << "). Increasing (" << a1 << ").\n";
    }

}