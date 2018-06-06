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

int n, m, s, t, p;
vector <vector<ii> > a, b;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m >> s >> t >> p;
        s--; t--;

        a.clear();
        a.resize(n);
        b = a;
        for(int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            u--; v--;
            a[u].push_back({v, c});
            b[v].push_back({u, c});
            //a[v].push_back({u, c});
        }

        vi ds;
        vi dt;

        {
            ds.assign(n, -1);
            priority_queue <ii, vector <ii>, greater<ii> > pq;
            pq.push({0, s});
            ds[s] = 0;
            ii cur;
            while(!pq.empty()) {
                cur = pq.top(); pq.pop();
                if(cur.first > ds[cur.second]) continue;
                for(auto v: a[cur.second]) {
                    if(ds[v.first] == -1 || ds[v.first] > cur.first + v.second) {
                        ds[v.first] = cur.first + v.second;
                        pq.push({ds[v.first], v.first});
                    }
                }
            }
        }

        {
            dt.assign(n, -1);
            priority_queue <ii, vector <ii>, greater<ii> > pq;
            pq.push({0, t});
            dt[t] = 0;
            ii cur;
            while(!pq.empty()) {
                cur = pq.top(); pq.pop();
                if(cur.first > dt[cur.second]) continue;
                for(auto v: b[cur.second]) {
                    if(dt[v.first] == -1 || dt[v.first] > cur.first + v.second) {
                        dt[v.first] = cur.first + v.second;
                        pq.push({dt[v.first], v.first});
                    }
                }
            }
        }

        int ans = -1;

        for(int i = 0; i < n; i++) {
            for(auto v: a[i]) {
                if(ds[i] != -1 && dt[v.first] != -1 && ds[i] + dt[v.first] + v.second <= p) {
                    ans = max(ans, v.second);
                }
            }
        }

        cout << ans << "\n";


    }

}