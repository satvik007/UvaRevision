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
#define p(x) ((x) * (x))
int k, n;
ii a[600];
double dist[510][510];
vector <pair <double, ii> > edges;

class UnionFind {
public:
    vi rank, p;
    UnionFind() {
        rank.assign(n, 0);
        p.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int i) {
        while(i != p[i]) p[i] = p[p[i]], i = p[i];
        return i;
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if(i != j) {
            if(rank[i] < rank[j]) p[i] = j;
            else {
                p[j] = i;
                if(rank[i] == rank[j]) rank[i]++;
            }
        }
    }
};


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(2);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> k >> n;
        for(int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            a[i] = {u, v};
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = sqrt(p(a[i].first - a[j].first) + p(a[i].second - a[j].second));
            }
        }

        edges.clear();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                edges.push_back({dist[i][j], {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        double ans = 0;
        int cnt = n - 1 - k;

        UnionFind cur;

        for(auto el: edges) {
            //cout << el.first << "\n";
            if(cnt < 0) break;
            if(!cur.isSameSet(el.second.first, el.second.second)) {
                cur.unionSet(el.second.first, el.second.second);
                cnt--;
                ans = max(ans, el.first);
            }
        }

        cout << ans << "\n";



    }

}