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
vector <string> a;
map <int, string> segment;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    segment[0] = "1111110";
    segment[1] = "0110000";
    segment[2] = "1101101";
    segment[3] = "1111001";
    segment[4] = "0110011";
    segment[5] = "1011011";
    segment[6] = "1011111";
    segment[7] = "1110000";
    segment[8] = "1111111";
    segment[9] = "1111011";

    while(cin >> n, n) {
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < a[i].size(); j++) {
                if(a[i][j] == 'Y') a[i][j] = '1';
                else a[i][j] = '0';
            }
        }
        bool flag1 = false;

        bool fused[12];

        for(int i = 9; i >= n - 1; i--) {
            bool flag2 = true;
            memset(fused, 0, sizeof fused);
            for(int j = 0; j < n && flag2; j++) {
                string s = segment[i - j];
                for(int k = 0; k < s.size(); k++) {
                    if(fused[k] == 1 && a[j][k] == '1') flag2 = false;
                    if(s[k] == '1' && a[j][k] == '0') fused[k] = 1;
                    if(s[k] == '0' && a[j][k] == '1') flag2 = false;
                }
            }
            if(flag2) {
                flag1 = true;
                break;
            }
        }

        if(flag1) {
            cout << "MATCH\n";
        } else {
            cout << "MISMATCH\n";
        }


    }

}