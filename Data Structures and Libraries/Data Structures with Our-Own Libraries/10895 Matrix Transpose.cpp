#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
int a[1000][1000];
int line[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m){
        int u, v;
        memset(a, 0, sizeof a);
        for(int i=0; i<n; i++) {
            cin >> u;
            for(int j=0; j<u; j++){
                cin >> line[j];
            }
            for(int j=0; j<u; j++){
                cin >> a[i][line[j]-1];
            }
        }
        cout << m << " " << n << "\n";
        for(int i=0; i<m; i++){
            int cnt = 0;
            for(int j=0; j<n; j++) if(a[j][i]) cnt++;
            cout << cnt;
            for(int j=0; j<n; j++) if(a[j][i]) cout << " " << j + 1;
            cout << "\n";
            cnt = 0;
            for(int j=0; j<n; j++){
                if(a[j][i]){
                    if(cnt) cout << " ";
                    cnt++;
                    cout << a[j][i];
                }
            }
            cout << "\n";
        }
    }
    return 0;
}