#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
string a, b, c;
set <char> visited;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n+1){
        visited.clear();
        cin >> a >> b;
        int strokes = 0;
        for(auto el:b){
            if(visited.count(el)) continue;
            if(a.find(el) != string::npos){
                for(int i=0; i<a.size(); i++) {
                    if(a[i] == el) a[i] = '0';
                }
            }else strokes++;
            visited.insert(el);
            bool flag = true;
            for(auto v:a){
                if(v != '0') flag = false;
            }
            if(flag) break;
        }
        bool flag = true;
        cout << "Round " << n << "\n";
        for(auto el:a) if(el != '0') flag = false;
        if(strokes >= 7) cout << "You lose.\n";
        else if(flag) cout << "You win.\n";
        else cout << "You chickened out.\n";
    }
    return 0;
}