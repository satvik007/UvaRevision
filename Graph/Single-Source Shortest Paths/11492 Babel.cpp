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

struct Data {
    int v;
    char first;
    int dist;
};

map <string, int> map1;
int n;
vector <vector<Data> > a;
map <pair<int, char>, int> dist;


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n, n) {
        string f, s;
        cin >> f >> s;
        map1.clear();
        map1[f] = 0;
        map1[s] = 1;

        int k = 2;

        a.clear();
        a.resize(2 * n + 2);

        for(int i = 0; i < n; i++) {
            string u, v, w;
            cin >> u >> v >> w;
            if(!map1.count(u)) map1[u] = k++;
            if(!map1.count(v)) map1[v] = k++;
            a[map1[u]].push_back({map1[v], w[0], (int)w.size()});
            a[map1[v]].push_back({map1[u], w[0], (int)w.size()});
        }

        auto comp = [&](Data x, Data y) {
            if(x.dist == y.dist) return x.first > y.first;
            return x.dist > y.dist;
        };

        function<int()> dijkstra = [&]() {
            priority_queue <Data, vector <Data>, decltype(comp)> pq(comp);
            dist.clear();
            for(int i = 0; i < a[0].size(); i++) {
                Data cur = a[0][i];
                dist[{cur.v, cur.first}] = cur.dist;
                pq.push(cur);
            }

            Data cur, temp;
            while(!pq.empty()) {
                cur = pq.top(); pq.pop();
                if(dist[{cur.v, cur.first}] < cur.dist) continue;
                if(cur.v == 1) {
                    return cur.dist;
                }
                for(auto el: a[cur.v]) {
                    if((!dist.count({el.v, el.first}) || dist[{el.v, el.first}] > cur.dist + el.dist) && cur.first != el.first) {
                        dist[{el.v, el.first}] = cur.dist + el.dist;
                        temp = el;
                        temp.dist = cur.dist + el.dist;
                        pq.push(temp);
                    }
                }
            }

            return -1;
        };

        int ans = dijkstra();
        if(ans == -1) cout << "impossivel\n";
        else cout << ans << "\n";


    }

}