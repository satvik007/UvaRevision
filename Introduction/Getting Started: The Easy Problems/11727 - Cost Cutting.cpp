#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, a[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    while(tc--){
        for(int i=0; i<3; i++) cin >> a[i];
        sort(a, a+3);
        cout << "Case " << cas++ << ": " << a[1] << "\n";
    }
    return 0;
}