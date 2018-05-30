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

int a[30];
int n;



int solve(const vi& cur) {
    int res = 0;
    int cnt[5];
    for(int i = 0; i < 25; i++) {
        if(a[i]) {
            for(int j = 0; j < 5; j++) {
                cnt[j] = abs(cur[j] / 5 - i / 5) + abs(cur[j] % 5 - i % 5);
            }
            res += *min_element(cnt, cnt + 5) * a[i];
        }
    }
    return res;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        memset(a, 0, sizeof a);
        int u, v, w;
        for(int i = 0; i < n; i++) {
            cin >> u >> v >> w;
            a[u * 5 + v] += w;
        }

        vi cur(5);
        int max1 = INF;
        vi ans;

        for(int i = 0; i < 21; i++) {
            cur[0] = i;
            for(int j = i + 1; j < 22; j++) {
                cur[1] = j;
                for(int k = j + 1; k < 23; k++) {
                    cur[2] = k;
                    for(int l = k + 1; l < 24; l++) {
                        cur[3] = l;
                        for(int m = l + 1; m < 25; m++) {
                            cur[4] = m;
                            int value = solve(cur);
                            if(value < max1) {
                                max1 = value;
                                ans = cur;
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < 5; i++) {
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";

    }



}