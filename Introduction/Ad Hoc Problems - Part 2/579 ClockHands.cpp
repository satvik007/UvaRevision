#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    double h, m;
    char null;
    cout << setprecision(3) << fixed;
    while(cin >> h >> null >> m, h||m){
        h *= 30;
        h += m / 2;
        m *= 6;
        double ans = min(abs(h-m) , 360 - abs(h-m));
        cout << ans << "\n";
    }
    return 0;
}