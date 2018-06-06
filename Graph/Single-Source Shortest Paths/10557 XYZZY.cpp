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
vi dist;
vector <vi> a;
vi b;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n, n != -1) {
        a.clear();
        a.resize(n);
        b.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            int u, v;
            cin >> u;
            while(u--) {
                cin >> v;
                a[i].push_back(v - 1);
            }
        }

        dist.assign(n, -1);
        dist[0] = 100;

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n; j++) {
                for(auto v: a[j]) {
                    if(dist[j] > 0 && dist[v] < dist[j] + b[v]) {
                        dist[v] = dist[j] + b[v];
                    }
                }
            }
        }

        for(int i = 0; i < 2 * n; i++) {
            for(int j = 0; j < n; j++) {
                for(auto v: a[j]) {
                    if(dist[j] > 0 && dist[v] < dist[j] + b[v]) {
                        dist[j] = 1000000;
                        dist[v] = dist[j] + b[v];
                    }
                }
            }
        }

        if(dist[n - 1] > 0) cout << "winnable\n";
        else cout << "hopeless\n";

        flush(cout);

    }


}