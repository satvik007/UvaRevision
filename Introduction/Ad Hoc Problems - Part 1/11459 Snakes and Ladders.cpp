#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, a, b, c;
int nextv[105];
int tos[1000010];
int player[1000010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        int u, v;
        memset(nextv, -1, sizeof nextv);
        for(int i=0; i<b; i++){
            cin >> u >> v;
            nextv[u] = v;
        }
        for(int i=0; i<a; i++) player[i] = 1;
        for(int i=0; i<c; i++) cin >> tos[i];
        for(int i=0; i<c; i++){
            player[i%a] += tos[i];
            if(nextv[player[i%a]] != -1){
                player[i%a] = nextv[player[i%a]];
            }
            if(player[i%a] >= 100){
                player[i%a] = 100;
                break;
            }

        }
        for(int i=0; i<a; i++){
            cout << "Position of player " << i + 1 << " is " << player[i] << ".\n";
        }
    }
    return 0;
}