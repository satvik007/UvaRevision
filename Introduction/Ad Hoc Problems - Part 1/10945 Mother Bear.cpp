#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin.peek() != EOF){
        getline(cin, b);
        if(b == "DONE") break;
        a.clear();
        for(int i=0; i<b.size(); i++){
            if(b[i] >= 'a' && b[i] <= 'z' || b[i] >= 'A' && b[i] <= 'Z'){
                a += tolower(b[i]);
            }
        }
        bool flag = true;
        for(int i=0; i<(a.size()+1)/2; i++){
            if(a[i] != a[a.size()-i-1]) flag = false;
        }
        if(flag) cout << "You won't be eaten!\n";
        else cout << "Uh oh..\n";
    }
    return 0;
}