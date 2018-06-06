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
vector <vector<ii> > a;
int dist[1010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;
        a.clear();
        a.resize(n);

        for(int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            a[u].push_back({v, c});
        }

        memset(dist, 0, sizeof dist);

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n; j++) {
                for(auto v: a[j]) {
                    dist[v.first] = min(dist[v.first], dist[j] + v.second);
                }
            }
        }

        bool flag = false;
        for(int j = 0; j < n; j++)
            for(auto v: a[j])
                if(dist[v.first] > dist[j] + v.second)
                    flag = true;

        if(flag) cout << "possible\n";
        else cout << "not possible\n";


    }


}