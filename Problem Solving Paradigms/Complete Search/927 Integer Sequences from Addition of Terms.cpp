#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll n, d, k;
ll a[30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n+1; i++) cin >> a[i];
        cin >> d >> k;
        int v = 1;
        for(int i=1; ;){
            if(i + d*v > k){
                break;
            }else{
                i += d*v;
                v++;
            }
        }
        ll res = 0, mul = 1;
        for(int i=n; i>=0; i--){
            res = res * v + a[i];
        }
        cout << res << "\n";
    }
    return 0;
}