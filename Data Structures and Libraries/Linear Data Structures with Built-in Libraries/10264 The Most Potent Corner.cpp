#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int n;
vi a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n){
        a.resize(1 << n); b.resize(a.size());
        for(int i=0; i<a.size(); i++) cin >> a[i];
        for(int i=0; i<(1<<n); i++){
            int sum = 0;
            for(int j=0; (i ^ (1<<j)) < a.size(); j++){
                sum += a[(i ^ (1<<j))];
            }
            b[i] = sum;
        }
        int max1 = -1;
        for(int i=0; i<a.size(); i++){
            for(int j=0; (i ^ (1<<j)) < a.size(); j++){
                max1 = max(max1, (int)b[i] + (int)b[i^(1<<j)]);
            }
        }
        cout << max1 << "\n";
    }
    return 0;
}
