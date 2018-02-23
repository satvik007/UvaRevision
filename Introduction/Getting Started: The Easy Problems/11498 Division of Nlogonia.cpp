#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> tc, tc){
        cin >> n >> m;
        int u, v;
        while(tc--){
            cin >> u >> v;
            if(u < n && m < v){
                cout << "NO\n";
            }else if(u < n && m > v){
                cout << "SO\n";
            }else if(u > n && m < v){
                cout << "NE\n";
            }else if(u > n && m > v){
                cout << "SE\n";
            }else if(u == n || m == v){
                cout << "divisa\n";
            }
        }
    }
    return 0;
}