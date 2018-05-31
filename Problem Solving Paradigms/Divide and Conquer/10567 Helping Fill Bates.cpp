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

#define maxn 1000010

int a[maxn][60];

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    string s;
    cin >> s;

    memset(a, -1, sizeof a);

    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = 0; j < 55; j++) {
            a[i][j] = a[i + 1][j];
        }
        if(s[i] >= 'a')
            a[i][s[i] - 'a'] = i + 1;
        else
            a[i][s[i] - 'A' + 26] = i + 1;
    }

    int q;
    cin >> q;

    while(q--) {
        cin >> s;
        bool flag = true;
        int v = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a')
                v = a[v][s[i] - 'a'];
            else
                v = a[v][s[i] - 'A' + 26];
            if(v == -1) {
                flag = false;
                break;
            }
        }
        int f = (s[0] >= 'a') ? a[0][s[0] -'a'] : a[0][s[0] - 'A' + 26];
        if(flag) {
            cout << "Matched " << f - 1 << " " << v - 1 << "\n";
        } else {
            cout << "Not matched\n";
        }
        flush(cout);
    }



}