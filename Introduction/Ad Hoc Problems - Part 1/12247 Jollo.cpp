#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int a[3], b[3], c[3];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1], a[0]){
        bool flag, son = false;
        int ans = 53;
        sort(a, a+3); sort(b, b+2);
        for(int i=1; i<=52; i++){
            if(find(b, b+2, i) == b+2 && find(a, a+3, i) == a+3){
                b[2] = i;
                copy(b, b+3, c);
                sort(c, c+3);
                if(a[2] > c[1] && a[1] > c[0]) continue;
                else {
                    ans = i; son = true; break;
                }
            }
        }
        if(son) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}