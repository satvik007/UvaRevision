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

int k, n;
int a[15];
vector <vi> ans;

void solve(int u, int sum, vi cur) {
    if(sum == k) {
        ans.push_back(cur);
        return;
    }
    if(u == n || sum > k) return;
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

    while(cin >> k >> n, n) {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, greater<int> ());
        ans.clear();
        cout << "Sums of " << k << ":\n";

        vi cur;
        solve(0, 0, cur);

        if(ans.empty()) {
            cout << "NONE\n";
            continue;
        }

        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        reverse(ans.begin(), ans.end());


        for(auto el: ans) {
            for(int i = 0; i < el.size(); i++) {
                if(i) cout << "+";
                cout << el[i];
            }
            cout << "\n";
        }

    }

}