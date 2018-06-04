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
map <char, int> map1;
int a[30];
char lis[30];
vector <string> ans;
int n;

void solve(int mask, string cur) {
    if(mask == (1 << n) - 1) {
        ans.push_back(cur);
    }
    for(int i = 0; i < n; i++) {
        if(!(mask & (1 << i)) && (mask & a[i]) == a[i]) {
            solve(mask | (1 << i), cur + lis[i]);
        }
    }
}

int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int tc;
    cin >> tc;
    cin.ignore();
    string s, b;

    while(tc--) {
        getline(cin, s);
        getline(cin, s);
        getline(cin, b);

        n = 0;
        for(int i = 0; i < s.size(); i += 2) {
            lis[n++] = s[i];
        }

        sort(lis, lis + n);

        for(int i = 0; i < n; i++) {
            map1[lis[i]] = i;
        }



        memset(a, 0, sizeof a);

        for(int i = 0; i < b.size(); i += 4) {
            a[map1[b[i + 2]]] |= (1 << map1[b[i]]);
            //a[map1[b[i]]] |= (1 << map1[b[i + 2]]);
        }

        ans.clear();

        string cur;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                solve((1 << i), cur + lis[i]);
            }
        }

        //sort(ans.begin(), ans.end());
        //ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

        if(ans.size()) {
            for(auto el: ans) {
                for(int i = 0; i < el.size(); i++) {
                    if(i) cout << " ";
                    cout << el[i];
                }
                cout << "\n";
            }
        } else {
            cout << "NO\n";
        }


        if(tc) cout << "\n";
    }


}