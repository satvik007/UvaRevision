#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

map <string, int> map1;
string a;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc; cin.ignore();
    cout << fixed << setprecision(4);
    while(tc--){
        map1.clear();
        cin.ignore(); n = 0;
        while(cin.peek() != '\n' && cin.peek() != EOF){
            getline(cin, a);
            if(map1.count(a)) map1[a]++;
            else map1[a] = 1;
            n++;
        }
        for(auto el:map1){
            cout << el.first << " " << (el.second*100.0/n) << "\n";
        }
        if(tc) cout << "\n";
    }
    return 0;
}