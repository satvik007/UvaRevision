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

double a[22][22][22];
int path[22][22][22];
int n;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> n) {
        memset(a, 0, sizeof a);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    path[0][i][j] = 1;
                    a[0][i][j] = 1;
                } else {
                    path[0][i][j] = i;
                    cin >> a[0][i][j];
                }
            }
        }

        for(int l = 1; l < n; l++) {
            for(int k = 0; k < n; k++) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        double x = a[l - 1][i][k] * a[0][k][j];
                        if(a[l][i][j] < x) {
                            a[l][i][j] = x;
                            path[l][i][j] = k;
                        }
                    }
                }
            }
        }

        int temp;
        bool flag = false;
        stack <int> s;

        for(int l = 1; l < n && !flag; l++) {
            for(int i = 0; i < n; i++) {
                if(a[l][i][i] > 1.01) {
                    s.push(path[l][i][i]);
                    for(int j = l - 1; j >= 0; j--) {
                        s.push(path[j][i][s.top()]);
                    }
                    temp = s.top();
                    while(!s.empty()) {
                        cout << (s.top() + 1) << " "; s.pop();
                    }
                    cout << (temp + 1) << "\n";
                    flag = true;
                    break;
                }
            }
        }

        if(!flag) cout << "no arbitrage sequence exists\n";

    }

}