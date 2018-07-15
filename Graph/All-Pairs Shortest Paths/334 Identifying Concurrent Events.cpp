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

const int INF = (int)1e9;

#define maxn 100010

int a[205][205];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    int n, m;
    map <string, int> map1;
    vector <string> names;
    int cas = 1;
    while(cin >> n, n) {
        map1.clear();
        names.clear();
        int q = 0;
        for(int i = 0; i <= 200; i++) {
            for(int j = 0; j <= 200; j++) {
                a[i][j] = INF;
            }
        }
        for(int i = 0; i < n; i++) {
            int u; cin >> u;
            for(int j = 0; j < u; j++) {
                string v;
                cin >> v;
                if(j) a[q - 1][q] = 1;
                map1[v] = q++;
                names.push_back(v);
            }
        }
        cin >> m;

        for(int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;
            a[map1[u]][map1[v]] = 1;
        }

        for(int k = 0; k < q; k++) {
            for(int i = 0; i < q; i++) {
                for(int j = 0; j < q; j++) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }

        queue <int> s;
        for(int i = 0; i < q; i++) {
            for(int j = i + 1; j < q; j++) {
                if(a[i][j] == INF and a[j][i] == INF) {
                    s.push(i);
                    s.push(j);
                }
            }
        }

        cout << "Case " << cas++ << ", ";
        if(s.empty()) {
            cout << "no concurrent events.\n";
        } else {
            cout << (s.size() / 2) << " concurrent events:\n";
            int j = s.size() / 2;
            j = min(j, 2);
            while(j--) {
                cout << "(" << names[s.front()] << ","; s.pop();
                cout << names[s.front()] << ") "; s.pop();
            }
            cout << "\n";
        }

    }

}