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

char type;
int n, m;
string s;

int a[210][210];

bool same(int u, int d, int l, int r) {
    int cur = a[u][l];
    for(int i = u; i <= d; i++) {
        for(int j = l; j <= r; j++) {
            if(cur != a[i][j]) return false;
        }
    }
    return true;
}

void fill(int u, int d, int l, int r, int cur) {
    for(int i = u; i <= d; i++) {
        for(int j = l; j <= r; j++) {
            a[i][j] = cur;
        }
    }
}

string btod(int u, int d, int l, int r) {
    string ans;
    if(u > d || l > r) return ans;
    if(same(u, d, l, r)) return ans + (char)(a[u][l] + '0');
    string ans1 = btod(u, (u + d) / 2, l, (l + r) / 2);
    string ans2 = btod(u, (u + d) / 2, (l + r) / 2 + 1, r);
    string ans3 = btod((u + d) / 2 + 1, d, l, (l + r) / 2);
    string ans4 = btod((u + d) / 2 + 1, d, (l + r) / 2 + 1, r);
    if((ans1 == ans2 || ans2.empty()) && (ans1 == ans3 || ans3.empty()) && (ans1 == ans4 || ans4.empty()) && ans1[0] != 'D') return ans1;
    return "D" + ans1 + ans2 + ans3 + ans4;
}

void dtob(int u, int d, int l, int r, int &ind) {
    if(u > d || l > r) return;
    if(s[ind] == 'D') {
        ind++;
        dtob(u, (u + d) / 2, l, (l + r) / 2, ind);
        dtob(u, (u + d) / 2, (l + r) / 2 + 1, r, ind);
        dtob((u + d) / 2 + 1, d, l, (l + r) / 2, ind);
        dtob((u + d) / 2 + 1, d, (l + r) / 2 + 1, r, ind);
    } else {
        fill(u, d, l, r, s[ind] - '0');
        ind++;
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    while(cin >> type, type != '#') {
        cin >> n >> m;

        if(type == 'B') {
            s.clear();
            while(s.size() < n * m) {
                string u; cin >> u;
                s += u;
            }
            cout << "D" << setw(4) << n << setw(4) << m << "\n";
            int k = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    a[i][j] = s[k++] - '0';
                }
            }
            string ans = btod(0, n - 1, 0, m - 1);
            for(int i = 0; i < ans.size(); i++) {
                if(i % 50 == 0 && i) cout << "\n";
                cout << ans[i];
            }
            cout << "\n";
        } else {
            cin >> s;
            cout << "B" << setw(4) << n << setw(4) << m << "\n";
            string ans;
            int val = 0;
            dtob(0, n - 1, 0, m - 1, val);
            int k = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(k % 50 == 0 && k != 0) cout << "\n";
                    cout << a[i][j];
                    k++;

                }
            }
            cout << "\n";
        }

    }

}