#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, visited[30], temp[30];
string active;
vi a[30];
map <char, int> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m){
        cin >> active;
        map1.clear(); memset(visited, 0, sizeof visited);
        memset(temp, 0, sizeof temp);
        int k = 0;
        for(auto el:active){
            visited[k] = 1, temp[k] = 1;
            map1[el] = k++;
        }
        for(int i=0; i<30; i++) a[i].clear();
        char u, v;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            if(!map1.count(u)) map1[u] = k++;
            if(!map1.count(v)) map1[v] = k++;
            a[map1[u]].push_back(map1[v]);
            a[map1[v]].push_back(map1[u]);
        }
        int ans = 0;
        for(int days = 1; ; days++){
            bool flag = false;
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    int cnt = 0;
                    for(auto j:a[i]){
                        if(visited[j]) cnt++;
                    }
                    if(cnt >= 3) temp[i] = 1, ans = days, flag = true;
                }
            }
            for(int i=0; i<n; i++) visited[i] = temp[i];
            if(!flag) break;
        }
        bool flag = true;
        for(int i=0; i<n; i++) if(!visited[i]) flag = false;
        if(!flag) cout << "THIS BRAIN NEVER WAKES UP\n";
        else cout << "WAKE UP IN, " << ans << ", YEARS\n";
    }
    return 0;
}