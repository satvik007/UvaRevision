#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(getline(cin, a), a != "#"){
        if(next_permutation(a.begin(), a.end())){
            cout << a << "\n";
        }else{
            cout << "No Successor\n";
        }
    }
    return 0;
}