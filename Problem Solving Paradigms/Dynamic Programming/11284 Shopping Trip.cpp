#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define inf (int) 1e9

int n, m;
int dist[60][60];
int shop[14];
int price[14];
int dp[14][1 << 14];

int tsp(int u, int mask) {
    if(dp[u][mask] != -inf) return dp[u][mask];
    int ans = - dist[shop[u]][0];
    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i))) {
            ans = max(ans, price[i] - dist[shop[u]][shop[i]] + tsp(i, mask | (1 << i)));
        }
    }
    return dp[u][mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cout << fixed << setprecision(2);
    int tc;
    cin >> tc;

    while(tc--) {
        cin >> n >> m;
        int u, v, a, b;

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dist[i][j] = inf;
            }
            dist[i][i] = 0;
        }

        for(int i = 0; i < m; i++) {
            char null;
            cin >> u >> v >> a >> null >> b;
            dist[u][v] = dist[v][u] = min(dist[u][v], a * 100 + b);
        }

        for(int k = 0; k <= n; k++) {
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = 0;

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> shop[i];
            char null;
            cin >> a >> null >> b;
            price[i] = a * 100 + b;
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= (1 << n); j++) {
                dp[i][j] = -inf;
            }
        }

        for(int i = 0; i < n; i++) {
            ans = max(ans, price[i] - dist[0][shop[i]] + tsp(i, (1 << i)));
        }

        if(ans == 0) cout << "Don't leave the house\n";
        else cout << "Daniel can save $" << (ans/100.0) << "\n";

    }



    return 0;
}