#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 1000001

string s;
list <char> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin.peek() != EOF){
        getline(cin, s);
        a.clear();
        auto iter = a.begin();
        for(auto el:s){
            if(el == '[') iter = a.begin();
            else if(el == ']') iter = a.end();
            else{
                iter = a.insert(iter, el); iter++;
            }
        }
        for(auto el:a) cout << el; cout << "\n";
    }
    return 0;
}