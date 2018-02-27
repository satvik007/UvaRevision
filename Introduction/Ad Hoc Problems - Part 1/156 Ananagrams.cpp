#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

map <string, string> map1;
string a, b;
vector <string> d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int k = 0;
    while(cin >> a, a != "#") {
        b = a;
        for (int i = 0; i < b.size(); i++) b[i] = tolower(b[i]);
        sort(b.begin(), b.end());
        if (map1.count(b)) map1[b] = "#";
        else map1[b] = a;
    }
    for(auto el:map1) if(el.second != "#") d.push_back(el.second);
    sort(d.begin(), d.end());
    for(auto el:d) cout << el << "\n";
    return 0;
}