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
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        int a, b, c;
        cin >> a >> b >> c;

        vi cur(3);

        vector <vi> ans;

        for(int i = 0; 3 * i * i <= c; i++) {
            for(int j = 0; i * i + 2 * j * j <= c; j++) {
                for(int k = 0; i * i + j * j + k * k <= c; k++) {
                    if(i * j * k == b && i * i + j * j + k * k == c) {
                        if(i + j + k == a && i != j && i != k && j != k) {
                            cur[0] = i; cur[1] = j; cur[2] = k;
                            sort(cur.begin(), cur.end());
                            ans.push_back(cur);
                        }
                        if(k - i - j == a && i != j && i != -k && j != -k) {
                            cur[0] = - i; cur[1] = - j; cur[2] = k;
                            sort(cur.begin(), cur.end());
                            ans.push_back(cur);
                        }
                        if(- k + i - j == a && i != -j && i != -k && j != k) {
                            cur[0] = i; cur[1] = -j; cur[2] = -k;
                            sort(cur.begin(), cur.end());
                            ans.push_back(cur);
                        }
                        if(- k - i + j == a && i != -j && i != k && j != -k) {
                            cur[0] = -i; cur[1] = j; cur[2] = -k;
                            sort(cur.begin(), cur.end());
                            ans.push_back(cur);
                        }
                    }
                }
            }
        }
        if(ans.empty()) cout << "No solution.\n";
        else {
            cur = *min_element(ans.begin(), ans.end());
            cout << cur[0] << " " << cur[1] << " " << cur[2] << "\n";
        }

    }

}