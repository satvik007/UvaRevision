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

#define p(x) ((x) * (x))
#define maxn 100010

int n;
int x[12];
int y[12];
int pa[12];
double dist[12][12];

void solve(){
    int a[10];
    double min1 = 100000000, temp;
    do{
        double sum = 0;
        for(int i=1; i<n; i++){
            sum += dist[pa[i]][pa[i-1]];
        }
        if(sum < min1) {
            min1 = sum;
            for(int i = 0; i < n; i++)
                a[i] = pa[i];
        }
    }while(next_permutation(pa, pa+n));
    for(int i=1; i<n; i++){
        cout << "Cable requirement to connect (" << x[a[i-1]] << "," << y[a[i-1]]
             << ") to (" << x[a[i]] << "," << y[a[i]] << ") is "
             << dist[a[i]][a[i-1]] << " feet.\n";
    }
    cout << "Number of feet of cable required is " << min1 << ".\n";
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(2);

    int cas = 1;
    while(cin >> n, n) {
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            pa[i] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = sqrt(p(x[i] - x[j]) + p(y[i] - y[j])) + 16;
            }
        }
        cout << "**********************************************************\n";
        cout << "Network #" << cas++ << "\n";
        solve();
    }


}