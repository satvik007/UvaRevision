#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    for(int cas=1; cas<=tc; cas++){
        cout << "Case " << cas << ": ";
        cin >> n;
        int u, v = -1;
        for(int i=0; i<n; i++){
            cin >> u; v = max(u, v);
        }
        cout << v << "\n";
    }
    return 0;
}
