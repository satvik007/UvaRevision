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

class UnionFind {
public:
    vi p, rank;
    int n;
    UnionFind(int _n) {
        n = _n;
        rank.assign(n, 1);
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n, m;

    vector <pair <int, ii> > a;

    while(cin >> n >> m, n || m) {
        a.clear();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            a.push_back({w, {u, v}});
        }
        sort(a.begin(), a.end());

        UnionFind cur(n);

        vi ans;

        for(auto el: a) {
            if(!cur.isSameSet(el.second.first, el.second.second)) {
                cur.unionSet(el.second.first, el.second.second);
            } else {
                ans.push_back(el.first);
            }
        }

        if(ans.empty()) cout << "forest\n";
        else {
            for(int i = 0; i < ans.size(); i++) {
                if(i) cout << " ";
                cout << ans[i];
            }
            cout << "\n";
        }

    }

}