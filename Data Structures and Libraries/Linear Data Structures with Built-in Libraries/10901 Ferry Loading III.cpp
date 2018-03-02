#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int n, t, m;
queue <ii> q1, q2, q3, q4, temp;
int a[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        while(!q3.empty()) q3.pop();
        while(!q4.empty()) q4.pop();
        cin >> n >> t >> m;
        int u; string v;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            if(v == "left") q3.push({u, i});
            else q4.push({u, i});
        }
        int current = 0, tim = 0;
        while(!q3.empty() || !q2.empty() || !q4.empty() || !q1.empty()){
            while(!q3.empty() && q3.front().first <= tim) q1.push(q3.front()), q3.pop();
            while(!q4.empty() && q4.front().first <= tim) q2.push(q4.front()), q4.pop();
            if(!current){
                int cnt = 0;
                bool flag = true;
                while(!q1.empty() && cnt < n){
                    cnt++;
                    a[q1.front().second] = tim + t;
                    q1.pop();
                    flag = false;
                }
                if(!flag){
                    tim += t;
                    current = 1;
                }else if(!q2.empty()){
                    tim += t;
                    current = 1;
                }else{
                    tim++;
                }
            }else{
                int cnt = 0;
                bool flag = true;
                while(!q2.empty() && cnt < n){
                    cnt++;
                    a[q2.front().second] = tim + t;
                    q2.pop();
                    flag = false;
                }
                if(!flag){
                    tim += t;
                    current = 0;
                }else if(!q1.empty()){
                    tim += t;
                    current = 0;
                }else{
                    tim++;
                }
            }
        }
        for(int i=0; i<m; i++){
            cout << a[i] << "\n";
        }
        if(tc) cout << "\n";
    }
    return 0;
}