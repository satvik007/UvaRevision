#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, s, q;
vector <queue<int>> a;
stack <int> b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        int u, v, cnt=0;
        while(!b.empty()) b.pop();
        cin >> n >> s >> q;
        a.clear(); a.resize(n);
        for(int i=0; i<n; i++){
            cin >> u;
            for(int j=0; j<u; j++) {
                cin >> v; v--;
                a[i].push(v);
                cnt++;
            }
        }
        int current = 0;
        int tim = 0;
        while(cnt){
            while(!b.empty()){
                if(b.top() == current) b.pop(), tim++, cnt--;
                else if(a[current].size() < q){
                    a[current].push(b.top()); b.pop();
                    tim++;
                }else
                    break;
            }
            while(!a[current].empty() && b.size() < s){
                b.push(a[current].front()); a[current].pop();
                tim++;
            }
            if(cnt) tim += 2, current = (current+1) % n;
        }
        cout << tim << "\n";
    }
    return 0;
}