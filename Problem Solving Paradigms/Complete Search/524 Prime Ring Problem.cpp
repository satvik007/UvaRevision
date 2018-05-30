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

bool is_prime(int n) {
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int m = sqrt(n) + 1;
    for(int i = 3; i <= m; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

int n;
vector <vi> ans;

void solve(int u, int mask, vi cur) {
    if(u == n) {
        if(is_prime(cur.front() + cur.back())) {
            ans.push_back(cur);
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i)) && is_prime(i + 1 + cur.back())) {
            cur.push_back(i + 1);
            solve(u + 1, mask | (1 << i), cur);
            cur.pop_back();
        }
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;
    while(cin >> n) {
        if(cas != 1) cout << "\n";
        cout << "Case " << cas++ << ":\n";
        vi cur(1, 1);

        ans.clear();
        solve(1, 1, cur);

        for(auto el: ans) {
            for(int i = 0; i < n; i++) {
                if(i) cout << " ";
                cout << el[i];
            }
            cout << "\n";
        }

    }
}