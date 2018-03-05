#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

priority_queue <int> pq;
int n;
stack <int> s;
queue <int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n){
        int u, v;
        while(!s.empty()) s.pop();
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
        bool iss = true, isq = true, ispq = true;
        for(int i=0; i<n; i++){
            cin >> u >> v;
            if(u == 1){
                s.push(v); q.push(v); pq.push(v);
            }else{
                if(s.empty() || s.top() != v) iss = false;
                else s.pop();
                if(q.empty() || q.front() != v) isq = false;
                else q.pop();
                if(pq.empty() || pq.top() != v) ispq = false;
                else pq.pop();
            }
        }
        if(!iss && !isq && !ispq) cout << "impossible\n";
        else if(iss && !isq && !ispq) cout << "stack\n";
        else if(!iss && isq && !ispq) cout << "queue\n";
        else if(!iss && !isq && ispq) cout << "priority queue\n";
        else cout << "not sure\n";
    }
    return 0;
}