#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int n, m;
queue <int> q1;
queue <int> q2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m; n *= 100;
        int u; string v;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            if(v == "left") q1.push(u);
            else q2.push(u);
        }
        int current = 0, cnt = 0;
        while(!q1.empty() || !q2.empty()){
            if(!current){
                int size = 0;
                while(!q1.empty()){
                    if(size + q1.front() > n) break;
                    size += q1.front(); q1.pop();
                }
                cnt++;
                current = 1;
            }else{
                int size = 0;
                while(!q2.empty()){
                    if(size + q2.front() > n) break;
                    size += q2.front(); q2.pop();
                }
                cnt++;
                current = 0;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}