#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
priority_queue <int, vi, greater <int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        int u, v;
        for(int i=0; i<n; i++){
            cin >> u;
            pq.push(u);
        }
        int cnt = 0;
        while(pq.size() > 1){
            u = pq.top(); pq.pop();
            v = pq.top(); pq.pop();
            cnt += (u + v);
            pq.push(u+v);
        }
        pq.pop();
        cout << cnt << "\n";
    }
    return 0;
}