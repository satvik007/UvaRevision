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
vector <vi> a;
vi dist;
vi cnt;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n) {
        a.clear();
        a.resize(n);

        for(int i = 0; i < n; i++) {
            int u, v;
            cin >> u;
            for(int j = 0; j < u; j++) {
                cin >> v;
                a[i].push_back(v);
            }
        }

        function<ii(int)> bfs = [&] (int u) -> ii {
            queue <int> q; q.push(u);
            dist.assign(n, -1);
            int a1 = -1, a2 = -1;
            dist[u] = 0;

            while(!q.empty()) {
                int c = q.front(); q.pop();
                for(auto el: a[c]) {
                    if(dist[el] == -1) {
                        dist[el] = dist[c] + 1;
                        q.push(el);
                    }
                }
            }

            cnt.assign(n, 0);

            for(int i = 0; i < n; i++) {
                if(dist[i] != -1) cnt[dist[i]]++;
            }

            int ind = max_element(cnt.begin() + 1, cnt.end()) - cnt.begin();

            return ii(ind, cnt[ind]);
        };

        int tc;
        cin >> tc;

        while(tc--) {
            int u;
            cin >> u;
            ii ans = bfs(u);
            if(ans.second == 0) cout << "0\n";
            else cout << ans.second << " " << ans.first << "\n";
        }
    }

}