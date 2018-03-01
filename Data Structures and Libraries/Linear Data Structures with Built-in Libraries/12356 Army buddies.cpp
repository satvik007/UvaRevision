#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
int lef[100010];
int righ[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n >> m, n||m){
        for(int i=0; i<n; i++){
            if(!i) lef[i] = -1;
            else lef[i] = i-1;
            if(i == n-1) righ[i] = -1;
            else righ[i] = i + 1;
        }
        for(int i=0; i<m; i++){
            cin >> u >> v; u--; v--;
            if(righ[v] != -1) lef[righ[v]] = lef[u];
            if(lef[u] != -1) righ[lef[u]] = righ[v];
            if(lef[u] == -1) cout << "* ";
            else cout << lef[u] + 1<< " ";
            if(righ[v] == -1) cout << "*\n";
            else cout << righ[v] + 1 << "\n";
        }
        cout << "-\n";
    }
    return 0;
}