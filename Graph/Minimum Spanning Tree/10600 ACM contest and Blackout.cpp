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
vector <pair<int, ii> > a;
int used[11000];
int can[11000];
bool flag;

class UnionFind {
public:
    vi rank, p;
    UnionFind() {
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

int kruskal() {
    UnionFind cur;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if(can[i]) {
            if(!cur.isSameSet(a[i].second.first, a[i].second.second)) {
                if(flag) used[i] = 1;
                cur.unionSet(a[i].second.first, a[i].second.second);
                ans += a[i].first;
                cnt++;
            }
        }
    }
    if(cnt == n - 1) return ans;
    else return INF;
}


int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(2);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;
        a.clear();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            a.push_back({w, {u, v}});
        }
        memset(used, 0, sizeof used);
        memset(can, 1, sizeof can);
        sort(a.begin(), a.end());
        flag = true;
        int ans1 = kruskal();
        flag = false;

        int ans2 = INF;

        for(int i = 0; i < a.size(); i++) {
            if(used[i]) {
                can[i] = 0;
                ans2 = min(ans2, kruskal());
                can[i] = 1;
            }
        }

        cout << ans1 << " " << ans2 << "\n";

    }

}