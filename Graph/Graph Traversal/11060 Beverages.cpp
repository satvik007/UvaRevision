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

map <string, int> map1;
vector <string> names;
int n, m;
vi a[110];
int d[110];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;
    string u, v;
    while(cin >> n) {
        map1.clear();
        names.clear();

        for(int i = 0; i < n; i++) {
            cin >> u;
            names.push_back(u);
            map1[u] = i;
            a[i].clear();
        }

        memset(d, 0, sizeof d);

        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            a[map1[u]].push_back(map1[v]);
            d[map1[v]]++;
        }

        priority_queue <int, vi, greater<int>> pq;

        int cnt = n;

        for(int i = 0; i < n; i++) {
            if(d[i] == 0) pq.push(i);
        }

        vi ans;

        int cur;
        while(!pq.empty()) {
            cur = pq.top(); pq.pop();
            ans.push_back(cur);
            for(auto el: a[cur]) {
                d[el]--;
                if(d[el] == 0) pq.push(el);
            }
        }

        cout << "Case #" << cas++ << ": Dilbert should drink beverages in this order:";

        for(auto el: ans) {
            cout << " " << names[el];
        }

        cout << ".\n\n";


    }

}