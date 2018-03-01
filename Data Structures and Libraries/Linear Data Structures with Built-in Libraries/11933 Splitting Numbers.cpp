#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 1000001

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        int a = 0, b = 0;
        int cnt = 0;
        for(int i=0; i<32; i++){
            if(n & (1<<i)){
                if(cnt % 2) a |= (n & (1<<i));
                else b |= (n & (1<<i));
                cnt++;
            }
        }
        cout << b << " " << a << "\n";
    }
    return 0;
}