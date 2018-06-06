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

int n, m, k;
int a[20];
int dist[10010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int cas = 1;

    while(cin >> n >> m >> k, n || m || k) {
        memset(dist, -1, sizeof dist);
        for(int i = 0; i < k; i++) {
            cin >> a[i];
        }

        bool flag = false;
        int ans;

        queue <int> q; q.push(n);
        dist[n] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(cur == m) {
                ans = dist[m];
                flag = true;
                break;
            }
            for(int i = 0; i < k; i++) {
                if(dist[(cur + a[i]) % 10000] == -1) {
                    dist[(cur + a[i]) % 10000] = dist[cur] + 1;
                    q.push((cur + a[i]) % 10000);
                }
            }
        }

        cout << "Case " << cas++ << ": ";
        if(flag) cout << ans << "\n";
        else cout << "Permanently Locked\n";


    }

}