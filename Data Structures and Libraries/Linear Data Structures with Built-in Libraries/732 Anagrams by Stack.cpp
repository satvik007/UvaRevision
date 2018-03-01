#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a, b;
int n;

void solve(stack <char> s, int i, int j, string ans){
    if(j == n){
        cout << ans << "\n";
    }else if(i == n){
        if(!s.empty() && s.top() == b[j]){
            s.pop();
            if(ans.empty()) ans += 'o';
            else ans += " o";
            solve(s, i, j+1, ans);
        }
    }else {
        s.push(a[i]);
        solve(s, i + 1, j, ans.empty() ? ans + "i" : ans + " i");
        s.pop();
        if (!s.empty() && s.top() == b[j]) {
            s.pop();
            solve(s, i, j + 1, ans.empty() ? ans + "o" : ans + " o");
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> a >> b){
        n = (int)a.size();
        cout << "[\n";
        stack <char> s;
        if(a.size() != b.size()) ;
        else solve(s, 0, 0, "");
        cout << "]\n";
    }
    return 0;
}