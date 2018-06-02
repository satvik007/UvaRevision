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

int coin[] = {1, 5, 10, 25, 50};
ll dp[30010];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int k = 0; k < 5; k++) {
        for(int i = 1; i <= 30000; i++) {
            if(i >= coin[k])
                dp[i] += dp[i - coin[k]];
        }
    }

    int n;
    while(cin >> n) {
        if(dp[n] == 1) {
            cout << "There is only 1 way to produce "<< n << " cents change.\n";
        } else {
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
        }
    }

}