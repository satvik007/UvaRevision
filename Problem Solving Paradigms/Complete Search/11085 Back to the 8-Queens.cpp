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

vector <vi> ans;

void solve(int u, vi cur) {
    if(u == 8) {
        bool flag = true;
        for(int i = 0; i < 8 && flag; i++) {
            for(int j = i + 1; j < 8 && flag; j++) {
                if(i - cur[i] == j - cur[j] || i + cur[i] == j + cur[j]) flag = false;
            }
        }
        if(flag)
            ans.push_back(cur);
    } else {
        for(int i = 0; i < 8; i++) {
            if(find(cur.begin(), cur.end(), i) == cur.end()) {
                cur.push_back(i);
                solve(u + 1, cur);
                cur.pop_back();
            }
        }
    }
};

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);




    vi b;
    solve(0, b);

    string a;

    b.resize(8);

    int cas = 1;

    while(getline(cin, a)) {
        stringstream sin(a);
        for(int i = 0; i < 8; i++) {
            sin >> b[i]; b[i]--;
        }
        int val = 100;
        for(auto el: ans) {
            int cur = 0;
            for(int i = 0; i < 8; i++) {
                if(b[i] != el[i]) cur++;
            }
            val = min(val, cur);
        }
        cout << "Case " << cas++ << ": " << val << "\n";
    }


}