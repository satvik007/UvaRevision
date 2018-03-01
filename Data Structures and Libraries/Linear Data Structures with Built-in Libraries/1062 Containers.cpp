#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

stack <char> b[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a;
    int cas = 1;
    while(cin >> a, a != "end"){
        cout << "Case " << cas++ << ": ";
        for(int i=0; i<26; i++){
            while(!b[i].empty()) b[i].pop();
        }
        for(auto el:a){
            for(int j=0; j<26; j++){
                if(b[j].empty() || b[j].top() >= el){
                    b[j].push(el);
                    break;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(!b[i].empty()) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}