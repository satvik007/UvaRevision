#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, u, sum;

void solve(){
    if(abs(sum) % n == 0){
        sum /= n;
        if(sum < 0) cout << "- ";
        cout << abs(sum) << "\n";
    }else{
        int sign = (sum < 0);
        sum = abs(sum);
        int avg = sum / n;
        int gcd = __gcd(n, sum);
        sum /= gcd; n /= gcd;
        int offset = (sign ? 2 : 0);
        offset += (avg == 0) ? 0 : to_string(avg).size();
        int len1 = to_string(sum % n).size();
        int len2 = to_string(n).size();
        for(int i=0; i<offset + len2 - len1; i++) cout << " ";
        cout << (sum % n) << "\n";
        if(sign) cout << "- ";
        if(avg) cout << avg;
        for(int i=0; i<len2; i++) cout << "-"; cout << "\n";
        for(int i=0; i<offset; i++) cout << " ";
        cout << n << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n, n){
        cout << "Case " << cas++ << ":\n";
        sum = 0;
        for(int i=0; i<n; i++){
            cin >> u; sum += u;
        }
        solve();
    }
    return 0;
}