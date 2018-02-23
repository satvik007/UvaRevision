#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a;
int b[10][10];
int c[10][10];

void knight(int u, int v){
    int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int i=0; i<8; i++){
        int tx = u + dr[i];
        int ty = v + dc[i];
        if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8) b[tx][ty] = 1;
    }
}
void rook(int u, int v){
    for(int i=u+1; i<8; i++){
        if(c[i][v]) break;
        b[i][v] = 1;
    }
    for(int i=u-1; i>=0; i--){
        if(c[i][v]) break;
        b[i][v] = 1;
    }
    for(int i=v+1; i<8; i++){
        if(c[u][i]) break;
        b[u][i] = 1;
    }
    for(int i=v-1; i>=0; i--){
        if(c[u][i]) break;
        b[u][i] = 1;
    }
}
void king(int u, int v){
    int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int k=0; k<8; k++){
        int tx = u + dr[k];
        int ty = v + dc[k];
        if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8) b[tx][ty] = 1;
    }
}
void bishop(int u, int v){
    for(int i=1; i<8; i++){
        int tx = u - i;
        int ty = v + i;
        if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8 && !c[tx][ty]) b[tx][ty] = 1;
        else break;
    }
    for(int i=1; i<8; i++){
        int tx = u + i;
        int ty = v + i;
        if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8 && !c[tx][ty]) b[tx][ty] = 1;
        else break;
    }
    for(int i=1; i<8; i++){
        int tx = u + i;
        int ty = v - i;
        if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8 && !c[tx][ty]) b[tx][ty] = 1;
        else break;
    }
    for(int i=1; i<8; i++){
        int tx = u - i;
        int ty = v - i;
        if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8 && !c[tx][ty]) b[tx][ty] = 1;
        else break;
    }
}
void queen(int u, int v){
    rook(u, v);
    bishop(u, v);
}
void pawnup(int u, int v){
    if(u-1 >= 0){
        if(v - 1 >= 0) b[u-1][v-1] = 1;
        if(v + 1 < 8) b[u-1][v+1] = 1;
    }
}
void pawndown(int u, int v){
    if(u+1 < 8){
        if(v - 1 >= 0) b[u+1][v-1] = 1;
        if(v + 1 < 8) b[u+1][v+1] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> a){
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        int k = 0, j = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] == '/') k++, j = 0;
            else if(a[i] >= '1' && a[i] <= '8'){
                j += (a[i] - '0');
            }else{
                b[k][j] = 1; c[k][j] = 1; j++;
            }
        }
        k = 0; j = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] == '/') k++, j = 0;
            else if(a[i] >= '1' && a[i] <= '8'){
                j += (a[i] - '0');
            }else{
                if(a[i] == 'n' || a[i] == 'N') knight(k, j);
                else if(a[i] == 'r' || a[i] == 'R') rook(k, j);
                else if(a[i] == 'K' || a[i] == 'k') king(k, j);
                else if(a[i] == 'q' || a[i] == 'Q') queen(k, j);
                else if(a[i] == 'b' || a[i] == 'B') bishop(k, j);
                else if(a[i] == 'p') pawndown(k, j);
                else if(a[i] == 'P') pawnup(k, j);
                j++;
            }
        }
        int cnt = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(!b[i][j]) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}