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

char a[5][6];
char b[5][6];
vector <string> ans;

void solve(int u, string cur) {
    if(u == 5) {
        ans.push_back(cur);
        return;
    }
    for(int i = 0; i < 6; i++) {
        if(find(a[u] + i + 1, a[u] + 6, a[u][i]) == a[u] + 6 && find(b[u], b[u] + 6, a[u][i]) != b[u] + 6){
            solve(u + 1, cur + a[u][i]);
        }
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> a[j][i];
            }
        }
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> b[j][i];
            }
        }

        for(int i = 0; i < 5; i++) {
            sort(a[i], a[i] + 6);
            sort(b[i], b[i] + 6);
        }

        ans.clear();
        string cur;
        solve(0, cur);
        //sort(ans.begin(), ans.end());
        //ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
//        for(auto el: ans) {
//            cout << el << "\n";
//        }

        //cout << "\n\n";

        if(n <= ans.size())
            cout << ans[n - 1] << "\n";
        else
            cout << "NO\n";
    }

}