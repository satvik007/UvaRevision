#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 1000001

int n, m;
int a[maxn+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v, w;
    while(cin >> n >> m, n||m){
        memset(a, 0, sizeof a);
        bool flag = true;
        for(int i=0; i<n; i++){
            cin >> u >> v;
            for(; u<v; u++){
                if(a[u])
                    flag = false;
                a[u] = 1;
            }
        }
        for(int i=0; i<m; i++){
            cin >> u >> v >> w;
            for(int j=u; j<maxn; j+=w){
                for(int k=j; k<j+v-u && k < maxn; k++){
                    if(a[k])
                        flag = false;
                    a[k] = 1;
                }
            }
        }
        if(flag) cout << "NO CONFLICT\n";
        else cout << "CONFLICT\n";
    }
    return 0;
}