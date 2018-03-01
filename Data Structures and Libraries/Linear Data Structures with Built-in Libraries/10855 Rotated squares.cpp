#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
vector <string> a, b[4];
int counter[4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m, n||m){
        a.resize(n);
        memset(counter, 0, sizeof counter);
        for(int i=0; i<4; i++)
            b[i].resize(m);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int j=0; j<m; j++) cin >> b[0][j];
        for(int i=0; i<m; i++){
            b[1][i].resize(m);b[2][i].resize(m);b[3][i].resize(m);
            for(int j=0; j<m; j++){
                b[1][i][j] = b[0][m-j-1][i];
                b[2][i][j] = b[0][m-i-1][m-j-1];
                b[3][i][j] = b[0][j][m-i-1];
            }
        }
        bool flag[4];
        for(int i=0; i<=n-m; i++){
            for(int j=0; j<=n-m; j++){
                memset(flag, true, sizeof flag);
                for(int v=0; v<4; v++){
                    for(int x=0; x<m && flag[v]; x++){
                        for(int y=0; y<m; y++){
                            if(a[i+x][j+y] != b[v][x][y]){
                                flag[v] = false;
                                break;
                            }
                        }
                    }
                    if(flag[v]) counter[v]++;
                }
            }
        }
        for(int i=0; i<4; i++) {
            if(!i) cout << counter[i];
            else cout << " " << counter[i];
        }
        cout << "\n";
    }
    return 0;
}