#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

// Rocks always defeat
// Scissors, Scissors always defeat Papers, and Papers always defeat Rocks.

int tc, n, m, k;
vector <string> a, b;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void apply(){
    b = a;
    int tx, ty;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<4; k++){
                tx = i + dr[k];
                ty = j + dc[k];
                if(tx >= 0 && ty >= 0 && tx < n && ty < m) {
                    if(b[i][j] == 'S' && b[tx][ty] == 'P')
                        a[tx][ty] = 'S';
                    else if(b[i][j] == 'R' && b[tx][ty] == 'S')
                        a[tx][ty] = 'R';
                    else if(b[i][j] == 'P' && b[tx][ty] == 'R')
                        a[tx][ty] = 'P';
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        cin >> n >> m >> k;
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        while(k--) apply();
        for(int i=0; i<n; i++){
            cout << a[i] << "\n";
        }
        if(tc) cout << "\n";
    }
    return 0;
}