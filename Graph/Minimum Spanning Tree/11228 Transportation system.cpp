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

int n, r;
int xx[1010];
int yy[1010];
double dist[1010][1010];

vector <pair<double, pair<int, int > > > a, b;

class UnionFind {
public:
    vi p, rank;
    int cnt;
    UnionFind() {
        rank.assign(n, 1);
        p.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
        cnt = n;
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
            cnt--;
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(0);

    int tc;
    cin >> tc;

    int cas = 1;

    while(tc--) {
        cin >> n >> r;
        for(int i = 0; i < n; i++) cin >> xx[i] >> yy[i];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = sqrt(p(xx[i] - xx[j]) + p(yy[i] - yy[j]));
            }
        }
        a.clear();
        b.clear();
        a.resize(n);
        b.resize(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(dist[i][j] <= r) a.push_back({dist[i][j], {i, j}});
                else b.push_back({dist[i][j], {i, j}});
            }
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        UnionFind cur;

        double a1 = 0;

        for(auto el: a) {
            if(!cur.isSameSet(el.second.first, el.second.second)) {
                cur.unionSet(el.second.first, el.second.second);
                a1 += el.first;
            }
        }

        int num = cur.cnt;

        double a2 = 0;

        for(auto el: b) {
            if(!cur.isSameSet(el.second.first, el.second.second)) {
                cur.unionSet(el.second.first, el.second.second);
                a2 += el.first;
            }
        }


        cout << "Case #" << cas++ << ": ";

        cout << num << " " << a1 << " " << a2 << "\n";
    }

}