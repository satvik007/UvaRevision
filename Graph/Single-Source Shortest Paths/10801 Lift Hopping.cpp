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

int n, k;
int b[10];
vi c[6];
vector <vector <ii>> a;
int dist[110];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n >> k) {
        //cout << n << " " << k << "\n";
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++) {
            c[i].clear();
            cin.ignore();
            while(cin.peek() != '\n' && cin.peek() != EOF) {
                int u; cin >> u;
                c[i].push_back(u);
            }
            sort(c[i].begin(), c[i].end());
        }

        a.clear();
        a.resize(101);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < c[i].size() - 1; j++) {
                for(int k = j + 1; k < c[i].size(); k++) {
                    a[c[i][j]].push_back({c[i][k], b[i] * (c[i][k] - c[i][j])});
                    a[c[i][k]].push_back({c[i][j], b[i] * (c[i][k] - c[i][j])});
                }
            }
        }

//        for(int i = 0; i <= 100; i++) {
//            if(a[i].size()) {
//                cout << i << " --- ";
//                for(auto el: a[i]) cout << "(" << el.first << ", " << el.second << ")  "; cout << "\n";
//            }
//        }

        function <int()> dijkstra = [&]() {
            priority_queue <ii, vector <ii>, greater<ii> > pq;
            pq.push({0, 0});
            memset(dist, -1, sizeof dist);
            dist[0] = 0;

            while(!pq.empty()) {
                ii cur = pq.top(); pq.pop();
                if(cur.first > dist[cur.second]) continue;
                if(cur.second == k) {
                    return cur.first;
                }
                if(cur.second != 0) cur.first += 60;
                for(auto el: a[cur.second]) {
                    if(dist[el.first] == -1 || dist[el.first] > cur.first + el.second) {
                        dist[el.first] = cur.first + el.second;
                        pq.push({dist[el.first], el.first});
                    }
                }
            }
            return -1;
        };

        int ans = dijkstra();

        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";

    }


}