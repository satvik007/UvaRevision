#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m, n||m){
        ll v = (ll)sqrt(m);
        if(!(v%2)) v--;
        ll current = v*v, x = n/2 + v/2;
        ll y = x;
        if(current == m){
            cout << "Line = " << x+1 << ", column = " << y+1 << ".\n";
            continue;
        }
        x++;
        if(current + v + 1 >= m){
            y -= (m - current - 1);
        }else{
            y -= v; current += (v+1);
            if(current + v + 1 >= m){
                x -= (m - current);
            }else{
                x -= (v+1); current += (v+1);
                if(current + v + 1 >= m){
                    y += (m - current);
                }else{
                    y += (v+1); current += (v+1);
                    x += (m - current);
                }
            }
        }
        cout << "Line = " << x+1 << ", column = " << y+1 << ".\n";
    }
    return 0;
}