#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <string> a;
int n, m;
vector <vi> b;
int cd, x, y;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int newDir(){
    int tx = x + dr[(cd+1)%4];
    int ty = y + dc[(cd+1)%4];
    if(tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty] == '0'){
        cd = (cd + 1) % 4;
    }else{
        tx = x + dr[cd];
        ty = y + dc[cd];
        if(tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty] == '0');
        else cd = (cd + 3) % 4;
    }
}

int move(){
    int tx = x + dr[cd];
    int ty = y + dc[cd];
    if(tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty] == '0'){
        x = tx; y = ty;
        b[x][y]++;
        return 0;
    }else return 1;
}
int counter[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m, n||m){
        a.resize(n);
        b.resize(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            b[i].assign(m, 0);
        }
        cd = 1, x = n - 1, y = 0;
        bool flag = true;
        while(x != n-1 || y != 0 || flag) {
            flag = false;
            newDir();
            move();
        }
        memset(counter, 0, sizeof counter);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '0'){
                    counter[b[i][j]]++;
                }
            }
        }
        for(int i=0; i<5; i++) {
            cout << setw(3) << counter[i];
        }
        cout << "\n";
    }
    return 0;
}