#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
vector <string> a;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n||m){
        if(cas != 1) cout << "\n";
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            for(int j=0; j<m; j++){
                if(a[i][j] == '.') a[i][j] = '0';
            }
        }
        cout << "Field #" << cas++ << ":\n";
        int tx, ty;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '*'){
                    for(int k=0; k<8; k++){
                        tx = i + dr[k];
                        ty = j + dc[k];
                        if(tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty] != '*'){
                            a[tx][ty]++;
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cout << a[i][j]; cout << "\n";
        }
    }
    return 0;
}