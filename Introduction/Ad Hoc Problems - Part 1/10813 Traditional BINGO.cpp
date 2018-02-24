#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, a[10][10], b[90];
int c[10][10];

bool check(int i, int j){
    if(i+j == 4){
        if(c[4][0] && c[3][1] && c[1][3] && c[0][4]) return true;
    }
    if(i == j){
        if(c[0][0] && c[1][1] && c[3][3] && c[4][4]) return true;
    }
    bool flag1 = true, flag2 = true;
    for(int k=0; k<5; k++){
        if(!c[i][k]) flag1 = false;
        if(!c[k][j]) flag2 = false;
    }
    return flag1 || flag2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(i == 2 && j == 2) continue;
                cin >> a[i][j];
            }
        }
        a[2][2] = -1;
        memset(c, 0, sizeof c);
        c[2][2] = 1;
        for(int i=0; i<75; i++){
            cin >> b[i];
        }
        bool flag = false;
        for(int i=0; i<75 && !flag; i++){
            for(int j=0; j<5 && !flag; j++){
                for(int k=0; k<5; k++){
                    if(a[j][k] == b[i]) {
                        c[j][k] = 1;
                        flag = check(j, k);
                        if(flag) {
                            cout << "BINGO after " << i+1 << " numbers announced\n";
                        }
                    }
                }
            }
        }
    }
    return 0;
}