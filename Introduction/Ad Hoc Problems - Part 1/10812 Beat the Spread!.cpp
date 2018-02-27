#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll tc, n, m;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        if(n < m || ((n ^ m) & 1)) cout << "impossible\n";
        else {
            if((n+m)/2 <= (ll)INT_MAX)
                cout << (n + m) / 2 << " " << (n - m) /2 << "\n";
            else cout << "impossible\n";
        }
    }
    return 0;
}