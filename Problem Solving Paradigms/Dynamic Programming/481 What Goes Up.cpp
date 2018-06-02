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



int main() {
#ifdef BZ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(20);

    vi a;
    int u;

    while (cin >> u) {
        a.push_back(u);
    }

    int n = (int) a.size();

    auto comp = [&] (int x, int y) {return a[x] < a[y];};
    set <int, decltype(comp)> s(comp);

    vi previous(a.size(), -1);

    for(int i = 0; i < n; i++) {
        auto it = s.insert(i).first;
        if(it != s.begin()) previous[i] = *prev(it);
        if(*it == i && next(it) != s.end())
            s.erase(next(it));
    }

    vi ans;
    ans.push_back(*s.rbegin());

    while(previous[ans.back()] != -1) {
        ans.push_back(previous[ans.back()]);
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n-\n";
    for(auto el: ans) cout << a[el] << "\n";

}