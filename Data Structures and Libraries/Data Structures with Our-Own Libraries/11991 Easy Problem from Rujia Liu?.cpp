#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
int a[100010];
map <int, vi> b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vi emp;
    while(cin >> n >> m){
        b.clear();
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            if(!b.count(a[i])) b[a[i]] = emp;
            b[a[i]].push_back(i);
        }
        int u, v;
        while(m--){
            cin >> u >> v;
            if(!b.count(v) || b[v].size() < u) cout << 0 << "\n";
            else cout << b[v][u-1] + 1 << "\n";
        }
    }
    return 0;
}