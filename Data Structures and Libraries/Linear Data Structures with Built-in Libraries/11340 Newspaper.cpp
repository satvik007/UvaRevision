#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

map <char, int> map1;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    cout << setprecision(2) << fixed;
    while(tc--){
        cin >> n;
        map1.clear();
        char curr;
        int u, v;
        for(int i=0; i<n; i++){
            cin >> curr >> u;
            map1[curr] = u;
        }
        cin >> n; cin.ignore();
        double money = 0;
        string line;
        for(int i=0; i<n; i++){
            getline(cin, line);
            for(auto el:line){
                if(map1.count(el)) money += map1[el];
            }
        }
        cout << (money/100) << "$\n";
    }
    return 0;
}