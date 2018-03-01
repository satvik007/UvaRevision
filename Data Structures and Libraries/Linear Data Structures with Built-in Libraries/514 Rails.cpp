#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
stack <int> s;
vi a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        a.resize(n);
        int big;
        while(true){
            while(!s.empty()) s.pop();
            big = n;
            cin >> a[0];
            if(!a[0]) break;
            for(int i=1; i<n; i++)
                cin >> a[i];
            reverse(a.begin(), a.end());
            for(int i=0; i<n; i++){
                s.push(a[i]);
                while(!s.empty() && s.top() == big){
                    s.pop(); big--;
                }
            }
            if(s.empty()) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n";
    }
    return 0;
}