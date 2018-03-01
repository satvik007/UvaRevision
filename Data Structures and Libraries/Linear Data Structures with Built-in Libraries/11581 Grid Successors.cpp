#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vector <string> a(3);
vector <vi> b(3), c(3);

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int solve(){
    c = b;
    int tx, ty;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int sum = 0;
            for(int k=0; k<4; k++){
                tx = i + dr[k];
                ty = j + dc[k];
                if(tx >= 0 && ty >= 0 && tx < 3 && ty < 3){
                    sum += c[tx][ty];
                }
            }
            b[i][j] = sum % 2;
        }
    }
    if(b == c) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        for(int i=0; i<3; i++) cin >> a[i];
        for(int i=0; i<3; i++){
            b[i].resize(3);
            for(int j=0; j<3; j++) b[i][j] = a[i][j]-'0';
        }
        int index = -1;
        while(solve()){
            index++;
        }
        cout << index << "\n";
    }
    return 0;
}