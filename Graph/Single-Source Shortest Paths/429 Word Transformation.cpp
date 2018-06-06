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

set <string> set1;

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;

    function <int(string, string)> bfs = [&] (string u, string v) {
        queue <string> q; q.push(u);
        map <string, int> map1;
        map1[u] = 0;
        string orig;
        while(!q.empty()) {
            string cur = q.front(); q.pop();
            orig = cur;
            if(cur == v) return map1[v];
            for(int i = 0; i < cur.size(); i++) {
                char val = cur[i];
                for(int j = 0; j < 26; j++) {
                    if(val != 'a' + j) {
                        cur[i] = (char)('a' + j);

                        if(set1.count(cur) && !map1.count(cur)) {
                            map1[cur] = map1[orig] + 1;
                            q.push(cur);
                            if(cur == v) return map1[v];
                        }
                    }
                }
                cur[i] = val;
            }
        }


        return 0;
    };

    int cas = 1;
    while(cin.peek() != EOF) {
        if(cas != 1) cout << "\n"; cas++;
        set1.clear();
        string s;
        while(true) {
            string s;
            cin >> s;
            if(s == "*") break;
            set1.insert(s);
        }

        cin.ignore();
        while(cin.peek() != EOF && cin.peek() != '\n') {
            getline(cin, s);
            stringstream sin(s);
            string u, v;
            sin >> u >> v;
            int ans = bfs(u, v);
            cout << u << " " << v << " " << ans << "\n";
        }
    }


}