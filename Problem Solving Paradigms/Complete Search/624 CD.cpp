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

int a[22];
int k, n;
vi ans;
int val;

void solve(int u, int sum, vi cur) {
    if(sum > k) return;
    if(k - sum < val) {
        val = k - sum;
        ans = cur;
    }
    if(u >= n) return;
    cur.push_back(a[u]);
    solve(u + 1, sum + a[u], cur);
    cur.pop_back();
    solve(u + 1, sum, cur);
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);



    while(cin >> k >> n) {
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vi emp;
        val = INF;
        solve(0, 0, emp);

        int cnt = 0;
        for(auto el: ans) cout << el << " ", cnt += el;
        cout << "sum:" << cnt << "\n";

    }


}