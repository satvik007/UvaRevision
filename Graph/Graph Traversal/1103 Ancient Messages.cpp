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

int n, m;
map <char, string> map1;
vector <string> a;
vector <vi> b;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void ff1(int r, int c, int c1, int c2) {
    if(r >= 0 && c >= 0 && r < n && c < m && b[r][c] == c1) {
        b[r][c] = c2;
        for(int k = 0; k < 4; k++) {
            ff1(r + dr[k], c + dc[k], c1, c2);
        }
    }
}

int ff2(int r, int c) {
    if(r >= 0 && c >= 0 && r < n && c < m && b[r][c] != 2) {
        int ans = 0;
        if(b[r][c] == 1) {
            b[r][c] = 2;
            for(int i = 0; i < 4; i++) {
                ans += ff2(r + dr[i], c + dc[i]);
            }
        } else {
            ans++;
            ff1(r, c, 0, 2);
        }
        return ans;
    }
    return 0;
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    map1['0'] = "0000";
    map1['1'] = "0001";
    map1['2'] = "0010";
    map1['3'] = "0011";
    map1['4'] = "0100";
    map1['5'] = "0101";
    map1['6'] = "0110";
    map1['7'] = "0111";
    map1['8'] = "1000";
    map1['9'] = "1001";
    map1['a'] = "1010";
    map1['b'] = "1011";
    map1['c'] = "1100";
    map1['d'] = "1101";
    map1['e'] = "1110";
    map1['f'] = "1111";

    int cas = 1;

    while(cin >> n >> m, n || m) {
        a.resize(n);
        b.resize(n);
        string s;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i].resize(4 * m);
            for(int j = 0; j < m; j++) {
                s = map1[a[i][j]];
                for(int k = 0; k < 4; k++) {
                    b[i][4 * j + k] = s[k] - '0';
                }
            }
        }
        m *= 4;

        for(int i = 0; i < n; i++) {
            if(b[i][0] == 0) ff1(i, 0, 0, 2);
            if(b[i][m - 1] == 0) ff1(i, m - 1, 0, 2);
        }

        for(int i = 0; i < m; i++) {
            if(b[0][i] == 0) ff1(0, i, 0, 2);
            if(b[n - 1][i] == 0) ff1(n - 1, i, 0, 2);
        }

//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++) {
//                cout << b[i][j];
//            }
//            cout << "\n";
//        }

        string an;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(b[i][j] == 1) {
                    int ans = ff2(i, j);
                    if(ans == 0) an += 'W';
                    else if(ans == 1) an += 'A';
                    else if(ans == 2) an += 'K';
                    else if(ans == 3) an += 'J';
                    else if(ans == 4) an += 'S';
                    else if(ans == 5) an += 'D';
                }
            }
        }

        sort(an.begin(), an.end());

        cout << "Case " << cas++ << ": " << an << "\n";

    }

}