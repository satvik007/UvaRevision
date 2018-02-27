#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

bool comp(char a, char b){
    if(std::tolower(a) == std::tolower(b)){
        return a < b;
    }
    return tolower(a) < tolower(b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    string a;
    while(tc--){
        cin >> a; sort(a.begin(), a.end(), comp);
        bool flag = true;
        while(flag){
            cout << a << "\n";
            flag = next_permutation(a.begin(), a.end(), comp);
        }
    }
    return 0;
}